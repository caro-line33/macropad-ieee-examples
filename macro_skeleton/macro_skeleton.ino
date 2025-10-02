#include <Keyboard.h> // keyboard library for keyboard functions

const int key_pins[] = {7, 8, 14, 16}; // REPLACE WITH THE PINS YOU CONNECTED YOUR BUTTONS TO
const size_t N = sizeof(key_pins) / sizeof(key_pins[0]);
const int LED_PIN = 17;
const unsigned long debounceDelay = 500; // ms
unsigned long lastPress = 0;

void setup() {
  for (size_t i = 0; i < N; i++) {
    pinMode(key_pins[i], INPUT_PULLUP);
  }

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  for (size_t i = 0; i < N; i++) {
    if (digitalRead(key_pins[i]) == LOW) { // if button pressed (ie, pin is connected to ground)
      unsigned long now = millis(); // debounce
        if (now - lastPress > debounceDelay) {

          // THIS IS THE MACROS PART
          Serial.println(key_pins[i]);

          // macro for button 1
          if(key_pins[i] == 7){
            Serial.println("hi");
          }

          // macro for button 2
          if(key_pins[i] == 14){
            Serial.println("ieee");
          }

          // macro for button 3
          if(key_pins[i] == 16){
            Serial.println("macropad");
          }

          // macro for button 4
          if(key_pins[i] == 8){
            Serial.println("hello");
          }
          lastPress = now;
        }
    }
  }
}