// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subComponents/ALO.h"

ALO::ALO() {
    std::thread t0(initialize);
}

void ALO::initialize() {
}

double ALO::getRPMFromDistance(double distance) {
    for(distanceMapItr = distanceMap.begin(); distanceMapItr != distanceMap.end(); distanceMapItr++) {
        if(distance = distanceMapItr->second || differenceFromKey < 0.5) {
            
        }
    }
    
}