

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print(digitalRead(2));
  Serial.print(" ");
}
