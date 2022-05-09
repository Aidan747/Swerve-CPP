
#ifndef SwerveModule_H
#define SwerveModule_H

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>
#include <memory>
#include <string>
#include <math.h>
#include <frc2/command/PIDSubsystem.h>
#include <frc/controller/PIDController.h>


using std::string;
using rev::CANSparkMax;
using rev::CANEncoder;
using frc::AnalogInput;

class SwerveModule {
    int driveMotorID;
    int turnMotorID;

    double absEncoderOffset; /* in radians */
    bool absEncoderReversed;

    AnalogInput* moduleEncoder;
    CANSparkMax* driveMotor;
    CANSparkMax* turnMotor;
    frc::PIDController* PIDCtrl;

    public:
        SwerveModule(int driveMotorID, int turnMotorID, bool driveMotorReversed, bool turnMotorReversed, int encoderID, double absEncoderOffset, bool absEncoderReversed);
        SwerveModule();
        double getDriveMotorPosition();
        double getTurningMotorPostion();
        double getDriveMotorVelocity();
        double getTurningMotorVelocity();
        double getAbsEncoderRadians();

    private:
      
        
};

#endif