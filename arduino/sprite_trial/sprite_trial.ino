#include <cstdlib>
#include "Adafruit_Arcada.h"
#include "ArduinoSTL.h"

Adafruit_Arcada arcada;
uint16_t x;
uint16_t y;
//std::vector<std::tuple<uint16_t, uint16_t, uint16_t, uint16_t>> dirty_rects;
//std::vector<int> my_vec;

void setup() {
  Serial.begin(115200);
  arcada.displayBegin();
  arcada.setBacklight(200);
  arcada.display->fillScreen(ARCADA_BLACK);
  x = 0;
  y = 0;
}

void update() {
  arcada.readButtons();
  uint8_t buttons = arcada.justPressedButtons();
  int16_t joystick_x = arcada.readJoystickX();
  int16_t joystick_y = arcada.readJoystickY();

  int8_t dx = (int8_t) ((float)joystick_x/512.0*5.0);
  int8_t dy = (int8_t) ((float)joystick_y/512.0*5.0);
  x += dx;
  y += dy;
}

void clean_dirty_rects() {
//  for (int i = 0; i < dirty_rects.size(); i++) {
//    std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> dirty_rect = dirty_rects[i];
//    arcada.display->fillRect(dirty_rect[0], dirty_rect[1], dirty_rect[2], dirty_rect[3], ARCADA_BLACK);
//  }
//  dirty_rects.clear();
}

void draw() {
  Serial.printf("X: %u, Y: %u\n", x, y);
  arcada.display->fillRect(x, y, 20, 20, ARCADA_WHITE);
}

void loop() {
  clean_dirty_rects();
  update();
  draw();
  
  delay(50);
}
