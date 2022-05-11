// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveTrain.h"
#include <frc/Joystick.h>
#include <units/velocity.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Drive : public frc2::CommandHelper<frc2::CommandBase, Drive> {
  DriveTrain driveTrainSub;
  double speed;
  units::meters_per_second_t xInput;
  units::meters_per_second_t yInput;
  units::radians_per_second_t zInput;
 public:
  Drive() = default;
  Drive(DriveTrain driveTrainSub);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
