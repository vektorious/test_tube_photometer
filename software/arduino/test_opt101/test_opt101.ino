#include <Wire.h> 
// Set the LCD address to 0x27 for a 16 chars and 2 line display

int sensor = A1;  // output pin of OPT101 attached to Analog 5
int opt_signal;

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  opt_signal = analogRead(sensor);
  Serial.print(opt_signal);
  Serial.print("\n");
  delay(1000);
}
