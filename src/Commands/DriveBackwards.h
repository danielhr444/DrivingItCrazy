#ifndef DriveBackwards_H
#define DriveBackwards_H

#include <Commands/CommandGroup.h>
#include "../Commands/TurnAndDrive.h"

class DriveBackwards : public CommandGroup {
public:
	DriveBackwards(int distance);
};

#endif  // DriveBackwards_H
