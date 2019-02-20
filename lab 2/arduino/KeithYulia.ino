/*
 * Demo of Hercules control DC Motor
 *
 * 2014-6-27
 *
 * This demo will show you how to control a DC motor
 * you can connect 2 DC motor here, both of they will go 
 * a direction for 3s the turn reverse for 3s
 *
 * This demo use the following function:
 *
 * void setSpeedDir(int ispeed, unsigned char dir);
 * - ispeed - speed, range 0-100, that mean pwm in %
 * - dir - DIRF(0x00) or DIRR(0x01)
 */

#include <Hercules.h>

bool done = false; //stop moving.

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
<<<<<<< HEAD:Dead Reckoning/DC_Motor/Keith_Julia_Octavio_Lab2.ino
=======

  //move_straight(100, 50); // move Brian forward 1 meter 
  turn(180,20); 
  stop_brian(2000);
   
/*
// 3. Rotate 90 degrees
  
>>>>>>> 80f46485df6e243ae4110fdf7305fca785e766f0:Dead Reckoning/DC_Motor/DC_Motor.ino

  //move_straight(100, 50); // move Brian forward 1 meter 
  turn(180,20); 
  stop_brian(2000);
   
/*
// 3. Rotate 90 degrees
  
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(200);
  //Do a little dance
  MOTOR.setSpeedDir(10, DIRF);
  delay(750);
  
// 4. Stop for 2 seconds
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(4000);
  
// 5. Drive Forward 2 meters
  MOTOR.setSpeedDir1(9, DIRF);
  MOTOR.setSpeedDir2(11, DIRF);
  delay(11000);
  
// 6. Stop for 2 seconds
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(4000);
<<<<<<< HEAD:Dead Reckoning/DC_Motor/Keith_Julia_Octavio_Lab2.ino
=======

>>>>>>> 80f46485df6e243ae4110fdf7305fca785e766f0:Dead Reckoning/DC_Motor/DC_Motor.ino
 // 
  MOTOR.setSpeedDir(10, DIRF);
  delay(300);
  
//
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(200);
//// 7. Rotate 90 degrees
  MOTOR.setSpeedDir1(20, DIRF);
  MOTOR.setSpeedDir2(20, DIRR);
  delay(1000);
//  
//// 8. Stop for 2 seconds
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(4000);
//
//// 9. Drive Forward 1 meter
//  MOTOR.setSpeedDir(10, DIRF); //10% drive forward
//  delay(5000);
//
//// 10. Stop for 2 seconds
//  MOTOR.setStop1();
//  MOTOR.setStop2();
//  delay(4000);
//
//// 11. Rotate 90 degrees
//  MOTOR.setSpeedDir1(20, DIRF);
//  MOTOR.setSpeedDir2(20, DIRR);
//  delay(1075);
//
//// 12. Stop for 2 seconds
//  MOTOR.setStop1();
//  MOTOR.setStop2();
//  delay(4000);
//
//// 13. Drive Forward 2 meters
//  MOTOR.setSpeedDir(10, DIRF); //10% drive forward
//  delay(10000);
//
//// 14. Stop
//  done = true;
//  MOTOR.setStop1();
//  MOTOR.setStop2();
*/ 
  }
}