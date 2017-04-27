#ifndef DriveTrain_H
#define DriveTrain_H

#include <WPILib.h>
//#include "../CommandBase.h"
#include <Commands/Subsystem.h>



class DriveTrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::Talon* left;
	frc::Talon* right;
	frc::Encoder* encoderLeft;
	frc::Encoder* encoderRight;
	float mult;
	int ticksToDistance;
	frc::BuiltInAccelerometer* accel;

public:
	frc::Gyro* gyro;

	DriveTrain();
	~DriveTrain();

	static float Limit(float num, float max);

	void setMult(float m);
	int getMult();
	void arcadeDrive(float move, float rotate);
	void tankDrive(float moveValueLeft, float moveValueRight);

	double getDistance();
	double getRate();
	void resetEncoders();
	void getAccelerations(double* x, double* y, double* z);

	double getRightEncoderDistance();
	double getLeftEncoderDistance();

	double getGyroAngle();
	void resetGyro();

	double readUltra(uint16_t sensorIndex);

	void setSpeedLeft(double speed);
	void setSpeedRight(double speed);   //if needed

	void InitDefaultCommand();


};

#endif  // DriveTrain_H
