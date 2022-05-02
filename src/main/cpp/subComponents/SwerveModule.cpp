

#include "subComponents/SwerveModule.h"

SwerveModule::SwerveModule() = default;

SwerveModule::SwerveModule(int driveMotorID, int turnMotorID) {
    this->driveMotorID = driveMotorID;
    this->turnMotorID = turnMotorID;
    WPI_TalonFX* driveMotor = new WPI_TalonFX(getIDs("driveMotor"));
    WPI_TalonFX* turnMotor = new WPI_TalonFX(getIDs("turnMotor"));
    this->driveMotor = driveMotor;
    this->turnMotor = turnMotor;
}

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
    return turnMotor->GetSelectedSensorPosition();
}
double SwerveModule::getSetpoint() {
    return driveMotor->GetMotorOutputPercent();
}
double SwerveModule::getVelocity(string unit) {
    if(unit == "rpm") {
        return (driveMotor->GetSelectedSensorVelocity() * 600) / 2048;
    }
    else if(unit ==  "m/s") {
        return 1;
    }
    else {
        return driveMotor->GetSelectedSensorVelocity();
    }
}