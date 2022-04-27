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

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

