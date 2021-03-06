// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"

DriveTrain::DriveTrain() = default;
DriveTrain::DriveTrain(SwerveModule frontRightModule, SwerveModule frontLeftModule, SwerveModule backRightModule, SwerveModule backLeftModule) {
    this->frontRightModule = frontRightModule;
    this->frontLeftModule = frontLeftModule;
    this->backRightModule = backRightModule;
    this->backLeftModule = backLeftModule;
    try
    {
        this->gyro = new AHRS(frc::SPI::kMXP);
        std::thread([this] () {
            sleep(1);
            resetGyro();
        });
    }
    catch(const std::exception& e)
    {
       frc::SmartDashboard::PutString("Gyro Status", "Not Pluged In");
    }
    
}
void DriveTrain::resetGyro() {
    gyro->Reset();
}

double DriveTrain::getHeading() {
    return fmod(gyro->GetAngle(), 360);
}
frc::Rotation2d DriveTrain::getRotation2d() {
    units::degree_t degrees{getHeading()};
    frc::Rotation2d out(degrees);
    return out;
    
}

// void DriveTrain::drive(double xInput, double yInput, double zInput) {
// //!TODO offload math to ALO
//     double r = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
//     // standard variable conversions --  Y is foward, X is strafe, Z is rotation:
//     a = xInput - zInput * (HEIGHT / WIDTH);
//     b = xInput + zInput * (HEIGHT / WIDTH);
//     c = yInput  - zInput * (HEIGHT / WIDTH);
//     d = yInput + zInput * (HEIGHT / WIDTH);

//     //speed & rotation calculations    
//     frontRightSpeed = sqrt(pow(b,2) + pow(c,2));
//     frontLeftSpeed = sqrt(pow(b,2) + pow(d,2));
//     backRightSpeed = sqrt(pow(a,2) + pow(c,2));
//     backLeftSpeed = sqrt(pow(a,2) + pow(d,2));

//     frontRightRotation = (atan2(b,c) / M_PI) * 180;
//     frontLeftRotation = (atan2(b,d) / M_PI) * 180;
//     backRightRotation = (atan2(a,c) / M_PI) * 180;
//     backLeftRotaion = (atan2(d,d) / M_PI) * 180;

//     // normalizing if calculated speed is greater than 1
//     speedVector = RobotContainer::alo->pushToVector(speedVector,frontRightSpeed, frontLeftSpeed, backLeftSpeed, backRightSpeed);
//     double speedMax = RobotContainer::alo->maxFromVector(speedVector);
//     if(speedMax > 1.0) {
//         frontRightSpeed = frontRightSpeed / speedMax;
//         frontLeftSpeed = frontLeftSpeed / speedMax;
//         backRightSpeed = backRightSpeed / speedMax;
//         backLeftSpeed = backLeftSpeed / speedMax;
//     }

//     //reset vector to stop memory leaks
//     speedVector.clear();
//}
void DriveTrain::stopModules() {
    frontLeftModule.stop();
    frontRightModule.stop();
    backLeftModule.stop();
    backRightModule.stop();
}
void DriveTrain::setModuleStates(frc::SwerveModuleState desiredStates[]) {
    frontLeftModule.setState(desiredStates[0]);
    frontRightModule.setState(desiredStates[1]);
    backRightModule.setState(desiredStates[2]);
    backLeftModule.setState(desiredStates[3]);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

