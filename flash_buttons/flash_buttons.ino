int pin1 = 16;
int pin2 = 10;

void setup() {
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(17, OUTPUT);
  pinMode(30, OUTPUT);
  digitalWrite(17, HIGH);
  digitalWrite(30, HIGH); 
}

void loop() {
  // continuously scan the voltages at the input pins
  // (it's contained in the loop function so we don't have
  // to do anything for looping!)
  bool press1 = digitalRead(pin1) == LOW;
  bool press2 = digitalRead(pin2) == LOW;

  if(press1){ // if button 1 pressed,
    digitalWrite(17, LOW);
    digitalWrite(30, LOW);
    Serial.println("button 1");
  }

  else if (press2){ // if button 2 pressed,
    digitalWrite(17, LOW);
    digitalWrite(30, LOW);
    Serial.println("button 2");
  }

  else{
    digitalWrite(17, HIGH);
    digitalWrite(30, HIGH);
  }
  delay(100); // short delay so we don't sense
  // 10000 button presses 
}


