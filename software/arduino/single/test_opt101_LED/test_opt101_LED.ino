#include <Wire.h> 
// Set the LCD address to 0x27 for a 16 chars and 2 line display

int sensor = A1;  // output pin of OPT101 attached to Analog 5
int opt_signal;
int LED = 5; // digital pin for LED

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode (LED, OUTPUT); //for cell 1 LED
}

void loop() {
  digitalWrite(LED, LOW);
  delay(500);
  opt_signal = analogRead(sensor);
  Serial.print(opt_signal);
  Serial.print("\n");
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
  opt_signal = analogRead(sensor);
  Serial.print(opt_signal);
  Serial.print("\n");
  delay(500);
}
