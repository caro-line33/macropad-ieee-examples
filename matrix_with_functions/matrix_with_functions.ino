int rowPins[2] = {15, 14}; // R0, R1
int colPins[2] = {10, 16}; // C0, C1

bool keyState[2][2] = { {false,false}, {false,false} };

// key actions
void action_00(){
  // insert code here
}

void action_01(){
  // insert code here
}

void action_10(){
  // insert code here
}

void action_11(){
  // insert code here
}

// 2D array of function pointers.
void (*actions[2][2])() = {
  { action_00, action_01 },
  { action_10, action_11 }
};

void setup() {
  for (int c = 0; c < 2; c++) pinMode(colPins[c], INPUT_PULLUP);
  for (int r = 0; r < 2; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }
}

void loop() {
  for (int r = 0; r < 2; r++) {
    for (int i = 0; i < 2; i++) digitalWrite(rowPins[i], (i == r) ? LOW : HIGH);
    for (int c = 0; c < 2; c++) {
      bool pressed = (digitalRead(colPins[c]) == LOW);
      if (pressed && !keyState[r][c]) {
        keyState[r][c] = true;
        actions[r][c]();
      } else if (!pressed && keyState[r][c]) {
        keyState[r][c] = false;
      }
    }
  }
}
