#include <LiquidCrystal.h>
//Were going to write a recipe for a delicious ginger beer
//Prep Time 5 Hours
//Cooke time 576 Hours
//Rest time 120 hours

//setup the LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Build Functions
void LCDTimer(long int);

void setup() {
    Serial.begin(9600);
    while(! Serial);
    Serial.println("Serial Is Ready");
    lcd.begin(16,2);
    lcd.print("Start Serial Monitor");
    LCDTimer(60);
}

void loop() {
//Title of the recipe
    //The Big Snap Ginger Beer

//List of ingredients
    Serial.println("Make Sure you have all these ingredients before you start");
    //4lb of Ginger
    Serial.println("* 4lb of Ginger");
    //5lb of corn sugar
    Serial.println("* 5lb of corn sugar");
    //1 pack Cider Yeast
    Serial.println("* 1 pack Cider Yeast");
    //1 cup lemon juice
    Serial.println("* 1 cup lemon juice");
    //1 food grade 5 gallon bucket
    Serial.println("* 5 Gallon bucket with a brewing lid (Food Grade)");
    //1 7 gallon cooking pot
    Serial.println("* 7 Gallon Cooking Pot");
    //1 Fine mesh strainer
    Serial.println("* Fine mesh strainer");
    //Sanatizing solution
    Serial.println("* Sanatizing solution (Food Grade)");
    //one way valve
    Serial.println("* One way valve");
    //Lots of patients
    Serial.println("* Lots Of Patients");
    lcd.setCursor(0,0);
//Preparations
    //Sanatize
    Serial.println("0. Sanatize everything.");

    //boil water
    Serial.println("1. Boil about 5 gallons of water");
    Serial.println("    in the 7 gallon pot.");
    Serial.println("");

    Serial.println("While the water is heating up ...");
    Serial.println("");

    //cut ginger
    Serial.println("2. Chop the ginger into small chucks.");
    Serial.println("    You can use a blender if");
    Serial.println("    you have one.");
    Serial.println("");

    //add ginger to water
    Serial.println("3. Add the ginger to the water");
    Serial.println("");

    //let sit for 1 hours
    Serial.println("4. Bring the water to a low boil");
    Serial.println("    and let sit for 1 hour.");
    Serial.println(" ");

    Serial.println("Make sure to stir the pot occationally ...");
    Serial.println("");

    //add sugar to brew mix
    Serial.println("5. Pour the sugar into the wart.");
    Serial.println("    Take your time and keep stiring to");
    Serial.println("    make sure all the sugar dissolves.");
    Serial.println("");

    // cool down the brew
    Serial.println("6. Turn off the burner and let the");
    Serial.println("    ginger wart cool down to around");
    Serial.println("    room temperatur. This will take");
    Serial.println("    Several hours.");
    Serial.println("");

    Serial.println("If your impaitent then you can move");
    Serial.println("    on when the wart gets to around");
    Serial.println("    100 degreed Fahrenheit. (~40 Celsius)");
    Serial.println("There is also a specialized tool for");
    Serial.println("    this called a cooling coil that will");
    Serial.println("    reduce the cooling time to about");
    Serial.println("    15 minutes.");
    Serial.println("");

    //pour into brew bucket
        //strain ginger as you do
    Serial.println("7. Now you'll need to strain out the");
    Serial.println("    ginger from the wart and pour it");
    Serial.println("    into the brew bucket.");
    Serial.println("");

    //Prepare the yeast solution
    Serial.println("8. Prepare the yeast following whatever");
    Serial.println("    instructions are on the package.");
    Serial.println("");

    Serial.println("9. Add the yeast to the cooled wart and");
    Serial.println("    place the lid on the bucket with");
    Serial.println("    the one way valve secured.");
    Serial.println("");

    Serial.println("You should look up how exactly to use");
    Serial.println("    whatever type of one way valve you");
    Serial.println("    bought.");
    Serial.println("");

    Serial.println("10. Wait a month while it fermints");
    Serial.println("");

    Serial.println("11. After this step you'll have to carbonate it.");
    Serial.println("    There are like 6 different ways to do this");
    Serial.println("    so you can figure it out for your self.");
    Serial.println("");

    //run the timer for every
    lcd.setCursor(0,0);
    lcd.print("Get ingredients");
    LCDTimer(200);

    lcd.setCursor(0,0);
    lcd.print("Step 0-6");
    LCDTimer(4000);

    lcd.setCursor(0,0);
    lcd.print("Step 6");
    LCDTimer(2000);

    lcd.setCursor(0,0);
    lcd.print("Step 7-11");
    LCDTimer(1728000);

}


void LCDTimer (long int DelayTime) {
    for (int i = 0;i <= DelayTime;i++){
        lcd.setCursor(0,1);
        lcd.print("                 ");
        lcd.setCursor(0,1);
        lcd.print(DelayTime - i);
        delay(1000);
    }


}
