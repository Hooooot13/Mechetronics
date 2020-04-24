#include "CustomServo.h"
#include <Arduino.h>

void SetupServo1() {
  int setAngle = 0;
  DDRB |= 0xFF; //PB7 is output other don't matter
  TCCR1A = 0b10001011; //set up timer 1C1 choose mode 7
  //TCCR1A = 0b00001011;
  TCCR1B = 0b00001100;// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
  OCR1A = setAngle; //Choose a value between 0 and 1023 this is for channle C only channle A is shown in the notes this code is how you set the cycles
}


void MoveServo1() {
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

void MoveServo2() {
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
