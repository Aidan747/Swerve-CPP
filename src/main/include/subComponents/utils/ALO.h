// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ALO_H
#define ALO_H

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <units/velocity.h>
#include <Constants.h>
#include <units/angular_velocity.h>

// Arithmatic Logic Operator

class ALO {
 public:
  ALO();

  double curveSpeed(double joystickInput);
  double getRPMFromDistance(double distanceKey);
  void initialize();
  units::meters_per_second_t joystickToMS(double joystickInput);
  std::vector<double> pushToVector(std::vector<double> arr, double v1, double v2, double v3, double v4);
  double maxFromVector(std::vector<double> arr);
  double convertToAbsolute(double encoderValue);
  units::radians_per_second_t joyToRad(double joystickInput);

 private:
  double differenceFromKey;
  std::map<double, double> distanceMap;
  std::map<double, double>::iterator distanceMapItr;

};

#endif