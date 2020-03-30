/*
 * Display Ginger Beer Recipe On LCD
 * written by:
 * Joey Franklin and Levi Carroll
 */

#include <LiquidCrystal.h>

// initialize the library by providing LCD pin locations
LiquidCrystal lcd(9,8,7,6,5,4);

void setup(){
  Serial.begin(9600);       // Initialize the Serial
  while (! Serial);       // Wait for Serial to be ready
  Serial.println("Serial is ready"); // print to the Serial port
  //Set LCD Size
  lcd.begin(16,2);
}

void loop(){ 
   
      // Ginger Beer
   Serial.println("Delicious Ginger Beer"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Delicious");
   lcd.setCursor(0,1);
   lcd.print("Ginger Beer");
   delay(6000);  // delay 6000 ms
   lcd.clear();
   
   // Step 1
   Serial.println("Ingredients Needed"); // print to the Serial port
   lcd.setCursor(0,0);
   lcd.write("Ingredients");
   lcd.setCursor(0,1);
   lcd.print("Needed:");
   delay(5000);  // delay 5000 ms
   lcd.clear();

   // Step 2
   Serial.println("4lb of Ginger"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("4 lbs");
   lcd.setCursor(0,1);
   lcd.print("Ginger");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 3
   Serial.println("5lbs of Corn Sugar"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("5 lbs");
   lcd.setCursor(0,1);
   lcd.print("Corn Sugar");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 4
   Serial.println("1 Package of cider yeast"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("1 Package");
   lcd.setCursor(0,1);
   lcd.print("Cider Yeast");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 5
   Serial.println("1 Cup of Lemon Juice"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("1 Cup");
   lcd.setCursor(0,1);
   lcd.print("Lemon Juice");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 6
   Serial.println("5 Gallon Bucket with Brewing Lid"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("5 Gallon");
   lcd.setCursor(0,1);
   lcd.print("Bucket w/");
   delay(1000);  // delay 1000 ms
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.write("Brewing Lid");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 7
   Serial.println("7 Gallon Cooking Pot"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("7 Gallon");
   lcd.setCursor(0,1);
   lcd.print("Pot");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 8
   Serial.println("Fine Mesh Strainer"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Fine Mesh");
   lcd.setCursor(0,1);
   lcd.print("Strainer");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 9
   Serial.println("Sanitizing Solution"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Sanitizing");
   lcd.setCursor(0,1);
   lcd.print("Solution");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 10
   Serial.println("1-Way Valve"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("1-Way");
   lcd.setCursor(0,1);
   lcd.print("Valve");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 11
   Serial.println("Preparation:"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Preparation:");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 12
   Serial.println("Sanitize Everything!"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Sanitize");
   lcd.setCursor(0,1);
   lcd.print("Everything!");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 13
   Serial.println("Boil 5 Gallons of Water in the 7 Gallon Pot"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Boil");
   lcd.setCursor(0,1);
   lcd.print("5 Gallons");
   delay(1000);  // delay 1000 ms
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.write("of Water");
   lcd.setCursor(0,1);
   lcd.print("in the");
   delay(1000);  // delay 1000 ms
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.write("7 Gallon Pot");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 14
   Serial.println("Finely Cut the Ginger"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Finely Cut");
   lcd.setCursor(0,1);
   lcd.print("the Ginger");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 15
   Serial.println("Add Ginger to Water"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Add Ginger");
   lcd.setCursor(0,1);
   lcd.print("to Water");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 16
   Serial.println("Bring to a Low Boil"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Bring to a");
   lcd.setCursor(0,1);
   lcd.print("low boil");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 17
   Serial.println("Let Sit for 1 Hour stirring Occasionally"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Let Sit for");
   lcd.setCursor(0,1);
   lcd.print("1 Hour");
   delay(1000);  // delay 1000 ms
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.write("Stirring");
   lcd.setCursor(0,1);
   lcd.print("Occasionally");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 18
   Serial.println("Dissolve Sugar"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Dissolve");
   lcd.setCursor(0,1);
   lcd.print("Sugar");
   delay(1000);  // delay 1000 ms
   lcd.clear();   // Step 2
   Serial.println("in the Mixture"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("in the");
   lcd.setCursor(0,1);
   lcd.print("Mixture");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 19
   Serial.println("Let it Cool"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Let it Cool!");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 20
   Serial.println("Strain Mixture"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Strain");
   lcd.setCursor(0,1);
   lcd.print("Mixture");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 21
   Serial.println("Add Prepped Yeast"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("4 lbs");
   lcd.setCursor(0,1);
   lcd.print("Ginger");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 22
   Serial.println("Place Lid on Bucket"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Place Lid");
   lcd.setCursor(0,1);
   lcd.print("on Bucket");
   delay(5000);  // delay 5000 ms
   lcd.clear();

      // Step 23
   Serial.println("Let it Ferment"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("Let it");
   lcd.setCursor(0,1);
   lcd.print("Ferment");
   delay(1000);  // delay 1000 ms
   lcd.clear();
   Serial.println("for 1 MONTH"); // print to the serial port
   lcd.setCursor(0,0);
   lcd.write("for");
   lcd.setCursor(0,1);
   lcd.print("1 MONTH");
   delay(5000);  // delay 5000 ms
   lcd.clear();
   
}
