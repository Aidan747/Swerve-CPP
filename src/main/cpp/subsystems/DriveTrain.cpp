// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() = default;
DriveTrain::DriveTrain(SwerveModule frontRightModule, SwerveModule frontLeftModule, SwerveModule backRightModule, SwerveModule backLeftModule) {
    this->frontRightModule = frontRightModule;
    this->frontLeftModule = frontLeftModule;
    this->backRightModule = backRightModule;
    this->backLeftModule = backLeftModule;
}
void DriveTrain::setAllMotors(double setpoint) {
    frontRightModule.setSpeed(setpoint);
}

void DriveTrain::drive() {
    double speed = RobotContainer::driverStick->GetRawAxis(1);
    frontRightModule.setSpeed(speed, true);
    frontLeftModule.setSpeed(speed, true);
    backRightModule.setSpeed(speed, true);
    backLeftModule.setSpeed(speed, true);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

