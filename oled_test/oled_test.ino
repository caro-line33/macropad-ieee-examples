#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128   // OLED width, in pixels
#define SCREEN_HEIGHT 64   // OLED height, in pixels
#define OLED_RESET -1      // Reset pin (often not used)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize display at I2C address 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    // If screen not found, hang here
    for (;;);
  }

  display.clearDisplay();            // clear buffer
  display.setTextSize(3);            // make it big
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 25);         // position text
  display.println("hello!");             // write text
  display.display();                 // show it!
}

void loop() {
  // nothing here — text stays on screen
}
