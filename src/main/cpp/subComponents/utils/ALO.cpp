// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subComponents/utils/ALO.h"

#define SHOOTER_REGRESSION(x) 2276.083 - (-84.4069/-0.05685471)*(1 - std::exp((0.05685471*x)))
#define SPEED_CURVE(x) 0.6914895 + (0.08625241 - 0.6914895) / (1 + pow((inputSpeed / 0.3315671), 11.36875))

ALO::ALO() {
    distanceMap[9.676] = 3365.0;
    distanceMap[13.0545] = 3910;
    distanceMap[23.141] = 6325;
}

double ALO::getRPMFromDistance(double distance) {
    

    for(distanceMapItr = distanceMap.begin(); distanceMapItr != distanceMap.end(); distanceMapItr++) {
        if(abs(distanceMapItr->first - distance) > 0.75 ) {
            return distanceMapItr->second;
        }
    }
    double calcualtedRPM = SHOOTER_REGRESSION(distance);
    return calcualtedRPM;
}

double ALO::curveSpeed(double inputSpeed) {
    return SPEED_CURVE(inputSpeed);
}
double ALO::maxFromVector(std::vector<double> arr) {
    double max = *max_element(arr.begin(), arr.end());
    return max;
}
std::vector<double> ALO::pushToVector(std::vector<double> arr, double v1, double v2, double v3, double v4) {
    arr.push_back(v1);
    arr.push_back(v2);
    arr.push_back(v3);
    arr.push_back(v4);
    return arr;
}