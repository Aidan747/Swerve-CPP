// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"
#include "RobotContainer.h"

Drive::Drive(DriveTrain driveTrainSub) {
  this->driveTrainSub = driveTrainSub;
  AddRequirements(&driveTrainSub);
}

// Called when the command is initially scheduled.
void Drive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
  units::meters_per_second_t xInput = RobotContainer::alo->joystickToMS(RobotContainer::driverStick->GetRawAxis(0));
  units::meters_per_second_t yInput = RobotContainer::alo->joystickToMS(RobotContainer::driverStick->GetRawAxis(1));
  units::radians_per_second_t zInput = RobotContainer::alo->joyToRad(RobotContainer::driverStick->GetRawAxis(2));
  // add speed curve from ALO later
  frc::ChassisSpeeds speeds{xInput, yInput, zInput};
  auto [frontRight, frontLeft, backRight, backLeft] = driveTrainSub.kinematics.ToSwerveModuleStates(speeds);
  frc::SwerveModuleState states[4] = {frontRight, frontLeft, backRight, backLeft};
  driveTrainSub.setModuleStates(states);
}

// Called once the command ends or is interrupted.
void Drive::End(bool interrupted) {}

// Returns true when the command should end.
bool Drive::IsFinished() {

  return false;
}
