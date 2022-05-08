
#ifndef SwerveModule_H
#define SwerveModule_H

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <frc/Encoder.h>
#include <memory>
#include <string>
#include <math.h>


using std::string;
using rev::CANSparkMax;
using frc::Encoder;

class SwerveModule {
    int driveMotorID;
    int turnMotorID;
    double encoderRotation;

    public:
        SwerveModule(int driveMotorID, int turnMotorID);
        SwerveModule();
        void setSpeed(double input, bool isCurved = false);
        double getModuleRotation();
        double getSetpoint();
        double getVelocity(string unit = " ");
        double azimuthError(double target);

    private:
        double joyInput;
        int getIDs(string motor) {
            if(motor == "driveMotor") {
                return driveMotorID;
            }
            else if(motor == "turnMotor") {
                return turnMotorID;
            }
        }
        Encoder* moduleEncoder;
        CANSparkMax* driveMotor;
        CANSparkMax* turnMotor;
        
};

#endif