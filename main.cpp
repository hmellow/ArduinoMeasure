#include <LiquidCrystal.h>

#define trigPin 8
#define echoPin 7

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buttonPin = 9;
int buttonState = 0;
float duration, distance;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Distance (cm):");
  // lcd.setCursor(0,1);
  // lcd.print("");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  lcd.setCursor(0, 2);
  lcd.print("            ");
  lcd.setCursor(0, 2);
  if (distance >= 400 || distance <= 2) {
    lcd.print("Out of range");
    delay(500);
  } else {
    lcd.print(distance);
    delay(500);
  }
  }     
}
