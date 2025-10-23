#include<Mouse.h>
#include<Keyboard.h>

int pin1 = 16;
int pin2 = 10;

void setup() {
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
}

void loop() {
  bool press1 = digitalRead(pin1) == LOW;
  bool press2 = digitalRead(pin2) == LOW;

  if(press1){ // if button 1 pressed,
  // INSERT MACRO HERE (scroll down for example macro functions)
    Keyboard.print("bye");
  }

  else if (press2){ // if button 2 pressed,
  // INSERT MACRO HERE (scroll down for example macro functions)
    Keyboard.print("hi");
  }

  delay(100); // short delay so we don't sense
  // 10000 button presses 
}

// EXAMPLE MACROS HERE

void move_in_a_square() {
  Mouse.begin();
  Mouse.move(20, 0, 0);   // Move right
  delay(300);
  Mouse.move(0, 20, 0);   // Move down
  delay(300);
  Mouse.move(-20, 0, 0);  // Move left
  delay(300);
  Mouse.move(0, -20, 0);  // Move up
  delay(300);
}

void mouseclick(){
  // clicks mouse and releases
  Mouse.begin();
  Mouse.click();
}

void go_to_d2l(){
  // go to a browser and click the serach bar, then run this macro
  Keyboard.begin();
  Keyboard.println("d2l");
}

void openNewTab() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
}

void openIncognito() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('n');
  delay(100);
  Keyboard.releaseAll();
}

void refreshPage() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
}

void screenshotOnWindows() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
}

void copyText() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();
}

void pasteText() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  delay(100);
  Keyboard.releaseAll();
}

void cutText() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('x');
  delay(100);
  Keyboard.releaseAll();
}

void undoAction() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  delay(100);
  Keyboard.releaseAll();
}