// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ALO_H
#define ALO_H

#include <cmath>
#include <map>


// Arithmatic Logic Operator

class ALO {
 public:
  ALO();

  double curveSpeed(double joystickInput);
  double getRPMFromDistance(double distanceKey);
  void initialize();

 private:
  double differenceFromKey;
  std::map<double, double> distanceMap;
  std::map<double, double>::iterator distanceMapItr;

  
  
};

#endif