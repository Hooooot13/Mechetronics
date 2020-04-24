/*
Proposal for a Music Box Like device with two separately timed beats and Pezo Electric
Toners. We will use the various analog input to set the beat and tone of the devices.
- 2 sensors
  - Encoder knob
  - PWM
  - Timer counter
  - (Optional) Joystick
- 2 actuators
  - 2 motors
  - PWM
  - HMI
  - LCD
  - (Optional) 8x8 LED display
- Other Inputs
  - 4 buttons
- Required functionalities
  - ADC
  - Timer counter
  - PWM
  - LCD display
*/

#include "RangeFinder.h"
#include "CustomServo.h"




void setup() {
  Serial.begin(9600);
  //RangeSetup();
  SetupServo1();
  //Set PA0 as input
}

void loop() {
  //Serial.println(RangeFind());
  //MoveServo1();
  //MoveServo2();
  // delay(1000);
}
