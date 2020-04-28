/*
Automated home entry system. The system will require a password then automatically open the front door of a model house. This system will also actuate a garage door which opens when it is read by the proximity sensor.
*/

#include "RangeFinder.h"
#include "CustomServo.h"
#include "Password.h"
#include <LiquidCrystal.h>

// initialize the library by providing LCD pin locations
LiquidCrystal lcd(8,9,7,6,5,4);

const float ProximityDistance = 9; //cm
float Distance = 0;
bool FrontDoorOpen = false;
bool GarageDoorOpen = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
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


  DDRB |= 0xFF; //PB7 and PB5 is output other don't matter
  TCCR1A = 0b10001011; //set up timer 1C1 choose mode 7
  //TCCR1A = 0b00001011;
  TCCR1B = 0b00001100;// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
  OCR1A = StartingAngleServo1; //Choose a value between 0 and 1023 this is for channle C only channle A is shown in the notes this code is how you set the cycles
  OCR1C = StartingAngleServo2;

}

void loop() {

  if(FrontDoorOpen == false) {
    lcd.setCursor(0,0);
    lcd.print("Press Pad to");
    lcd.setCursor(0,1);
    lcd.print("enter code");

    if(PINL & ZeroPin) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Code");
      lcd.setCursor(0,1);
      delay(300);
      if(PasswordCheck() == true) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Welcome Home");
        lcd.setCursor(0,1);
        lcd.print("Press 0 to close");
        FrontDoorOpen = true;
        OpenDoor();
      }
      else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Wrong");
        delay(1000);
      }
    }
  }
  else {
    if(PINL & ZeroPin) {
      FrontDoorOpen = false;
      CloseDoor();
    }
  }


  if(GarageDoorOpen == false) {
    if(RangeFind() < ProximityDistance) {
      GarageDoorOpen = true;
      OpenGarage();
      delay(3000);
    }
  }
  if((GarageDoorOpen == true) && (RangeFind() > float(12))){
    GarageDoorOpen = false;
    CloseGarage();
  }
}
