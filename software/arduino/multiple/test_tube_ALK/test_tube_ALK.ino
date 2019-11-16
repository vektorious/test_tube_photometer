float darksig1 = 0;
float darksig2 = 0;
float darksig3 = 0;
float refsig = 0;  //you can add multiple of these. so if you want to set it up with 10 test tubes, just make refsig1, density1 and result1 and make a counter system.
float density1 = 0;
float density2 = 0;
int prog = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode (7, OUTPUT); //for blank LED
  pinMode (8, OUTPUT); //for sample 1 LED
  pinMode (9, OUTPUT); //for sample 2 LED
  delay(1000); //leave delays for start-up
}

void loop() {
  delay(1000);
  dark(); 
  delay(1000);
  ref();
  delay(1000);
  dens();
  delay(1000);
  Serial.print('\n');
  delay(600000);
}

void dark() {
  darksig1 = 0;
  darksig2 = 0;
  darksig3 = 0;
  delay(1000);
  digitalWrite(7, LOW); //ensures blank LED off!!!!
  digitalWrite(8, LOW); //ensures sample 1 LED off!!!!
  digitalWrite(9, LOW); //ensures sample 2 LED off!!!!
  delay(1000);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    darksig1 = abs(darksig1 + analogRead(A1));   //for blank test tube
    delay(500);
    darksig2 = abs(darksig2 + analogRead(A5));   //for sample 1 test tube
    delay(500);
    darksig3 = abs(darksig3 + analogRead(A3));   //for sample 2 test tube
    delay(500);
  }
  delay(100);
}

void ref() {
  refsig = 0;
  delay(1000);
  digitalWrite(7, HIGH); //turns blank LED on
  delay(1000);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    refsig = abs(refsig + analogRead(A1));   //have a blank test tube for the set up (A1), and all experimental tubes on other pins.
    delay(500);
  }
  digitalWrite(7, LOW); //ensures blank LED off!!!!
  delay(100);
}

void dens() {
  density1 = 0;
  density2 = 0;
  delay(1000);
  digitalWrite(8, HIGH); //turns exp LED on
  digitalWrite(9, HIGH); //turns exp LED on
  delay(1000);
  for (int dummy = 0; dummy < 100; dummy++)
  {
    delay(500);
    density1 = (density1 + analogRead(A5));
    density2 = (density2 + analogRead(A3));
    delay(500);
  }
  digitalWrite(8, LOW); //ensures sample 1 LED off!!!!
  digitalWrite(9, LOW); //ensures sample 2 LED off!!!!
  delay(1000);
  Serial.print(darksig1);
  Serial.print(',');
  Serial.print(darksig2);
  Serial.print(',');
  Serial.print(darksig3);
  Serial.print(',');
  Serial.print(refsig);
  Serial.print(',');
  Serial.print(density1);
  Serial.print(',');
  Serial.print(density2);
  
}






