// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() = default;
DriveTrain::DriveTrain(SwerveModule frontRightModule, SwerveModule frontLeftModule, SwerveModule backRightModule, SwerveModule backLeftModule) {
    this->frontRightModule = frontRightModule;
    this->frontLeftModule = frontLeftModule;
    this->backRightModule = backRightModule;
    this->backLeftModule = backLeftModule;
}
void DriveTrain::setAllMotors(double setpoint) {
    frontRightModule.setSpeed(setpoint);
}

void DriveTrain::drive(double xInput, double yInput, double zInput) {
//!TODO offload math to ALO
    double r = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
    // standard variable conversions --  Y is foward, X is strafe, Z is rotation:
    a = xInput - zInput * (HEIGHT / WIDTH);
    b = xInput + zInput * (HEIGHT / WIDTH);
    c = yInput  - zInput * (HEIGHT / WIDTH);
    d = yInput + zInput * (HEIGHT / WIDTH);

    //speed & rotation calculations    
    frontRightSpeed = sqrt(pow(b,2) + pow(c,2));
    frontLeftSpeed = sqrt(pow(b,2) + pow(d,2));
    backRightSpeed = sqrt(pow(a,2) + pow(c,2));
    backLeftSpeed = sqrt(pow(a,2) + pow(d,2));

    frontRightRotation = atan2(b,c);
    frontLeftRotation = atan2(b,d);
    backRightRotation = atan2(a,c);
    backLeftRotaion = atan2(d,d);

    // normalizing if calculated speed is greater than 1
    speedVector = ALO::pushToVector(speedVector,frontRightSpeed, frontLeftSpeed, backLeftSpeed, backRightSpeed);
    double speedMax = ALO::maxFromVector(speedVector);
    if(speedMax > 1.0) {
        frontRightSpeed = frontRightSpeed / speedMax;
        frontLeftSpeed = frontLeftSpeed / speedMax;
        backRightSpeed = backRightSpeed / speedMax;
        backLeftSpeed = backLeftSpeed / speedMax;
    }

    //reset vector to stop memory leaks
    speedVector.clear();
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

