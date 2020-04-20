#include <Arduino.h>
#include "RangeFinder.h"

void RangeSetup() {
  //Set PA0 as input
  DDRA=0b00000000;

  /////////// Set up AtoD Converter //////////
  // Set Voltage Reference to 1024 = AVREF = 2.56 --> bit 7, bit 6
  // Left Justify Register Read For Easier Calculations --> bit 5
  // Use PF0 --> bit 4, bit 3, bit 2, bit 1, bit 0
  ADMUX = 0b01100000;

  // Enable AtoD Conversion --> bit 7
  // Start AtoD Conversions --> bit 6
  // Dont Use Auto Trigger --> bit 5
  // Clear Interrupt Flag --> bit 4
  // Enable Interrupts --> bit 3
  // Set pre-scaler to 16 --> bit 2, bit 1, bit0
  ADCSRA = 0b10000100;
}

void RangeFind() {

}
