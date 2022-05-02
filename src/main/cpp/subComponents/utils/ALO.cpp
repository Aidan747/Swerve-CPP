// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subComponents/utils/ALO.h"

#define REGRESSION(x) 2276.083 - (-84.4069/-0.05685471)*(1 - std::exp((0.05685471*x)))

ALO::ALO() = default;

double ALO::getRPMFromDistance(double distance) {
    for(distanceMapItr = distanceMap.begin(); distanceMapItr != distanceMap.end(); distanceMapItr++) {
        if(abs(distanceMapItr->first - distance) > 0.75 ) {
            return distanceMapItr->second;
        }
    }
    double calcualtedRPM = REGRESSION(distance);
    return calcualtedRPM; 
}

double ALO::curveSpeed(double inputSpeed) {
    return 0.6914895 + (0.08625241 - 0.6914895) / (1 + pow((inputSpeed / 0.3315671), 11.36875));
}