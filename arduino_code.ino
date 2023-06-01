#include <LiquidCrystal.h>
#define LED_PIN 9
#define BUTTON_PIN 7
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("");
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("");
  
  
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, LOW);
    Serial.println(111);
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Cont:7219846196");
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Blood: O+");

  }
  else {
    //digitalWrite(LED_PIN, HIGH);
    //Serial.println(100);
  }
}
