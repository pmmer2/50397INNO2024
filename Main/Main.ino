#include <LiquidCrystal.h>  // Use this for standard LCD (non-I2C)

// Define the hardware serial communication on Mega (using Serial1)
HardwareSerial& mySerial = Serial1;  // Use Serial1 for communication with Uno node

// LCD display setup (using standard LCD)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Adjust pin numbers based on your wiring

int whaleCount = 0;  // Counter for detected whales
unsigned long startMillis;
unsigned long currentMillis;

void setup() {
    // Start serial communication
    Serial.begin(9600);        // Serial monitor for debugging
    mySerial.begin(9600);      // Use Serial1 for Uno node communication
    lcd.begin(16, 2);          // Initialize LCD

    lcd.setCursor(0, 0);
    lcd.print("Whale Detection");

    startMillis = millis();    // Start the timer for elapsed time
}

void loop() {
    currentMillis = millis();

    // Display elapsed time on LCD
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print((currentMillis - startMillis) / 1000); // seconds

    // Check if data is available from Uno node via Serial1
    if (mySerial.available()) {
        String message = mySerial.readStringUntil('\n');
        processMessage(message);
    }
}

void processMessage(String message) {
    // Display incoming message and update whale count
    if (message.startsWith("Node1:WhaleDetected")) {
        whaleCount++;
        lcd.setCursor(0, 1);
        lcd.print("Whale Count: ");
        lcd.print(whaleCount);
    }
}
