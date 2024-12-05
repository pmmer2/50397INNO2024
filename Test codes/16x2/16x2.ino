#include <LiquidCrystal.h> 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("LCD Test");
    lcd.setCursor(0, 1);
    lcd.print("Working?");
}

void loop() {
    // Do nothing; just display the text
}
