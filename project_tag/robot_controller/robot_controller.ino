/*
  AlphaBot robot controller code 
  Keith Skinner, Julia Maliauka, James Morris, Octavio Leon 
  Spring 2019 
*/

const int IR_pin = 13; 
const int mic_pin = A0; 
const int buzz_pin = 8; 

// vars for the mic module 
const int mic_input_window = 100; 
unsigned int mic_sample; 

// vars for the "distance to object" module 
long duration, cm, inches;

void setup() {
  Serial.begin(9600);
  pinMode(IR_pin, INPUT);
  pinMode(trigger_pin, OUTPUT); 
  pinMode(echo_pin, INPUT); 
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
int get_distance_to_obstacle (int type) {
  int distance_to_obstacle = 0; 

  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from ping to echo reception 
  pinMode(echo_pin, INPUT);
  duration = pulseIn(echo_pin, HIGH);

  // convert the time (duration) to a distance 
  if (type == 0) 
    distance_to_obstacle = (duration/2) / 74;   // distance in inches 
  else 
    distance_to_obstacle = (duration/2) / 29.1; // distance in cm 
  
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
  // Serial.print(get_distance_to_obstacle(1));
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
