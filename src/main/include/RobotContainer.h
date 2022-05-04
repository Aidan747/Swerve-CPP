// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef RobotContainer_H
#define RobotContainer_H

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"


#include "commands/ExampleCommand.h"

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveTrain.h"

#include "subComponents/SwerveModule.h"
#include "subComponents/utils/ALO.h"


using frc::Joystick;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  ~RobotContainer();

  frc2::Command* GetAutonomousCommand();

  inline static ALO* ALO = new ALO();
  inline static Joystick* driverStick = new Joystick(1);

  void ConfigureButtonBindings();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  DriveTrain driveTrainSub;
  SwerveModule frontRightModule;
  SwerveModule frontLeftModule;
  SwerveModule backRightModule;
  SwerveModule backLeftModule;




};
namespace limelight {
  double xOffset;
  double yOffset;
  bool hasTarget;
}

#endif