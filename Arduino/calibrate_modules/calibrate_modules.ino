// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float darksig1 = 0;
float darksig2 = 0;
float darksig3 = 0;
float density1 = 0;  //you can add multiple of these. so if you want to set it up with 10 test tubes, just make refsig1, density1 and result1 and make a counter system.
float density2 = 0;
float density3 = 0;
float total1 = 0;
float total2 = 0;
float total3 = 0;
int prog = 0;
int counter = 0;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode (7, OUTPUT); //for cell 1 LED
  pinMode (8, OUTPUT); //for cell 2 LED
  pinMode (9, OUTPUT); //for cell 3 LED
  lcd.begin(20, 4);
  lcd.print("Measuring...");
  delay(1000); //leave delays for start-up
}

void loop() {
  delay(100);
  counter = 10;
  for (int dummy = 0; dummy < 10; dummy++)
  {
  lcd.clear();
  lcd.print("Measuring...");
  lcd.setCursor(0, 1);
  lcd.print("Starting in: ");
  lcd.print(counter);
  counter = abs(counter - 1);
  delay(1000);
  }
  calibrate1();
  Serial.print('\n'); 
  delay(100);
  lcd.clear();
  lcd.print("Measuring...");
  counter = 20;
  for (int dummy = 0; dummy < 20; dummy++)
  {
  lcd.clear();
  lcd.print("Measuring...");
  lcd.setCursor(0, 1);
  lcd.print("Starting in: ");
  lcd.print(counter);
  counter = abs(counter - 1);
  delay(1000);
  }
  lcd.clear();
  lcd.print("Measuring...");
  calibrate2();
  Serial.print('\n');
  delay(100);
  lcd.clear();
  lcd.print("Measuring...");
  counter = 20;
  for (int dummy = 0; dummy < 20; dummy++)
  {
  lcd.clear();
  lcd.print("Measuring...");
  lcd.setCursor(0, 1);
  lcd.print("Starting in: ");
  lcd.print(counter);
  counter = abs(counter - 1);
  delay(1000);
  }
  lcd.clear();
  lcd.print("Measuring...");
  calibrate3();
  delay(100);
  Serial.print('\n');
  delay(600000);
}

void calibrate1() {
  darksig1 = 0;
  lcd.setCursor(0, 1);
  lcd.print("Calibrating Cell 1");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring dark...");
  delay(1000);
  digitalWrite(7, LOW); //ensures cell 1 LED is off!!!!
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    darksig1 = abs(darksig1 + analogRead(A1));   //for cell 1
    delay(500);
  }
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Dark value: ");
  lcd.print(darksig1);
  delay(10000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring light...");
  
  density1 = 0;
  delay(100);
  digitalWrite(7, HIGH); //turns exp LED on
  delay(100);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    density1 = (density1 + analogRead(A1));
    delay(500);
  }
  delay(1000);
  digitalWrite(7, LOW); //ensures cell 1 LED is off!!!!
  lcd.setCursor(0, 2);
  lcd.print("Light value: ");
  lcd.print(density1);
  total1 = abs(density1 - darksig1);
  delay(1000);
  Serial.print("cell_1");
  Serial.print(',');
  Serial.print(darksig1);
  Serial.print(',');
  Serial.print(density1);
  Serial.print(',');
  Serial.print(total1);
}

void calibrate2() {
  darksig2 = 0;
  lcd.setCursor(0, 1);
  lcd.print("Calibrating Cell 2");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring dark...");
  delay(1000);
  digitalWrite(8, LOW); //ensures cell 2 LED is off!!!!
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    darksig2 = abs(darksig2 + analogRead(A5));   //for cell 1
    delay(500);
  }
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Dark value: ");
  lcd.print(darksig2);
  delay(10000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring light...");
  
  density2 = 0;
  delay(100);
  digitalWrite(8, HIGH); //turns exp LED on
  delay(100);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    density2 = (density2 + analogRead(A5));
    delay(500);
  }
  delay(1000);
  digitalWrite(8, LOW); //ensures cell 1 LED is off!!!!
  lcd.setCursor(0, 2);
  lcd.print("Light value: ");
  lcd.print(density2);
  total2 = abs(density2 - darksig2);
  delay(1000);
  Serial.print("cell_2");
  Serial.print(',');
  Serial.print(darksig2);
  Serial.print(',');
  Serial.print(density2);
  Serial.print(',');
  Serial.print(total2);
}

void calibrate3() {
  darksig3 = 0;
  lcd.setCursor(0, 1);
  lcd.print("Calibrating Cell 3");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring dark...");
  delay(1000);
  digitalWrite(9, LOW); //ensures cell 1 LED is off!!!!
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    darksig3 = abs(darksig3 + analogRead(A3));   //for cell 1
    delay(500);
  }
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Dark value: ");
  lcd.print(darksig3);
  delay(10000);
  lcd.setCursor(0, 2);
  lcd.print("Measuring light...");
  
  density3 = 0;
  delay(100);
  digitalWrite(9, HIGH); //turns exp LED on
  delay(100);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    density3 = (density3 + analogRead(A3));
    delay(500);
  }
  delay(1000);
  digitalWrite(8, LOW); //ensures cell 1 LED is off!!!!
  lcd.setCursor(0, 2);
  lcd.print("Light value: ");
  lcd.print(density3);
  total3 = abs(density3 - darksig3);
  delay(1000);
  Serial.print("cell_3");
  Serial.print(',');
  Serial.print(darksig3);
  Serial.print(',');
  Serial.print(density3);
   Serial.print(',');
  Serial.print(total3);
}

