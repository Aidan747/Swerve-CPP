// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Joystick.h>
#include <AHRS.h>
#include <frc/SPI.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "subComponents/SwerveModule.h"
#include <frc/kinematics/SwerveDriveKinematics.h>

#define WIDTH 10
#define HEIGHT 10


using frc::Joystick;

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
  DriveTrain(SwerveModule frontRight, SwerveModule frontLeft, SwerveModule backRight, SwerveModule backLeft);

  void drive(double xInput, double yInput, double zInput);
  void setAllMotors(double setpoint);
  void resetGyro();
  double getHeading();
  frc::Rotation2d getRotation2d();
  void stopModules();
  void setModuleStates(frc::SwerveModuleState desiredStates[]);
  //change, from center of robot
  frc::Translation2d frontLeftLocation{0.381_m, 0.381_m};
  frc::Translation2d frontRightLocation{0.381_m, -0.381_m};
  frc::Translation2d backLeftLocation{-0.381_m, 0.381_m};
  frc::Translation2d backRightLocation{-0.381_m, -0.381_m};

  frc::SwerveDriveKinematics<4> kinematics{frontLeftLocation, frontRightLocation, backLeftLocation, backRightLocation};
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  SwerveModule frontRightModule;
  SwerveModule frontLeftModule;
  SwerveModule backRightModule;
  SwerveModule backLeftModule;

  AHRS* gyro = nullptr;

  std::vector<double> speedVector;

  double a;
  double b;
  double c;
  double d;
  
  double frontRightSpeed;
  double frontLeftSpeed;
  double backRightSpeed;
  double backLeftSpeed;

  double frontRightRotation;
  double backRightRotation;
  double frontLeftRotation;
  double backLeftRotaion;
  
};
