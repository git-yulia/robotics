/*
  AlphaBot robot controller code 
  Keith Skinner, Julia Maliauka, James Morris, Octavio Leon 
  Spring 2019 
*/

int trigger_pin = 11; 
int echo_pin = 26;  
int IR_pin = 22; 

long duration, cm, inches;

void setup() {
  Serial.begin(9600);
  pinMode(IR_pin, INPUT);
  pinMode(trigger_pin, OUTPUT); 
  pinMode(echo_pin, INPUT); 
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

void loop() {
  Serial.print("scanning for enemies...");
  Serial.print(detect_enemy());
  Serial.println();

  Serial.println("obstacle distance in cm:");
  Serial.print(get_distance_to_obstacle(1));
  Serial.println();
  
  delay(1000);
}
