#include "CustomServo.h"
#include <Arduino.h>

void OpenDoor() {
  for(int i = 90; i < 130; i++) {
    OCR1A = i;
    Serial.println(i);
    delay(100);
  }

}

void CloseDoor() {
  for(int i = 130; i > 90; i--) {
    OCR1A = i;
    delay(100);
  }
}

void OpenGarage() {
  int BeatHz = 3;
  for(int i = 30; i < 90; i++) {
    OCR1C = i;
    Serial.println(i);
    delay(100);
  }
}

void CloseGarage() {
  for(int i = 90; i > 30; i--) {
    OCR1C = i;
    delay(100);
  }
}
