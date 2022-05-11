

#include "subComponents/SwerveModule.h"
#include <frc/MathUtil.h>


#define wheelDiameter 15 // inches?
#define kBrushed rev::CANSparkMaxLowLevel::MotorType::kBrushed
#define kBrushless rev::CANSparkMaxLowLevel::MotorType::kBrushless

SwerveModule::SwerveModule() = default;

SwerveModule::SwerveModule(int driveMotorID, int turnMotorID, bool driveMotorReversed, bool turnMotorReversed, int encoderID, double absEncoderOffset, bool absEncoderReversed) {
    this->absEncoderOffset = absEncoderOffset;
    this->absEncoderReversed = absEncoderReversed;
    //needs to be absolute encoder -- fix when we finish drivetrain
    this->moduleEncoder = new AnalogInput(encoderID);
    
    this->turnMotor = new CANSparkMax(turnMotorID, kBrushed);
    this->driveMotor = new CANSparkMax(driveMotorID, kBrushed);
    driveMotor->SetInverted(driveMotorReversed);
    turnMotor->SetInverted(turnMotorReversed);
    
    /* set encoder constants here:
       if we could use falcons instead of sims it makes velocity calcs
       much easier. if we cant make sure to add velcity encoders on CIMS, 
       and define them here, along with the motor.setPositionConversionFactor(<conversion factor>)
       & do the same for velocity. */

    this->PIDCtrl = new frc::PIDController(0.02, 0, 0);
    PIDCtrl->EnableContinuousInput(-M_PI,M_PI);

    resetEncoders();
}
double SwerveModule::getAbsEncoderRadians() {
    /* 5 is the total voltage being supplied to the encoder */
    /* fix when we have final encoder */
    double angle = moduleEncoder->GetVoltage() / 5;
    angle *= (M_PI * 2);
    angle -= absEncoderOffset;
    return angle * (absEncoderReversed ? -1 : 1);
}
double SwerveModule::getDriveMotorPosition() {
    return driveMotor->GetEncoder().GetPosition();
}
units::radian_t SwerveModule::getTurningMotorPostion() {
    units::radian_t out{turnMotor->GetEncoder().GetPosition()};
    return out;
}
double SwerveModule::getRawTurningMotorPosition() {
    return turnMotor->GetEncoder().GetPosition();
}
double SwerveModule::getTurningMotorVelocity() {
    return turnMotor->GetEncoder().GetVelocity();
}
units::velocity::meters_per_second_t SwerveModule::getDriveMotorVelocity() {
    units::velocity::meters_per_second_t out{driveMotor->GetEncoder().GetVelocity()}; 
    return out;
}
void SwerveModule::resetEncoders() {
    driveMotor->GetEncoder().SetPosition(0);
    turnMotor->GetEncoder().SetPosition(getAbsEncoderRadians());
}
frc::SwerveModuleState SwerveModule::getState() {
    frc::SwerveModuleState out;
    out.angle = frc::Rotation2d(getTurningMotorPostion());
    out.speed = getDriveMotorVelocity();
}
void SwerveModule::stop() {
    driveMotor->Set(0);
    turnMotor->Set(0);

}
void SwerveModule::setState(frc::SwerveModuleState state) {
    if(abs(state.speed() < 0.001)) {
        stop();
        return;
    }
    state = state.Optimize(state, getState().angle);

    //typecasting for PID Controller
    double motorSpeed = (double) (state.speed / Constants::ModuleConstants::maxSpeed);
    double radianRaw = (double) getTurningMotorPostion();
    double setpointRaw = (double) state.angle.Radians();
    driveMotor->Set(motorSpeed);
    turnMotor->Set(PIDCtrl->Calculate(radianRaw, setpointRaw));
}

