#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int rowPins[2] = {15, 14}; // rows
int colPins[2] = {10, 16}; // cols

bool keyState[2][2] = { {false,false}, {false,false} };

// key actions
void showText(const char* s){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(12, 24);
  display.println(s);
  display.display();
}

void action_00(){ showText("hello!"); }
void action_01(){ showText("yay!");   }
void action_10(){ showText("hi!");    }
void action_11(){ showText("bye!");   }

void (*actions[2][2])() = {
  { action_00, action_01 },
  { action_10, action_11 }
};

void setup() {
  // ---- OLED init (REQUIRED)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1) {} // hang if not found
  }
  display.clearDisplay();
  display.display();

  // matrix IO
  for (int c = 0; c < 2; c++) pinMode(colPins[c], INPUT_PULLUP);
  for (int r = 0; r < 2; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH); // idle HIGH
  }
}

void loop() {
  for (int r = 0; r < 2; r++) {
    // drive this row LOW, others HIGH
    for (int i = 0; i < 2; i++) digitalWrite(rowPins[i], (i == r) ? LOW : HIGH);
    delayMicroseconds(50); // settle after switching row

    for (int c = 0; c < 2; c++) {
      bool pressed = (digitalRead(colPins[c]) == LOW); // INPUT_PULLUP: LOW=pressed
      if (pressed && !keyState[r][c]) {
        keyState[r][c] = true;
        actions[r][c]();           // call the mapped action
      } else if (!pressed && keyState[r][c]) {
        keyState[r][c] = false;
      }
    }
  }
}
