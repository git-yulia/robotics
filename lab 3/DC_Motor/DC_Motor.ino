/*
Lab 3 
Valentine's Day 
Julia Maliauka, Keith Skinner
 */

#include <Hercules.h>
#include <Ultrasonic.h>

bool done = false; 

void setup()
{
    MOTOR.begin();
}

// move Brian forward the requested distance at the requested speed
// unit is centimeters by popular demand 
void move_straight(int distance, int speed) 
{ 
  int factor [] = {60, 53, 52, 51, 48, 44, 40, 40, 40, 40}; 
  int new_factor = factor[(speed/10) - 1];
  
  if (speed >= 30) {
    move_straight(3, 10);
    distance = distance - 7; 
  }
  
  MOTOR.setSpeedDir1(speed - 1, DIRF); 
  MOTOR.setSpeedDir2(speed, DIRF);
  delay((new_factor*distance)/(speed/10.0));  
}

// move Brian the angular distance at the requested speed 
void turn(int angle, int speed) 
{
  MOTOR.setSpeedDir1(speed, DIRF);
  MOTOR.setSpeedDir2(speed, DIRR);
  delay(angle*11);
}

void stop_brian(int nap_length)
{
  MOTOR.setStop1(); 
  MOTOR.setStop2(); 
  delay(nap_length*1000); 
}

void loop()
{
  if (!done) {

  //move_straight(100, 50); // move Brian forward 1 meter 
  //turn(180,20); 

  
  
  stop_brian(2000);

  

  

  
  }
}
