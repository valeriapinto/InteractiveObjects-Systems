/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lightPin = 0; // A0
int lightReading;

void setup() {

  Serial.begin(9600);
//   set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
//   Print a message to the LCD.
  lcd.print("Your fortune");
  lcd.setCursor(0, 1);
  lcd.print("awaits!");
  delay(1200);
}

void loop() {

     // amount of light read
    lightReading = analogRead(lightPin);
     
    // these are the different readings of light
    if (lightReading < 350) { // dark
        lcd.clear();
      Serial.println("Life"); 
         lcd.setCursor(0, 0);
         lcd.print("Change is coming");
          delay(1000);
      
    } else if (lightReading < 600) { // dim
        lcd.clear();
        Serial.println("Love");
         lcd.setCursor(0, 0);
         lcd.print("Love is like war");
         delay(1000);
         
    } else if (lightReading < 650) { // light
        lcd.clear();
      Serial.println("Money");
        lcd.setCursor(0, 0);
        lcd.print("Spend less than");
        lcd.setCursor(0, 1);
        lcd.print("you make...");
        delay(1000);
       
        
    } else if (lightReading < 970) { // bright (standard)
          lcd.clear();
      Serial.println("Standard");
        lcd.setCursor(0, 0);
        lcd.print("Your fortune");
        lcd.setCursor(0, 1);
        lcd.print("awaits!");
        delay(1200);
// 
        
    } else {
      Serial.println("Very_Bright"); // very bright (will ask for flashlight for the audience cause everyone wants their future to be bright!)
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Good things are");
      lcd.setCursor(0, 1);
      lcd.print("coming your way");
      delay(1000);

    }
}
