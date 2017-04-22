#ifndef DriveRight_H
#define DriveRight_H

#include <Commands/CommandGroup.h>
#include "../Commands/TurnAndDrive.h"

class DriveRight : public CommandGroup {
public:
	DriveRight(int distance);
};

#endif  // DriveRight_H
