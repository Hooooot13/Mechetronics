#ifndef PASSWORD_H
#define PASSWORD_H

const int ZeroPin = 0x01; //PIN 49
const int OnePin = 0x02; //PIN 48
const int TwoPin = 0x04; //PIN 47
const int ThreePin =0x08; //PIN 46

int ReadButtonPad();
bool PasswordCheck();

#endif
