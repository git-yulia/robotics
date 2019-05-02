/*
  AlphaBot robot controller code 
  Keith Skinner, Julia Maliauka, James Morris, Octavio Leon 
  Spring 2019 
*/

#include "Ultrasonic.h"

const int IR_pin = 13; 
const int mic_pin = A0; 
const int buzz_pin = 8; 

// vars for the mic module 
const int mic_input_window = 100; 
unsigned int mic_sample; 

// vars for the "distance to object" module 
long duration, cm, inches;
Ultrasonic ultrasonic(10);

void setup() {
  Serial.begin(9600);
  pinMode(IR_pin, INPUT);
  pinMode(mic_pin, INPUT); 
}

// returns True if there is an enemy in front of us (enemy is TBD)
bool detect_enemy() {
  if (digitalRead(IR_pin) == 0) 
    return true; 
  else
    return false; 
}

// returns the distance to the obstacle in front of it 
// type = 0 gives you inche | type = 1 gives you cm 
long get_distance_to_obstacle (int type) {
    long RangeInInches;
    long RangeInCentimeters;
    long distance_to_obstacle; 

    Serial.println("The distance to obstacles in front is: ");
    RangeInInches = ultrasonic.MeasureInInches();
    Serial.print(RangeInInches);//0~157 inches
    Serial.println(" inch");
    delay(250);

    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    delay(250);

  if (type == 0) 
    distance_to_obstacle = RangeInInches;
  else 
    distance_to_obstacle = RangeInCentimeters; 
     
  return distance_to_obstacle; 
}

void get_microphone_data() {
// two variables for minimum and maximum values in window
  unsigned int inputMax = 0;
  unsigned int inputMin = 1024;

  // loop for the window of time 
  for (unsigned int i = 0; i < mic_input_window; i++) {
    // read in a single value
    mic_sample = analogRead(mic_pin);
    // get the minimum and maximum value
    inputMin = min(inputMin, mic_sample);
    inputMax = max(inputMax, mic_sample);
  }

  // send the values on serial
  Serial.print("Min: ");
  Serial.print(inputMin);
  Serial.print("  Max: ");
  Serial.print(inputMax);
  Serial.print("  Diff: ");
  Serial.print(inputMax - inputMin);
  Serial.println();
}

void buzzer() {
  tone(11, 500, 1000);
}

void run_test_sequence() {
  Serial.print("scanning for enemies...");
  Serial.print(detect_enemy());
  Serial.println();
  // 
  Serial.print("obstacle distance in cm: ");
  Serial.print(get_distance_to_obstacle(1));
  Serial.println();

  Serial.println("getting sound data from the real world..."); 
  // get_microphone_data(); 
  Serial.println(); 

  delay(1000); 
}

void loop() {
  run_test_sequence(); // tests components 

  
 

  
  
  delay(1000);
}
