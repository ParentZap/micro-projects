#include "Adafruit_Arcada.h"

Adafruit_Arcada arcada;
uint16_t x;
uint16_t y;

void setup() {
  Serial.begin(115200);
  arcada.displayBegin();
  arcada.setBacklight(200);
  arcada.display->fillScreen(ARCADA_BLACK);
  x = 0;
  y = 0;
}

void loop() {
  arcada.readButtons();
  uint8_t buttons = arcada.justPressedButtons();
  int16_t joystick_x = arcada.readJoystickX();
  int16_t joystick_y = arcada.readJoystickY();

  int8_t dx = (int8_t) ((float)joystick_x/512.0*5.0);
  int8_t dy = (int8_t) ((float)joystick_y/512.0*5.0);
  x += dx;
  y += dy;

  Serial.printf("X: %u, Y: %u\n", x, y);
  
  arcada.display->drawRect(x, y, 20, 20, ARCADA_WHITE);
  delay(50);
}
