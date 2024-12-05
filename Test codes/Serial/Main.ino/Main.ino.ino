#include <LiquidCrystal.h>

// LCD pin configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Hardware serial communication
HardwareSerial &mySerial = Serial1;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);    // For debugging
    mySerial.begin(9600);  // Communication with Uno node

    // Initialize LCD
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Mega Test Mode");

    Serial.println("Mega Test Initialized");
}

void loop() {
    // Send test message to Uno
    static unsigned long lastSendTime = 0;
    if (millis() - lastSendTime > 2000) { // Every 2 seconds
        mySerial.println("TestMessageFromMega");
        Serial.println("Sent: TestMessageFromMega");
        lastSendTime = millis();
    }

    // Check for incoming messages from Uno
    if (mySerial.available()) {
        String message = mySerial.readStringUntil('\n');
        Serial.print("Received from Uno: ");
        Serial.println(message);

        // Display received message on LCD
        lcd.setCursor(0, 1);
        lcd.print("Recv: ");
        lcd.print(message);
        lcd.print("     ");  // Clear trailing characters
    }
}
