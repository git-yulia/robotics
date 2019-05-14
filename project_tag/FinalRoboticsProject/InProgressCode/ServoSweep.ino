#include <Servo.h>
#include "Ultrasonic.h"
#include <IRremote.h>
Servo servo; 
Ultrasonic ultrasonic(13); // we are letting the compiler know that the ultrasonic sensor is on pin 13 

int trigPin = 10; 
int echoPin = 12; 
int servoPin = 10; 
int tonePin = 8; 
long duration; // duration of the ultrasonic sensor
double cm, inches; // these variables give is the measurements for how far away an object is
int angle = 0; // default angle

// All motor related things 

const int enAPin = 6; // Left motor PWN speed control 
const int in1Pin = 7; // Left motor Direction 1
const int in2Pin = 5; // Left motor Direction 2 

/////////////////////////////////////////////////////
const int in3Pin = 4; // Right motor Direction 1
const int in4Pin = 2; // Right motor Direction 2
const int enBPin = 3; // Right motor PWN speed control 


//void irDetection()
//{
//  int detect = digitalRead(irPin);
//  if(detect == LOW)
//  {
//    Serial.println("Obstacle on the way"); 
//  } 
//  else
//  {
//    Serial.println("All clear"); 
//  }
//  delay(300); 
//}



// Read distance from the ultrasonic sensor , return distance in mm
//
// Speed of sound in dry air , 20C is 343 m/s
// pulseIn returns time in microseconds (10ˆ􀀀6)
// 2d = p * 10ˆ􀀀6 s * 343 m/s = p * 0.00343 m = p * 0.343 mm/us
unsigned int readDistance ()
{

  digitalWrite ( trigPin , HIGH );
  delayMicroseconds(10);
  digitalWrite ( trigPin , LOW );
  unsigned long period = pulseIn ( echoPin, HIGH );
  Serial.print(period);
  Serial.print("cm, ");
  Serial.println();
  return period * 343 / 2000;

}


#define NUM_ANGLES 7
unsigned char sensorAngle[NUM_ANGLES] = {60, 70, 80, 90, 100, 110, 120};
unsigned int distance [NUM_ANGLES];
// Scan the area ahead by sweeping the ultrasonic sensor left and right
// and recording the distance observed. This takes a reading , then
// sends the servo to the next angle . Call repeatedly once every 50 ms or so.
void readNextDistance()
{

  static unsigned char angleIndex = 0;
  static signed char step = 1;
  distance [angleIndex] = readDistance ();
  angleIndex += step ;
  if (angleIndex == NUM_ANGLES - 1) step = -1;
  else if (angleIndex == 0) step = 1;
  servo.write ( sensorAngle[angleIndex] );

}


void speakerTone()
{
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 675.0);
    delay(750.0);
    tone(tonePin, 220, 675.0);
    delay(750.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 450.0);
    delay(500.0);
    tone(tonePin, 220, 450.0);
    delay(500.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 293, 675.0);
    delay(750.0);
    tone(tonePin, 195, 675.0);
    delay(750.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 246, 112.5);
    delay(125.0);
    tone(tonePin, 293, 450.0);
    delay(500.0);
    tone(tonePin, 195, 450.0);
    delay(500.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 246, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 329, 675.0);
    delay(750.0);
    tone(tonePin, 220, 675.0);
    delay(750.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 450.0);
    delay(500.0);
    tone(tonePin, 220, 450.0);
    delay(500.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 293, 675.0);
    delay(750.0);
    tone(tonePin, 195, 675.0);
    delay(750.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 246, 112.5);
    delay(125.0);
    tone(tonePin, 293, 450.0);
    delay(500.0);
    tone(tonePin, 195, 450.0);
    delay(500.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 246, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 329, 675.0);
    delay(750.0);
    tone(tonePin, 220, 675.0);
    delay(750.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 450.0);
    delay(500.0);
    tone(tonePin, 220, 450.0);
    delay(500.0);
    tone(tonePin, 261, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 246, 450.0);
    delay(500.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 450.0);
    delay(500.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 450.0);
    delay(500.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 246, 450.0);
    delay(500.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 293, 675.0);
    delay(750.0);
    tone(tonePin, 195, 675.0);
    delay(750.0);
    tone(tonePin, 246, 337.5);
    delay(375.0);
    tone(tonePin, 261, 337.5);
    delay(375.0);
    tone(tonePin, 246, 337.5);
    delay(375.0);
    tone(tonePin, 195, 337.5);
    delay(375.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 195, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 174, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 174, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 112.5);
    delay(125.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 112.5);
    delay(125.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 87, 225.0);
    delay(250.0);
    tone(tonePin, 110, 112.5);
    delay(125.0);
    tone(tonePin, 123, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 87, 225.0);
    delay(250.0);
    tone(tonePin, 110, 112.5);
    delay(125.0);
    tone(tonePin, 123, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 123, 225.0);
    delay(250.0);
    tone(tonePin, 146, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 220, 112.5);
    delay(125.0);
    tone(tonePin, 195, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 174, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 164, 112.5);
    delay(125.0);
    tone(tonePin, 174, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 112.5);
    delay(125.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 112.5);
    delay(125.0);
    tone(tonePin, 146, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 87, 225.0);
    delay(250.0);
    tone(tonePin, 110, 112.5);
    delay(125.0);
    tone(tonePin, 123, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 87, 225.0);
    delay(250.0);
    tone(tonePin, 110, 112.5);
    delay(125.0);
    tone(tonePin, 123, 112.5);
    delay(125.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 130, 225.0);
    delay(250.0);
    tone(tonePin, 123, 225.0);
    delay(250.0);
    tone(tonePin, 97, 225.0);
    delay(250.0);
    tone(tonePin, 123, 225.0);
    delay(250.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 110, 225.0);
    delay(250.0);
    tone(tonePin, 82, 225.0);
    delay(250.0);
    tone(tonePin, 87, 112.5);
    delay(125.0);
    tone(tonePin, 97, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 164, 225.0);
    delay(250.0);
    tone(tonePin, 174, 112.5);
    delay(125.0);
    tone(tonePin, 195, 112.5);
    delay(125.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 349, 112.5);
    delay(125.0);
    tone(tonePin, 391, 112.5);
    delay(125.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 349, 112.5);
    delay(125.0);
    tone(tonePin, 391, 112.5);
    delay(125.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 349, 112.5);
    delay(125.0);
    tone(tonePin, 391, 112.5);
    delay(125.0);
    tone(tonePin, 440, 675.0);
    delay(750.0);
}



void motorDrive()
{
  
   //Turn on the left Motor 
   digitalWrite(in1Pin, HIGH);
   digitalWrite(in2Pin, LOW);  


// const int enAPin = 6; // Left motor PWN speed control 
//const int in1Pin = 7; // Left motor Direction 1
//const int in2Pin = 5; // Left motor Direction 2 
//
///////////////////////////////////////////////////////
//const int in3Pin = 4; // Right motor Direction 1
//const int in4Pin = 2; // Right motor Direction 2
//const int enBPin = 3; // Right motor PWN speed control

   //Set speed to 200 out of a possible range 0 -255
   analogWrite(enAPin, 95); 

   // Turn on the right motor
   digitalWrite(in3Pin, HIGH);
   digitalWrite(in4Pin, LOW);


   //Set speed to 200 out of a possible range 0 -255
   analogWrite(enBPin, 95); 
   delay(2000);


}







const int REC_PIN = 9; 
IRrecv irrecv(REC_PIN);
decode_results results; 
 
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); // Initiate the serial monitor  
  servo.attach(servoPin); // attach the servo motor that is located on pin 11
  servo.write(0); // By default we are positioning the servo motor at an angle '0'
  pinMode(trigPin, OUTPUT); //sends the sound wave
  pinMode(echoPin, INPUT); // receives the wave in order to calculate the distance
  pinMode(tonePin, OUTPUT); 

  //Motor related setup 
  pinMode(enAPin, OUTPUT);
  pinMode(enBPin, OUTPUT); 
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT); 
  pinMode(in3Pin, OUTPUT); 
  pinMode(in4Pin, OUTPUT);  


 // pinMode(13,OUTPUT); 
  pinMode(8,OUTPUT); // Immiting IR 

  irrecv.enableIRIn(); 
  irrecv.blink13(true); 
  decode_results results; 
}

int inputVal = 0; 
void loop() {
 
  //servoSweep(); 
  //irDetection();
  //speakerTone();  
  //motorDrive();
 // speakerTone();  
  //double currentDistance = readDistance(); 

//  if(digitalRead(8) == HIGH)
//  {
//    digitalWrite(13,HIGH);
//  }
//  else
//  {
//    digitalWrite(13,LOW); 
//  }
//  inputVal = digitalRead(8);
//  Serial.println(inputVal);
//  delay(1000);   

  if(irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);
    irrecv.resume();  
  }

//  Serial.print(readDistance());
//  Serial.print("cm, ");
//  Serial.println(); 



 
}
