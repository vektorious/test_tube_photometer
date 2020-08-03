//Version 1.1 of the test tube photometer software
//It ignores possible disturbing light by neglecting the "dark values"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2); // adjust first parameter to the I2C address of your LCD. Check it via the I2C scanner

int sensor = A1;  // output pin of OPT101 attached to Analog 5
float opt_signal;
float OD = 0;
int LED = 8;
int buttonBlank = 9;
int buttonMeasure = 10;

int blank = 0;
float blankValue = 0;
bool blanked = false;
int measure = 0;

void measureBlank(int multiplier) {

  blankValue = 0;
  
  for (int dummy = 0; dummy < multiplier; dummy++)
  {
    delay(100);
    blankValue = (blankValue + analogRead(sensor));
    delay(100);
  }
  blanked = true;
}

void measureOD(int multiplier) {

  opt_signal = 0;

  for (int dummy = 0; dummy < multiplier; dummy++)
  {
    delay(100);
    opt_signal = (opt_signal + analogRead(sensor));
    delay(100);
  }

  if(blanked == true){
    OD = -log10(opt_signal/blankValue);
  }

  else{
    OD = opt_signal/multiplier;
  }
}

void setup() {

  delay(100);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("   Test  Tube    ");
  lcd.setCursor(0, 1);
  lcd.print("Photometer  v1.2");
  pinMode (LED, OUTPUT); //for LED
  pinMode(buttonBlank, INPUT_PULLUP);
  pinMode(buttonMeasure, INPUT_PULLUP);
  delay(1000);
}

void loop() {
  measure = digitalRead(buttonMeasure);
  blank = digitalRead(buttonBlank);

  if(blank == LOW){
    lcd.clear();
    lcd.print("Measuring Blank ...");
    lcd.setCursor(0, 1);
    lcd.print("Please wait");
    digitalWrite(LED, HIGH);
    delay(500);
    measureBlank(10);
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Blanked");
  }
  
  if(measure == LOW){
    lcd.clear();
    lcd.print("Measuring OD ...");
    lcd.setCursor(0, 1);
    lcd.print("Please wait");
    digitalWrite(LED, HIGH);
    delay(500);
    measureOD(10);
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(OD);
    if(blanked == false){
      lcd.print("raw value");
    }
  }

  if (blanked == false)
  {
    lcd.clear();
    lcd.print("Showing raw signal ...");
    lcd.setCursor(0, 1);
    digitalWrite(LED, HIGH);
    delay(100);
    lcd.print(analogRead(sensor));
    delay(500);
  }
  
}



