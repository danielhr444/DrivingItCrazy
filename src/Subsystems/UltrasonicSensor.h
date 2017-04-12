#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

#include <Commands/Subsystem.h>

class UltrasonicSensor : public Subsystem {
private:
	Ultrasonic* us;
	double distance;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	UltrasonicSensor();
	~UltrasonicSensor();
	void InitDefaultCommand();
	void InitUltrasonic();
	double FindDistance();
};

#endif  // Ultrasonic_H
