const int to_test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16, 18, 19, 20, 21}; // list of all pins to test
const size_t N = sizeof(to_test) / sizeof(to_test[0]); // size of array
const int LED_PIN = 17; // internal LED pin number

void setup() {
  // set all test pins to INPUT_PULLUP so they can sense if they are connected to ground.
  for (size_t i = 0; i < N; ++i) {
    pinMode(to_test[i], INPUT_PULLUP);
  }

  pinMode(LED_PIN, OUTPUT); // set internal LED pin to an output
  digitalWrite(LED_PIN, HIGH); // start ON (high turns internal LED off but turns external LED on bc of diode polarity)
}

// loop thru each pin and reach its voltage. if it is LOW that means that it is grounded.
void loop() {
  for (size_t i = 0; i < N; ++i) {
    if (digitalRead(to_test[i]) == LOW) { // if grounded
      // flash LED on and then off
      digitalWrite(LED_PIN, LOW);  // ON
      delay(200);
      digitalWrite(LED_PIN, HIGH); // OFF
      delay(200);
    }
  }
}
