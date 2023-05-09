/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
LCD software*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 
}
void loop() {  
  lcd.setCursor(0, 0);   // print the number of seconds since reset:
  lcd.print("Speed of vechile =");
   lcd.setCursor(2,1); 
 lcd.print("???????? cm/s");
  
}
