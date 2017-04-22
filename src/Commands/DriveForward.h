#ifndef DriveForward_H
#define DriveForward_H

#include <Commands/CommandGroup.h>
#include "../Commands/TurnAndDrive.h"

class DriveForward : public CommandGroup {
public:
	DriveForward(int distance);

};

#endif  // DriveForward_H
