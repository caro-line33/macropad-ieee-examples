const int key_pins[] = {7, 8, 14, 16}; // REPLACE WITH THE PINS YOU CONNECTED YOUR BUTTONS TO
const size_t N = sizeof(key_pins) / sizeof(key_pins[0]);
const int LED_PIN = 17;

void setup() {
  for (size_t i = 0; i < N; i++) {
    // Set key pins as inputs with pullups
  }

  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);
  // start OFF if active-low LED
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  for (size_t i = 0; i < N; i++) {
    if (digitalRead(key_pins[i]) == LOW) { // if button pressed (ie, pin is connected to ground)
      digitalWrite(LED_PIN, LOW);   // LED on
      delay(200);
      digitalWrite(LED_PIN, HIGH);  // LED off
      delay(200);
    }
  }
}
