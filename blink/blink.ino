// Blink an LED on Arduino Pro Micro
// Built-in LED is on pin 17 (labeled RX LED)

void setup() {
  pinMode(17, OUTPUT); // Set the RX LED pin as output
}

void loop() {
  digitalWrite(17, HIGH); // Turn LED on
  delay(500);             // Wait 500 ms
  Serial.println("Hi!");
  digitalWrite(17, LOW);  // Turn LED off
  delay(500);             // Wait 500 ms
  Serial.println("Bye!");
}

