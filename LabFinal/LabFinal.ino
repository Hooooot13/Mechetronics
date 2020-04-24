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
#include "Password.h"

const float ProximityDistance = 7; //cm

void setup() {
  Serial.begin(9600);
  DDRL=0b00000000;

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


  DDRB |= 0xFF; //PB7 is output other don't matter
  TCCR1A = 0b10001011; //set up timer 1C1 choose mode 7
  //TCCR1A = 0b00001011;
  TCCR1B = 0b00001100;// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
  OCR1A = StartingAngleServo1; //Choose a value between 0 and 1023 this is for channle C only channle A is shown in the notes this code is how you set the cycles
  OCR1C = StartingAngleServo2;


}

void loop() {
  //SetActivation pin for Password
  if(PINL & ZeroPin){
    //enter Password
    if(PasswordCheck() == true){
      //if password is correct open door
      MoveServo1();
      //Print to lcd
    }
    else //else do not open door and print to lcd
  }
  if(RangeFind() < ProximityDistance) {//if proximity is < x open the garage
    OpenGarage();
    //run a timer then close the door
  }


}
