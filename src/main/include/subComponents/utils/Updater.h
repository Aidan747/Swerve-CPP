// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef Updater_H
#define Updater_H

#include <thread>
#include <cmath>
#include <memory>
#include <vector>
#include <list>
#include <any>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <RobotContainer.h>


using std::vector;

class Updater {
 public:
  Updater();
  void initializeSystemUpdates();
  void initalizeSmartDashboardUpdates();
};

#endif