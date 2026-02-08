#define USE_NIMBLE
#include <BleMouse.h>

BleMouse bleMouse("ESP32 Multi-Mouse", "Maker", 100);

const int potX = 34; 
const int potY = 35;
const int centerBtn = 13; 
const int rightBtn = 14; // External button for Right Click

const int center = 2048; 
const int deadzone = 300; 

unsigned long buttonPressTime = 0;
bool isPressed = false;

void setup() {
  pinMode(centerBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  bleMouse.begin();
}

void loop() {
  if (bleMouse.isConnected()) {
    int xVal = analogRead(potX);
    int yVal = analogRead(potY);
    bool btnState = (digitalRead(centerBtn) == LOW);

    int moveX = 0, moveY = 0;
    if (abs(xVal - center) > deadzone) moveX = map(xVal, 0, 4095, -12, 12);
    if (abs(yVal - center) > deadzone) moveY = map(yVal, 0, 4095, 12, -12);

    // --- CENTER BUTTON LOGIC ---
    if (btnState) {
      if (!isPressed) {
        buttonPressTime = millis(); // Start timer
        isPressed = true;
      }

      // If stick is moved while button is held -> SCROLL
      if (moveX != 0 || moveY != 0) {
        bleMouse.move(0, 0, moveY, (moveX / 2));
        delay(70); 
      }
    } else {
      if (isPressed) {
        // If button was released quickly (< 200ms) and NOT moved much -> CLICK
        if (millis() - buttonPressTime < 200) {
          bleMouse.click(MOUSE_LEFT);
        }
        isPressed = false;
      }

      // NORMAL MOVEMENT (Only when button NOT pressed)
      if (moveX != 0 || moveY != 0) {
        bleMouse.move(moveX, moveY);
      }
    }

    // --- RIGHT CLICK (External Button) ---
    if (digitalRead(rightBtn) == LOW) {
      if (!bleMouse.isPressed(MOUSE_RIGHT)) bleMouse.press(MOUSE_RIGHT);
    } else {
      if (bleMouse.isPressed(MOUSE_RIGHT)) bleMouse.release(MOUSE_RIGHT);
    }

    delay(10);
  }
}