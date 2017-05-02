//#include "DriveTrain.h"
#include "../RobotMap.h"
#include <math.h>
#include "../CommandBase.h"
#include "../Commands/Tankdrive.h"

using namespace frc;

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain"), left(new Talon(0)), right(new Talon(1)), encoderLeft(
				new Encoder(ENCODER_LEFT_1, ENCODER_LEFT_2)), encoderRight(
				new Encoder(ENCODER_RIGHT_1, ENCODER_RIGHT_2)), mult(1.0), ticksToDistance(
				114), // 112 < ticksToDistance < 117
		accel()
{
	gyro = new frc::ADXRS450_Gyro(SPI::kOnboardCS0);
	std::cout << "why" << std::endl;
	 encoderLeft->SetDistancePerPulse(1.0);
	 encoderRight->SetDistancePerPulse(1.0);
	 left->SetInverted(true);
	 right->SetInverted(true);
	 gyro->Calibrate();
	 gyro->Reset();
	// left->Set(200);
	// right->Set(20);
}

DriveTrain::~DriveTrain()
{
    delete left;
    delete right;
    delete encoderLeft;
    delete encoderRight;
    //delete accel;
    delete gyro;
}

void DriveTrain::setMult(float m)
{
    mult = m;
}

int DriveTrain::getMult()
{
	return mult;
}

void DriveTrain::resetEncoders()
{
    encoderLeft->Reset();
    encoderRight->Reset();
}

void DriveTrain::arcadeDrive(float moveValue, float rotateValue)
{
    float leftMotorOutput;
    float rightMotorOutput;

    moveValue = DriveTrain::Limit(moveValue, 1) * mult;
    rotateValue = DriveTrain::Limit(rotateValue, 1);

    // Standard ArcadeDriveTrain algorithm from Google
    if(moveValue > 0.0)
    {
        if(rotateValue > 0.0)
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = max(moveValue, rotateValue);
        }
        else
        {
            leftMotorOutput = max(moveValue, -rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
    }
    else
    {
        if(rotateValue > 0.0)
        {
            leftMotorOutput = - max(-moveValue, rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
        else
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = - max(-moveValue, -rotateValue);
        }
    }

    float limitedL = DriveTrain::Limit(leftMotorOutput, 1.0);
    float limitedR = -DriveTrain::Limit(rightMotorOutput, 1.0);

    left->Set(-limitedL);
    right->Set(-limitedR); //removed negatives
}

void DriveTrain::tankDrive(float moveValueLeft, float moveValueRight)
{
    //float leftMotorOutput;
    //float rightMotorOutput;

    moveValueLeft = DriveTrain::Limit(moveValueLeft, 1.0);
    moveValueRight = -DriveTrain::Limit(moveValueRight, 1.0);

    //std::cout << "LeftRaw: " << limitedL<< "\n";
	//std::cout << "RightRaw: " << limitedR << "\n";
    // TODO: mult should never be 0, but robot wasn't driving for some reason
    if (mult != 0) {
		left->Set(-moveValueLeft);
		right->Set(-moveValueRight);
    }
    else {
    	left->Set(-moveValueLeft);
		right->Set(-moveValueRight);
    }
}

float DriveTrain::Limit(float num, float max)
{
    if(num > max)
        return max;

    if(num < -max)
        return -max;

    return num;
}

// Return distance in feet
double DriveTrain::getDistance()
{
    // Average of both encoders (must negate to get proper direction)
    return
    (
        (double) ((encoderLeft->Get()) / ticksToDistance) -
        (double) ((encoderRight->Get()) / ticksToDistance)
    ) / 2.0;
}

double DriveTrain::getRate()
{
    // Average of both encoder rates (must negate to get proper direction)
    // TODO: test to see if negation is necessary
    return
    (
        (double) ((encoderLeft->GetRate()) / ticksToDistance) -
        (double) ((encoderRight->GetRate()) / ticksToDistance)
    ) / 2.0;

}

void DriveTrain::getAccelerations(double* x, double* y, double* z)
{
	//*x = accel->GetX();
	//*y = accel->GetY();
	//*z = accel->GetZ();
}

void DriveTrain::InitDefaultCommand()
{
	//std::cout<<"pushpush"<<std::endl;
	SetDefaultCommand(new TankDrive());
}


double DriveTrain::getLeftEncoderDistance()
{
	//TODO negate this and the right one below
	//return this->left->GetPosition();

	return -this->encoderLeft->GetDistance();
}

double DriveTrain::getRightEncoderDistance()
{
	return this->encoderRight->GetDistance();
}

double DriveTrain::getGyroAngle()
{
   // return axis->getzAxis();
	return gyro->GetAngle();
}

void DriveTrain::resetGyro()
{
	gyro->Reset();
}

double DriveTrain::readUltra(uint16_t sensorIndex)
{
	return 0.0;//ultrasonicSensors->ReadUltra(sensorIndex);
}

void DriveTrain::setSpeedLeft(double speed){
	left->SetSpeed(speed);
}

void DriveTrain::setSpeedRight(double speed){
	right->SetSpeed(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
