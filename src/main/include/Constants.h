// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef Constants_H
#define Constants_H

#include <cmath>
#include <units/velocity.h>
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace Constants
{
    namespace Controllers 
    {
        int driverControllerID = 1;
    }
    namespace DriveTrainConstants
    {
        constexpr units::meters_per_second_t robotMaxSpeed{5};
        constexpr int fowardRightDriveMotorID = 1;
        constexpr int fowardRightTurnMotorID = 2;
        constexpr int backRightDriveMotorID = 3;
        constexpr int backRightTurnMotorID = 4;
        constexpr int fowardLeftDriveMotorID = 5;
        constexpr int fowardLeftTurnMotorID = 6;
        constexpr int backLeftDriveMotorID = 7;
        constexpr int backLeftTurnMotorID = 8;
    }
    namespace ModuleConstants {
        constexpr double wheelDiameterMeters = 0.1;
        constexpr double wheelDiameterInches = 5; /*?*/
        constexpr double turnMotorGearing = 1/18;
        constexpr double driveMotorGearing = 1/5.8462;
        constexpr double driveEncoderRotToMeter = driveMotorGearing * M_PI * wheelDiameterMeters;
        constexpr double turningEncoderRotToRadians = turnMotorGearing * M_PI * 2;
        constexpr double maxSpeed = 8.2;
    }
}

#endif