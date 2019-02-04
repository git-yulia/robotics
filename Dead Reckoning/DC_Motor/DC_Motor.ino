/*
 * Demo of Hercules control DC Motor
 *
 * Loovee
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
//int 1meter = 58.5/1000

void setup()
{
    MOTOR.begin();                      // initialize
}

void loop()
{
  if (!done) {
// 1. Drive Forward 1 meter
  MOTOR.setSpeedDir1(9, DIRF); //10% drive forward
  MOTOR.setSpeedDir2(10, DIRF);
  delay(5800); // 4250
  
// 2. Stop for 2 seconds
  MOTOR.setStop1();
  MOTOR.setStop2();
  delay(2000);
  
// 3. Rotate 90 degrees
  MOTOR.setSpeedDir1(20, DIRF);
  MOTOR.setSpeedDir2(20, DIRR);
  delay(1000); // 1150

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

  //make a little hug
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
  }
}
