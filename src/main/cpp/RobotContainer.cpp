// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"


/* CHANGE INITIALIZATION LIST LATER - FINAL PARAMS ARE HARDWARE SPECIFIC */

RobotContainer::RobotContainer() :
  frontRightModule(Constants::DriveTrainConstants::fowardRightDriveMotorID, Constants::DriveTrainConstants::fowardRightTurnMotorID, false, false, 1,0,false),
  frontLeftModule(Constants::DriveTrainConstants::fowardLeftDriveMotorID, Constants::DriveTrainConstants::fowardLeftTurnMotorID, false, false, 1,0,false),
  backRightModule(Constants::DriveTrainConstants::backRightDriveMotorID, Constants::DriveTrainConstants::backRightTurnMotorID, false, false, 1,0,false),             
  backLeftModule(Constants::DriveTrainConstants::backLeftDriveMotorID, Constants::DriveTrainConstants::backLeftTurnMotorID, false, false, 1,0,false),
  driveTrainSub(frontRightModule, frontLeftModule, backRightModule, backLeftModule),
  m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  
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
