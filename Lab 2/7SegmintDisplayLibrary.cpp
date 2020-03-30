
void displayNum(int x) {
    // define StartPin
    //define FinishPin

    int a = 0;
    //Define port as output
    DDRC = 0b11111111; // set all port c to output
    for(int i = StartPin; i <= FinishPin; i++) {
        a = x % 10;
        //0
        PORTC = 0b11111100;

        //1
        PORTC = 0b01100000;

        //2
        PORTC = 0b11011010;

        //3
        PORTC = 0b11110010;

        //4
        PORTC = 0b01100110;

        //4
        PORTC = 0b10110110;

        //6
        PORTC = 0b00111110;

        //7
        PORTC = 0b11100000;

        //8
        PORTC = 0b11111110;

        //9
        PORTC = 0b11100110;
        }
}
