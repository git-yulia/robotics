#include <Ultrasonic.h>
#include <Drive.h>
#include <TimerOne.h> //Pins 11, 12, 13
#include <TimerThree.h> //Pins 2, 3, 5

const int PIN_MOTOR_LEFT[2] = {9, 10};
const int PIN_MOTOR_RIGHT[2] = {8, 7};

const int PIN_IR_RR = 2;
const int PIN_IR_RM = 3;
const int PIN_IR_LM = 19;
const int PIN_IR_LL = 18;

//SPEAKER
//const int PIN_SPKR = 7;

//SONAR
const int PIN_SONAR[2] { A14, A15 };

Ultrasonic sonar(PIN_SONAR[0]);
Drive motors(PIN_MOTOR_RIGHT[0], PIN_MOTOR_RIGHT[1], PIN_MOTOR_LEFT[0], PIN_MOTOR_LEFT[1]);

volatile int lastHigh = 0;

String pinToString(int pin)
{
  switch(pin) {
    case PIN_IR_RR: return "PIN_IR_RR";
    case PIN_IR_RM: return "PIN_IR_RM";
    case PIN_IR_LM: return "PIN_IR_LM";
    case PIN_IR_LL: return "PIN_IR_LL";
    default: return "";
  }
}

void writeLastHigh(int pin)
{
  lastHigh = pin;
}


volatile long measure = 0;
volatile long average = 0;
volatile long count = 0;
void function() {
  long centimeters = sonar.MeasureInCentimeters();
  centimeters = min(500, centimeters);
  centimeters = max(8, centimeters);
  measure += centimeters;
  ++count;
  average = measure / count;
}

void writeRRHigh() {writeLastHigh(PIN_IR_RR);}
void writeRMHigh() {writeLastHigh(PIN_IR_RM);}
void writeLMHigh() {writeLastHigh(PIN_IR_LM);}
void writeLLHigh() {writeLastHigh(PIN_IR_LL);}

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1500);
  Timer1.attachInterrupt(function);
  motors.stop();

  pinMode(PIN_IR_RR, INPUT_PULLUP);
  pinMode(PIN_IR_RM, INPUT_PULLUP);
  pinMode(PIN_IR_LM, INPUT_PULLUP);
  pinMode(PIN_IR_LL, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_IR_RR), writeRRHigh, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_IR_RM), writeRMHigh, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_IR_LM), writeLMHigh, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_IR_LL), writeLLHigh, RISING);
}

const int FORWARD_SPEED = 100;
const int TURN_SPEED = 80;

void loop() {
  switch (lastHigh) {
    case PIN_IR_RR:
      motors.right(TURN_SPEED);
      break;
    case PIN_IR_RM:
      motors.forward(FORWARD_SPEED);
      break;
    case PIN_IR_LM:
      motors.forward(FORWARD_SPEED);
      break;
    case PIN_IR_LL:
      motors.left(TURN_SPEED);
      break;
    default:
      motors.stop();
  }
}