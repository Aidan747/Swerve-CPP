// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"

RobotContainer::RobotContainer() :
  frontRightModule(Constants::DriveTrainConstants::fowardRightDriveMotorID, Constants::DriveTrainConstants::fowardRightTurnMotorID),
  frontLeftModule(Constants::DriveTrainConstants::fowardLeftDriveMotorID, Constants::DriveTrainConstants::fowardLeftTurnMotorID),
  backRightModule(Constants::DriveTrainConstants::backRightDriveMotorID, Constants::DriveTrainConstants::backRightTurnMotorID),             
  backLeftModule(Constants::DriveTrainConstants::backLeftDriveMotorID, Constants::DriveTrainConstants::backLeftTurnMotorID),
  m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  DriveTrain driveTrainSub(frontRightModule, frontLeftModule, backRightModule, backLeftModule);
  // Configure the button bindings
  ConfigureButtonBindings();
}
RobotContainer::~RobotContainer() {
  delete driverStick;
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
