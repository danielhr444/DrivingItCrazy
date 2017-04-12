#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

const double PIDCON_INCHES = 0.13617;//inches
const double CLICKS_TO_METERS = 0.0008842593;
const double ENCODER_RIGHT_1=0;
const double ENCODER_RIGHT_2=1;
const double ENCODER_LEFT_1=2;
const double ENCODER_LEFT_2=3;

const int MOTORPORT = 0;


#endif  // ROBOTMAP_H
