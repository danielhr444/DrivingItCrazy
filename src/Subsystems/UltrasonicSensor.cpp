#include <Subsystems/UltrasonicSensor.h>
#include "../RobotMap.h"

UltrasonicSensor::UltrasonicSensor() : Subsystem("UltrasonicSensor")
{
	us->Initialize();
}

void UltrasonicSensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void UltrasonicSensor::InitUltrasonic()
{
	us->Initialize();
}

double UltrasonicSensor::FindDistance()
{
	//us->Ping();
	distance = us->GetRangeInches(); //TODO: Check if correct
	return distance;
}

UltrasonicSensor::~UltrasonicSensor()
{
	delete us;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
