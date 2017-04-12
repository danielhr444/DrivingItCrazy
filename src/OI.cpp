#include "OI.h"
#include <WPILib.h>

using namespace frc;

OI::OI():
	driveStickLeft(new Joystick(2)), driveStickRight(new Joystick(1))
{

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
