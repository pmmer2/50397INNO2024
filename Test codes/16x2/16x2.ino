#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
