#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // adjust first parameter to the I2C address of your LCD. Check it via the I2C scanner


int sensor = A1;  // output pin of OPT101 attached to Analog 5
int opt_signal;
int LED = 5;

void setup() {
  Serial.begin(9600);
  delay(100);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Measuring OD");
  
  pinMode (LED, OUTPUT); //for LED
}

void loop() {
  opt_signal = analogRead(sensor);
  delay(1000);

  Serial.print(opt_signal);
  Serial.print("\n");
  digitalWrite(LED, HIGH); // alternating LED on and off

  lcd.setCursor(0, 1);
  lcd.print(opt_signal);
  lcd.print(" alexunits");

}
