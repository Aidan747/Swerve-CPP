// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef Constants_H
#define Constants_H

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
        int fowardRightDriveMotorID = 1;
        int fowardRightTurnMotorID = 2;
        int backRightDriveMotorID = 3;
        int backRightTurnMotorID = 4;
        int fowardLeftDriveMotorID = 5;
        int fowardLeftTurnMotorID = 6;
        int backLeftDriveMotorID = 7;
        int backLeftTurnMotorID = 8;
    }
    namespace SwerveValues {
        double a;
        double b;
        double c;
        double d;
    }
}

#endif