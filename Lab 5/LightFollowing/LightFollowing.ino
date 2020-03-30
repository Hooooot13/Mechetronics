//This program will follow a light source using a servo motor

int setAngle = 100;
int referanceAngle = 100;
const int leftLightSensor = 0x01;
const int centerLightSensor = 0x02;
const int rightLightSensor = 0x04;
void setup() {
    Serial.begin(9600);
    //DDRN = 0b00000111;
    DDRC |= 0x00;
    DDRB |= 0x80; //PB7 is output other don't matter
    TCCR1A = 0b00001011; //set up timer 1C1 choose mode 7
    TCCR1B = 0b00001100;// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
    OCR1C = setAngle; //Choose a value between 0 and 1023 this is for channle C only channle A is shown in the notes this code is how you set the cycles
}

void loop() {
    while((PINC & centerLightSensor)){
        Serial.println((PINC & leftLightSensor));
        Serial.println((PINC & rightLightSensor));
        if(!(PINC & leftLightSensor)) {// && (setAngle >= 35)) {
            setAngle--;
        }
        if(!(PINC & rightLightSensor)) {// && (setAngle <= 140)) {
            setAngle++;
        }
        if(referanceAngle != setAngle) {
            referanceAngle = setAngle;
            OCR1C = setAngle;
        }
        Serial.println(setAngle);
        delay(2);
    }
}
