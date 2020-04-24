#include <Arduino.h>
#include "Password.h"

int ReadButtonPad() {
  PORTL = 0x00;
      while(true){
          //0
          if(PINL & ZeroPin) {
              Serial.println(0);
              delay(300);
              return 0;
          }
          //1
          if(PINL & OnePin) {
              Serial.println(1);
              delay(300);
              return 1;
          }
          //2
          if(PINL & TwoPin) {
              Serial.println(2);
              delay(300);
              return 2;
          }
          //3
          if(PINL & ThreePin) {
              Serial.println(3);
              delay(300);
              return 3;
          }
      }
  }

  bool PasswordCheck() {
      int correct = 0;
      int input[4] = {33, 33, 33, 33};
      //set password Array
      int password[4] = {0, 1, 2, 3};

      //Ask user for password
    //  lcd.setCursor(0,0);
      //lcd.write("Enter Password");
      //lcd.setCursor(0,1);

      for(int i = 0; i < 4; i++) {
          input[i] = ReadButtonPad();
          //lcd.print(input[i]);
          if(input[i] == password[i]){
              correct++;
          }
      }
      if(correct != 4) {
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
