#include "CustomServo.h"
#include <Arduino.h>

void OpenDoor() {
  int BeatHz = 3;
  for(int i = 0; i < 150; i++) {
    OCR1A = i;
    delay(25);
  }
  for(int i = 150; i > 0; i--) {
    OCR1A = i;
    delay(25);
  }
}

void OpenGarage() {
  int BeatHz = 3;
  for(int i = 0; i < 150; i++) {
    OCR1C = i;
    delay(7);
  }
  for(int i = 150; i > 0; i--) {
    OCR1C = i;
    delay(7);
  }
}
