#include "CommandBase.h"
#include <Commands/Scheduler.h>
#include "RobotMap.h"

using namespace frc;

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

DriveTrain* CommandBase::drive = nullptr;
UltrasonicSensor* CommandBase::ultrasonic = nullptr;
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::initialize()
{
	drive = new DriveTrain();
	ultrasonic = new UltrasonicSensor();
	oi = std::make_unique<OI>();
}
