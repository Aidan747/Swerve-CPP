#include <ctre/Phoenix.h>
#include <memory>
#include <string>
#include <math.h>



using std::string;


#ifndef SwerveModule_H
#define SwerveModule_H

class SwerveModule {
    int driveMotorID;
    int turnMotorID;
    double encoderRotation;

    public:
        SwerveModule(int driveMotorID, int turnMotorID);
        SwerveModule();
        void setSpeed(double input, bool manualSet, bool isCurved = false, double hardSetpoint = 0);
        double getModuleRotation();
        double getSetpoint();
        double getVelocity(string unit = " ");

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
        WPI_TalonFX* driveMotor = new WPI_TalonFX{1};
        WPI_TalonFX* turnMotor = new WPI_TalonFX{1};
        
};

#endif