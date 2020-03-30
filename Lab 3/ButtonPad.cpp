//#include "ButtonPad.h"
//#include "Arduino.h"
//#include <LiquidCrystal.h>
#include "Libraries.h"

//This code will lay out the function that read the input from the 12 diget button pad

//When invoced this function will wait for the input from a button pin before returning
int ReadButtonPad() {
    while(true){
        //0
        if(PINL & ZeroPin) {
            delay(300);
            return 0;
        }
        //1
        if(PINL & OnePin) {
            delay(300);
            return 1;
        }
        //2
        if(PINL & TwoPin) {
            delay(300);
            return 2;
        }
        //3
        if(PINL & ThreePin) {
            delay(300);
            return 3;
        }
        //4
/*        if(PORTL & FourPin) {
            delay(100);
            return 4;
        }
        //5
        if(PORTL & FivePin) {
            delay(100);
            return 4;
        }
        //6
        if(PORTL & SixPin) {
            delay(100);
            return 6;
        }
        //7
        if(PORTL & SevenPin) {
            delay(100);
            return 7;
        }
        //8
        if(PORTL & EightPin) {
            delay(100);
            return 8;
        }
        //9
        if(PORTL & NinePin) {
            delay(100);
            return 9;
        }
        //#
        if(PORTL & PoundPin) {
            delay(100);
            return #;
        }
        //*
        if(PORTL & StarPin) {
            delay(100);
            return *;
        }*/
    }
}

bool PasswordCheck() {
    //set password Array
    int correct = 0;
    int input[4] = {33, 33, 33, 33};
    int password[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        input[i] = ReadButtonPad();
        lcd.print(input[i]);
        if(input[i] == password[i]){
            correct++;
        }
    }
    if(correct < 4) {
        Serial.println("Wrong");
        //Serial.print(input);
        return false;
    }
    else if(correct == 4){
        Serial.println("Correct");
        //Serial.print(input);
        return true;
    }
}
