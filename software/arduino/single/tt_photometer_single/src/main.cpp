// Version 1.3 of the test tube photometer software
// It ignores possible disturbing light by neglecting the "dark values"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
// adjust first parameter to the I2C address of your LCD. Check it via the I2C scanner
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Input/Output
int sensor = A1;  // input pin of OPT101 attached to Analog 1
int buttonBlank = 9; // input pin for blank button
int buttonMeasure = 10; // input pin for measure button
int LED = 8; // output pin for blank button

// Variables
float opt_signal;
float OD = 0;
int blank = 0;
float blankValue = 0;
int measure = 0;

// Add factor from calibration curve to calculate concentration
int factor = 0;

bool trouble = false;
bool blanked = false;

// Function for "Blank" measurements
void measureBlank(int multiplier) { // multiplier determines how many measurements are pooled
  blankValue = 0;
  
  for (int dummy = 0; dummy < multiplier; dummy++){
    delay(100);
    blankValue = (blankValue + analogRead(sensor));
    delay(100);
  }
  
  blankValue = blankValue/multiplier;
  blanked = true;
}

// Function for OD measurements
void measureOD(int multiplier) { // multiplier determines how many measurements are pooled
  opt_signal = 0;

  for (int dummy = 0; dummy < multiplier; dummy++){
    delay(100);
    opt_signal = (opt_signal + analogRead(sensor));
    delay(100);
  }

  if (blanked == true){ // output of OD if blanked
    opt_signal = opt_signal/multiplier;
    OD = -log10(opt_signal/blankValue);
    if(factor =! 0){
      OD = OD*factor;
    }
  }

  else{ // output of the raw value if not blanked
    OD = opt_signal/multiplier;
  }
}

// Start loop
void setup() {

  delay(100);

  // Turn on the blacklight and print a message.
  lcd.begin();
  lcd.backlight();
  lcd.print("   Test  Tube    ");
  lcd.setCursor(0, 1);
  lcd.print("Photometer  v1.3");

  pinMode (LED, OUTPUT); //for LED
  pinMode(buttonBlank, INPUT_PULLUP);
  pinMode(buttonMeasure, INPUT_PULLUP);
  delay(1000);
  lcd.clear();

  // If any button is pressed during the startup, troubleshooting mode is activated.
  // (LED is always on & raw value output) 
  for (int i = 0; i < 10; i++){
    lcd.setCursor(0, 0);
    lcd.print("Starting ... ");
    lcd.print(i);
    measure = digitalRead(buttonMeasure);
    blank = digitalRead(buttonBlank);
    delay(500);
    if (measure == LOW || blank == LOW){
      trouble = true;
      lcd.clear();
      lcd.print("Troubleshooting");
      lcd.setCursor(0, 1);
      lcd.print("Mode");
      delay(1000);
      break;
    }
  }
  
  lcd.clear();
  lcd.print("Press Button");
  lcd.setCursor(0, 1);
  lcd.print("to start :)");
}

// Main loop
void loop() {
  measure = digitalRead(buttonMeasure);
  blank = digitalRead(buttonBlank);

  // troubleshooting mode
  if (trouble == true){
    lcd.clear();
    lcd.print("Showing raw signal ...");
    lcd.setCursor(0, 1);
    digitalWrite(LED, HIGH);
    delay(100);
    lcd.print(analogRead(sensor));
    delay(500);
  }

  // measuring blank
  else if(blank == LOW){
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
  
  // measuring sample
  else if(measure == LOW){
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

    if (factor =! 0){
      lcd.print(" g/L");
    }

    else if(blanked == false){
      lcd.print(" raw value");
    }
  }
}