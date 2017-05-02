#ifndef DriveCode_H
#define DriveCode_H

#include <Commands/CommandGroup.h>
#include "TurnAndDrive.h"

class DriveCode : public CommandGroup {

private:
	double distance;
	double angle;
public:
	DriveCode();
};

#endif  // DriveCode_H
