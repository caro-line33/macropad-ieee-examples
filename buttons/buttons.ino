void setup() {
  int pin1 = 16;
  int pin2 = 10;
  // set pins to INPUT_PULLUP. HIGH voltage when floating.
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
}

void loop() {
  // continuously scan the voltages at the input pins
  // (it's contained in the loop function so we don't have
  // to do anything for looping!)
  bool press1 = digitalRead(pin1) == LOW;
  bool press2 = digitalRead(pin2) == LOW;

  if(press1){ // if button 1 pressed,
    Serial.println("bye"); // print Bye
  }

  if (press2){ // if button 2 pressed,
    Serial.println("hi"); // print Hi
  }
  delay(100); // short delay so we don't sense
  // 10000 button presses 
}


