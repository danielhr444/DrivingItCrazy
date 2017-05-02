#include "OI.h"
#include <WPILib.h>

using namespace frc;

OI::OI():
	driveStickLeft(new Joystick(0)), driveStickRight(new Joystick(1))
{
	std::cout << "work" << std::endl;
}

Joystick* OI::getDriveStickLeft()
{
    return driveStickLeft;
}

Joystick* OI::getDriveStickRight()
{
    return driveStickRight;
}

OI::~OI()
{
    delete driveStickLeft;
    delete driveStickRight;
}
