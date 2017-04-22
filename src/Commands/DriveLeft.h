#ifndef DriveLeft_H
#define DriveLeft_H

#include <Commands/CommandGroup.h>
#include "../Commands/TurnAndDrive.h"

class DriveLeft : public CommandGroup {
public:
	DriveLeft(int distance);
};

#endif  // DriveLeft_H
