/*
** The alpha-bot has: 
**	- straight-ahead vision (can only detect prey directly in front of it)
*/

#include "common.h"

typedef enum { SCOUT, CHASE } mode_t; 

/*
** The beta-bot sprints in the direction of the beta. 
**
** Note: If it stays in chase mode for more than 5 seconds, 
** it runs out of energy and loses the game. 
*/
void chase()
{
	// ...
}

/*
** The alpha roams, entering chase mode if it detects the beta. 
*/
void scout()
{
    // ...
}

/*
** Returns true if beta is detected. 
**
** Note: The alpha-bot must be able to tell the difference between 
** the beta-bot's IR output (by its frequency) versus its own reflection off
** of obstacles. 
*/
bool detect_beta()
{
	bool result = false; 

	return result; 
}

/*
** this code runs once, at the very beginning
*/
void setup() 
{
	// 1. Set pinmode for each pin as either INPUT or OUTPUT.
}

void loop() {
    // ...
}
