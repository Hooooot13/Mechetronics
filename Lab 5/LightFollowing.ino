//This program will follow a light source using a servo motor


int anlge = 0;
const int leftLightSensor = 0x01;
const int centerLightSensor = 0x02;
const int rightLightSensor = 0x04;
void setup() {
    //DDRN = 0b00000111;
    DDRB |= 0x80; //
    DDRC |= 0x00;
    TCCR1A = 0b10000011; //timer 1A1 mode 7
    TCCR1B = 0b00001100; //// choose mode 7 (WGM3 = 0, WGM2 = 1, prescale of 1/256) CS2 = 1 CS1 = 0 CS0 = 0
    OCR1A = 0;
}

void loop() {
    int setAngle = 0;
    while(!(PINC & centerLightSensor)){
        if(PINC & leftLightSensor) {
            setAngle++;
        }
        if(PINC & rightLightSensor) {
            setAngle--;
        }
    }
    Serial.println(i);
}
