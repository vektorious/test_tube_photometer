#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // adjust first parameter to the I2C address of your LCD. Check it via the I2C scanner


int sensor = A1;  // output pin of OPT101 attached to Analog 5
int opt_signal;
int LED = 5;
int buttonBlank = 12;
int buttonMeasure = 13;

int blank = 0;
int blanked = 0;
int measure = 0;

void setup() {
  Serial.begin(9600);
  delay(100);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Measuring OD");
  
  pinMode (LED, OUTPUT); //for LED
  pinMode(buttonBlank, INPUT);
  pinMode(buttonMeasure, INPUT);
}

void loop() {
  opt_signal = analogRead(sensor);
  measure = digitalRead(buttonMeasure);
  blank = digitalRead(buttonBlank);
  delay(1000);

  if (measure == HIGH){
    Serial.print("Measure was pressed");
    Serial.print("\n");
  }

    if (blank == HIGH){
    Serial.print("Blank was pressed");
    Serial.print("\n");
  }
  
  Serial.print(opt_signal);
  Serial.print("\n");
  digitalWrite(LED, !digitalRead(LED)); // alternating LED on and off

  lcd.setCursor(0, 1);
  lcd.print(opt_signal);
  lcd.print(" alexunits");

}
