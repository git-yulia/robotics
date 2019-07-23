/*
** The beta-bot has: 
**	- IR sensors on both sides so that it can see the alpha coming from any direction
*/

#include "common.h"

typedef enum { HIDE, FLEE, FREEZE } mode_t; 

/*
** experimental
** The beta-bot tries to mimic the IR blink of the alpha to become 
** invisible. 
*/
void misdirection(mode_t mode)
{
	/* pseudocode 
		1. If beta is in HIDE mode and sees alpha from an angle that Alpha cannot see it:
			a. measure the seconds in between blinks by recording ON/OFF cycles and time stamps, 
			b. If fewer than 4 blinks were measured: 
				- break; alpha has moved out of range 
			c. Save the blinking pattern for later use in HIDE mode
		3. If beta is in FLEE or FREEZE mode and this function has been called: 
			a. Check for a mimic blink pattern in memory. If found: 
				- Mimic the pattern. If after 3 seconds, the alpha has gotten even closer:
					+ re-enter FLEE mode by calling flee()
				- else, after 6 seconds of safety: 
					+ re-enter HIDE mode 
	*/
}

/*
** The beta-bot is stunned into immobility for four seconds, facing a wall
** so that the alpha might be unable to see it. (it's a feature, not a bug)
*/
void freeze()
{
	// ...
}

/*
** The beta bot drives away from the location where it recognized 
** its predator, until it no longer senses danger and re-enters 
** HIDE mode.   
*/
void flee()
{
	// ...
}

/*
** The beta-bot finds a nice place to hide and stays put, unless
** it detects the alpha. If detected, the beta enters FLEE mode. 
*/
void hide()
{
	// continuously look for the alpha
}

/*
** Returns true if the alpha is detected. 
*/
bool detect_alpha()
{
	bool result = false; 

	return result; 
}

/*
** this code runs once, at the very beginning
*/
void setup() 
{
	// 1. Set pinmode for each pin as either INPUT or OUTPUT
}

void loop() {

}
