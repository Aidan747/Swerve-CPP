// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ALO_H
#define ALO_H

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

// Arithmatic Logic Operator

class ALO {
 public:
  ALO();

  double curveSpeed(double joystickInput);
  double getRPMFromDistance(double distanceKey);
  void initialize();
  std::vector<double> pushToVector(std::vector<double> arr, double v1, double v2, double v3, double v4);
  double maxFromVector(std::vector<double> arr);
  double convertToAbsolute(double encoderValue);

 private:
  double differenceFromKey;
  std::map<double, double> distanceMap;
  std::map<double, double>::iterator distanceMapItr;

};

#endif