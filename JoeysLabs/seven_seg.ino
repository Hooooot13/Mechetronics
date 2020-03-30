/****************************************************************
 *   ECE4370 - Mechatronics                                     *
 *   Dr. Stephen Canfield                                       *
 *   LAB 2:                                                     *
 *  Display an electronic recipe with a timer display on the    *
 *  7 segment display                                           *
 *                                                              *
 * Written by: Joey Franklin                                    *
 *        and  Levi Carroll                                     *
 ***************************************************************/
#include <LiquidCrystal.h>

// initialize the library by providing LCD pin locations
LiquidCrystal lcd(8,9,7,6,5,4);

// Function for 7 segment timer
void counter(int timer);

// bits representing segments A through G (and decimal point) for numerals 0-9
//empty,A,B,C,D,E,F,G
const byte digit[10] = {
0b1111110, // 0
0b0110000, // 1
0b1101101, // 2
0b1111001, // 3
0b0110011, // 4
0b1011011, // 5
0b0011111, // 6
0b1110000, // 7
0b1111111, // 8
0b1110011};// 9

//Port C for each 7 segment display
// Low will turn that segment off
const byte num_disp[4] = {
0b00001110,  // PA0--> segment 1
0b00001101,  // PA1--> segment 2
0b00001011,  // PA2--> segment 3
0b00000111}; // PA3--> segment 4

// Variables to hold value in ones,
// tens, hundreds, and thousands place
int ones = 0;
int tens = 0;
int hund = 0;
int thou = 0;
 
void setup() {
  // put your setup code here, to run once:
  // Initialize the Serial
  Serial.begin(9600);
  // Wait for Serial to be ready
  while (! Serial);
  // print to the Serial port
  Serial.println("Serial is ready");
  //Set LCD Size
  lcd.begin(16,2);

  //Set porta and portc as outputs
  DDRA=0b11111111;
  DDRC=0b11111111;

}

void loop() { 
  // put your main code here, to run repeatedly:

    // Ginger Beer
    // print to the serial port
   Serial.println("Delicious Ginger Beer");
   // print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Delicious");
   lcd.setCursor(0,1);
   lcd.print("Ginger Beer");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();
   
   // Step 1
    // print to the Serial port
   Serial.println("Ingredients Needed");
    // print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Ingredients");
   lcd.setCursor(0,1);
   lcd.print("Needed:");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 2
   // Print to the serial port
   Serial.println("4lb of Ginger"); // print to the serial port
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("4 lbs Ginger");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 3
   // Print to the Serial Port 
   Serial.println("5lbs of Corn Sugar");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("5 lbs Corn Sugar");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 4
   // Print to the Serial Port
   Serial.println("1 Package of cider yeast");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("1 Package");
   lcd.setCursor(0,1);
   lcd.print("Cider Yeast");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

    // Step 5
    //Print to the Serial Port
   Serial.println("1 Cup of Lemon Juice");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("1 Cup Lemon");
   lcd.setCursor(0,1);
   lcd.print("Juice");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

    // Step 6
    // Print to the Serial Port
   Serial.println("5 Gallon Bucket with Brewing Lid");
   // Print to LCD
   lcd.setCursor(0,0);
   lcd.write("5 Gallon Bucket");
   lcd.setCursor(0,1);
   lcd.print("w/ Brewing Lid");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 7
   // Print to the serial port
   Serial.println("7 Gallon Cooking Pot");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("7 Gallon Pot");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 8
   // Print to the Serial Port
   Serial.println("Fine Mesh Strainer");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Fine Mesh");
   lcd.setCursor(0,1);
   lcd.print("Strainer");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 9
   // Print to the Serial Port
   Serial.println("Sanitizing Solution");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Sanitizing");
   lcd.setCursor(0,1);
   lcd.print("Solution");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 10
   // Print to the Serial Port
   Serial.println("1-Way Valve");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("1-Way Valve");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 11
   // Print to the Serial Port
   Serial.println("Preparation:");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Preparation:");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 12
   // Print to the Serial Port
   Serial.println("Sanitize Everything!");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Sanitize");
   lcd.setCursor(0,1);
   lcd.print("Everything!");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 13
   // Print to the Serial Port
   Serial.println("Boil 5 Gallons of Water in the 7 Gallon Pot");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Boil 5 Gallons of");
   lcd.setCursor(0,1);
   lcd.print("Water in the Pot");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 14
   // Print to the Serial Port
   Serial.println("Finely Cut the Ginger");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Fine Cut Ginger");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 15
   // Print to the Serial Port
   Serial.println("Add Ginger to Water");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Add Ginger");
   lcd.setCursor(0,1);
   lcd.print("to Water");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 16
   // Print to the Serial Port
   Serial.println("Bring to a Low Boil");
   // Print to LCD
   lcd.setCursor(0,0);
   lcd.write("Bring to a");
   lcd.setCursor(0,1);
   lcd.print("low boil");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 17
   // Print to the Serial Port
   Serial.println("Let Sit for 1 Hour stirring Occasionally");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Let Sit for Hour");
   lcd.setCursor(0,1);
   lcd.print("and stir a bit");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 18
   // Print to the Serial Port
   Serial.println("Dissolve Sugar in the Mixture");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Dissolve Sugar");
   lcd.setCursor(0,1);
   lcd.print("in the Mixture");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 19
   // Print to the Serial Port
   Serial.println("Let it Cool");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Let it Cool!");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 20
   // Print to the Serial Port
   Serial.println("Strain Mixture");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Strain Mixture");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 21
   // Print to the Serial Port
   Serial.println("Add Prepped Yeast");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Add Prepped");
   lcd.setCursor(0,1);
   lcd.print("Yeast");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 22
   // Print to the Serial Port
   Serial.println("Place Lid on Bucket");
   // Print to the LCD
   lcd.setCursor(0,0);
   lcd.write("Place Lid");
   lcd.setCursor(0,1);
   lcd.print("on Bucket");
   // delay in seconds with countdown
   counter(5);
   lcd.clear();

   // Step 23
   // Print to the Serial Port
   Serial.println("Let it Ferment");
   lcd.setCursor(0,0);
   lcd.write("Let it Ferment");
   lcd.setCursor(0,1);
   lcd.print("For 1 Month!");
   // delay in seconds with countdown
   counter(9999);
   lcd.clear();

}

/**************************************
 * Function Name: Counter             *
 * Revieves a number to display       *
 * for 1 second on a countdown timer  *
 * Written By: Joey Franklin          *
 **************************************/
 void counter(int timer){
  for(int i =timer; i >= 0; i--){

      // find value in each of the four positions
      thou = (i/1000)%10;
      hund = (i/100)%10;
      tens = (i/10)%10;
      ones = i%10;
      
      // run through loop to display each number for 1 second (20*50msec=1sec)
      for(int j=0; j<50; j++){
        PORTA=digit[thou];
        PORTC=num_disp[3];
        delay(5);
      
        PORTA=digit[hund];
        PORTC=num_disp[2];
        delay(5);
      
        PORTA=digit[tens];
        PORTC=num_disp[1];
        delay(5);
    
        PORTA=digit[ones];
        PORTC=num_disp[0];
        delay(5);
      }
  }
  }
