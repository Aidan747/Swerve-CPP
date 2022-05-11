
#ifndef SwerveModule_H
#define SwerveModule_H

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <ctre/phoenix/sensors/CANCoder.h>
#include <Constants.h>
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/angular_velocity.h>
#include <wpi/numbers>
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
        units::radian_t getTurningMotorPostion();
        units::velocity::meters_per_second_t getDriveMotorVelocity();
        double getTurningMotorVelocity();
        double getAbsEncoderRadians();
        void resetEncoders();
        frc::SwerveModuleState getState();
        void setState(frc::SwerveModuleState state);
        double getRawTurningMotorPosition();
        void stop();

    private:
      
        
};

#endif