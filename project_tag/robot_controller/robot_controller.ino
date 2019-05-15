/*
  AlphaBot robot controller code 
  Keith Skinner, Julia Maliauka, James Morris, Octavio Leon 
  Spring 2019 
*/

#include "Ultrasonic.h"

const int IR_pin = 7; 
const int mic_pin = A0; 
const int buzz_pin = A11; 

unsigned long previousTime = 0; 

// vars for the mic module 
const int mic_input_window = 100; 
unsigned int mic_sample; 

// const vars for motors 
const int ENA = 8;
const int IN1 = 9;
const int IN2 = 10;

const int IN3 = 6; 
const int IN4 = 12;
const int ENB = 13; 

// vars for the "distance to object" module 
long duration, cm, inches;
Ultrasonic ultrasonic(2);

void setup() {
  Serial.begin(9600);
  pinMode(IR_pin, INPUT);
  pinMode(mic_pin, INPUT); 

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(buzz_pin, 0);
}

// returns True if there is an enemy in front of us (enemy is TBD)
bool detect_enemy() {
  bool enemy_found = false; 
  unsigned long currentTime = millis();
  unsigned long previousTime = millis();
  int interval = 4000; 

  // these vars are for determining how fast the IR is blinking
  bool IR_detected = false; 
  int number_of_changes = 0; 
  
  // measure for an interval and then decide if enemy or self
  while (currentTime < (previousTime + interval)) {
    currentTime = millis(); 

    if (digitalRead(IR_pin) != IR_detected) {
      number_of_changes++; 
      IR_detected = digitalRead(IR_pin); 
    }
  }

  if (number_of_changes < 8) {
     enemy_found = true; 
  }

  Serial.println("number of changes");
  Serial.println(number_of_changes);
  delay(1000);
  
  return enemy_found; 
}

// returns the distance to the obstacle in front of it 
// type = 0 gives you inche | type = 1 gives you cm 
long get_distance_to_obstacle (int type) {
    long RangeInInches;
    long RangeInCentimeters;
    long distance_to_obstacle; 

    Serial.println("The distance to obstacles in front is: ");


  if (type == 0) {
    RangeInInches = ultrasonic.MeasureInInches();
    Serial.print(RangeInInches);//0~157 inches
    Serial.println(" inch");
    distance_to_obstacle = RangeInInches;
  }
  else {
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    distance_to_obstacle = RangeInCentimeters; 
  }
     
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

void run_test_sequence() {
  Serial.print("scanning for enemies...");
  Serial.print(detect_enemy());
  Serial.println();
  
  Serial.print("obstacle distance in cm: ");
  Serial.print(get_distance_to_obstacle(1));
  Serial.println();

  Serial.println("getting sound data from the real world..."); 
  get_microphone_data(); 
  Serial.println(); 

  delay(1000); 
}

void buzz() {
  tone(buzz_pin, 300, 100);
}


void drive_forward() {
  analogWrite(ENA, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 100);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void drive_backward() {
  analogWrite(ENA, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 100);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop_agunia() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turn_left_backward() {
  analogWrite(ENA, 190);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void drive_around() {
  stop_agunia();
  delay(500); 

  while(get_distance_to_obstacle(1) <= 15) {
    Serial.println("going back");
    drive_backward(); 
  }

  turn_left_backward(); 
  delay(400);
}

void drive_forward_a_bit() {
  Serial.println();
}

void sweep() {
  // turn in an arc

  // if you see beta bot, stop

  Serial.println();
  
}

void find_betabot() {
  
 while (detect_enemy() == false) {
    drive_forward_a_bit(); 
    sweep(); 
    delay(100);
 }

  buzz(); 
  delay(200);
  noTone(buzz_pin);
  analogWrite(buzz_pin, 0);
  
    while(get_distance_to_obstacle(1) > 15) {
      Serial.println("going forward");
      drive_forward(); 
    }
    delay(300);
 
 stop_agunia(); 
  
}

void loop() {
  // run_test_sequence();
  // drive_around(); 

  find_betabot(); 
  
  
}
