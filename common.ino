#include "common.h" 

/*
** drives the bot, given a direction and a speed (as a percentage of motor power)
**
** see reference_3.ino 
*/
void drive(direction_t direction, int speed)
{
    // ...
}

/*
** Returns the distance to an obstacle (in cm)
*/
long echo() 
{
	long range; 
	long distance_to_obstacle;

	distance_to_obstacle = ultrasonic.MeasureInCentimeters(); 

	return distance_to_obstacle;
}
