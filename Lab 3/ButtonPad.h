#ifndef BUTTON_PAD_H
#define BUTTON_PAD_H

//Initalize the ports for input

//Define the pin values so they can be changes easily
const int ZeroPin = 0x01; //PIN 49
const int OnePin = 0x02; //PIN 48
const int TwoPin = 0x04; //PIN 47
const int ThreePin =0x08; //PIN 46
const int FourPin = 0x21; //PIN 45
const int FivePin = 0x22; //PIN 44
const int SixPin = 0x24; //PIN 43
const int SevenPin = 0x41; //PIN 42
const int EightPin = 0x42; //PIN 22
const int NinePin = 0x44; //PIN 23
const int PoundPin = 0x84; //PIN 24
const int StarPin = 0x81; //PIN 25

//define the function
    int ReadButtonPad();
    bool PasswordCheck();
#endif
