

#include "subComponents/SwerveModule.h"


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

    this->PIDCtrl = new frc::PIDController(0.02,0,0);
    PIDCtrl->EnableContinuousInput(-M_PI,M_PI);
}
double SwerveModule::getAbsEncoderRadians() {
    /* 5 is the total voltage being supplied to the encoder */
    double angle = moduleEncoder->GetVoltage() / 5;
    angle *= (M_PI * 2);
    angle -= absEncoderOffset;
    return angle * (absEncoderReversed ? -1 : 1);
}
double SwerveModule::getDriveMotorPosition() {
    return driveMotor->GetEncoder().GetPosition();
}
double SwerveModule::getTurningMotorPostion() {
    return turnMotor->GetEncoder().GetPosition();
}
double SwerveModule::getTurningMotorVelocity() {
    return turnMotor->GetEncoder().GetVelocity();
}
double SwerveModule::getDriveMotorVelocity() {
    return driveMotor->GetEncoder().GetVelocity();
}


