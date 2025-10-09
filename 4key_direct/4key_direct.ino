const int ROWS = 2;
const int COLS = 2;

int rowPins[ROWS] = {2, 3};   // Connect to the row pins of the keypad
int colPins[COLS] = {4, 5};   // Connect to the column pins of the keypad

void setup() {
  Serial.begin(9600);

  // Initialize row pins as outputs
  for (int r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH); // idle high
  }

  // Initialize column pins as inputs with pull-ups
  for (int c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
}

void loop() {
  for (int r = 0; r < ROWS; r++) {
    // Set the current row LOW
    digitalWrite(rowPins[r], LOW);

    // Check each column
    for (int c = 0; c < COLS; c++) {
      if (digitalRead(colPins[c]) == LOW) {
        Serial.print("Pressed -> Row: ");
        Serial.print(r);
        Serial.print(", Col: ");
        Serial.println(c);
        delay(200); // debounce delay
      }
    }

    // Set the row back to HIGH
    digitalWrite(rowPins[r], HIGH);
  }
}