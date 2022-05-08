

#include "subComponents/SwerveModule.h"


#define wheelDiameter 
#define kBrushed rev::CANSparkMaxLowLevel::MotorType::kBrushed
#define kBrushless rev::CANSparkMaxLowLevel::MotorType::kBrushless

SwerveModule::SwerveModule() = default;

SwerveModule::SwerveModule(int driveMotorID, int turnMotorID) {
    this->driveMotorID = driveMotorID;
    this->turnMotorID = turnMotorID;
    this->turnMotor = new CANSparkMax(turnMotorID, kBrushed);
    this->driveMotor = new CANSparkMax(driveMotorID, kBrushed);
    //needs to be absolute encoder -- fix when we finish drivetrain
    this->moduleEncoder = new Encoder(1,2);

    
}
// double SwerveModule::azimuthError(double target) {
//     double encoder = moduleEncoder->Get();
//     double azimuthAngle = remainder(moduleEncoder->Get(), target)
// }
void SwerveModule::setSpeed(double input, bool isCurved) {
    double curvedSpeed = 0.6914895 + (0.08625241 - 0.6914895) / (1 + pow((input / 0.3315671),11.36875));
    if(isCurved) {
        driveMotor->Set(curvedSpeed);
    }
    else {
        driveMotor->Set(input);
    }
}
double SwerveModule::getModuleRotation() {
    return moduleEncoder->Get();
}
double SwerveModule::getSetpoint() {
    return driveMotor->Get();
}
double SwerveModule::getVelocity(string unit) {
    if(unit == "rpm") {
        return (moduleEncoder->GetRate() * 600) / 2048;
    }
    else if(unit ==  "m/s") {
        return 1;
    }
    else {
        return driveMotor->Get();
    }
}