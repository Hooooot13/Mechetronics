//Mechatronics Exam Reference Sheet

//serial
Serial.begin(9600);
Serial.print("String");
Seriak.println("String");


//LCD
#include <LiquidCrystal.h>
//setup the LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
lcd.begin(16,2);
lcd.setCursor(0,0); //top line
lcd.setCursor(0,1); // bottom line
lcd.print("Print this string");
lcd.print(integer);
lcd.clear();

//Ports
DDRn = 0x01; //First 4 bits are input last 4 bits are outputs
if(PINn & PinValue) {//check a button
    //task here
}

//using a timer for PWM
DDRB |= 0x80; //PB7 is output other don't matter
TCCR1A = 0b00001011; //set up timer 1C1 choose mode 7
TCCR1B = 0b00001100;// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
OCR1C = setAngle; //Choose a value between 0 and 1023 this is for channle C only channle A is shown in the notes this code is how you set the cycles
