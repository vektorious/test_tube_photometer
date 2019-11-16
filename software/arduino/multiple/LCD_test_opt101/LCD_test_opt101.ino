
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sense = A1;  // output pin of OPT101 attached to Analog 0
int val = 0 ;  
int sense1 = A2;  // output pin of OPT101 attached to Analog 0
int val1 = 0 ;
int sense2 = A3;  // output pin of OPT101 attached to Analog 0
int val2 = 0 ;    

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("Measuring...");
}

void loop() {
  val = analogRead(sense);
  delay(1000);
  val1 = analogRead(sense1);
  delay(1000);
  val2 = analogRead(sense2);
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(val);
  lcd.print(" alexunits ");
  lcd.setCursor(0, 2);
  // print the number of seconds since reset:
  lcd.print(val1);
  lcd.print(" alexunits ");
  lcd.setCursor(0, 3);
  // print the number of seconds since reset:
  lcd.print(val2);
  lcd.print(" alexunits ");
}
