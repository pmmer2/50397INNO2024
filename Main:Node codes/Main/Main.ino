#include <LiquidCrystal.h>

// Define LCD pin configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Hardware serial communication with Uno
HardwareSerial &mySerial = Serial1;

// Variables
int whaleCount = 0;  // Counter for detected whales

void setup() {
    // Initialize serial communication
    Serial.begin(9600);        // For debugging
    mySerial.begin(9600);      // Communication with Uno node

    // Initialize LCD
    lcd.begin(16, 2);          // 16x2 LCD
    lcd.setCursor(0, 0);
    lcd.print("Whale Detection");

    // Debugging message
    Serial.println("Mega Initialized and Ready");
}

void loop() {
    // Display whale count on LCD
    lcd.setCursor(0, 1);
    lcd.print("Whales: ");
    lcd.print(whaleCount);
    lcd.print("     ");  // Clear trailing characters

    // Check for incoming messages from the Uno node
    if (mySerial.available()) {
        String message = mySerial.readStringUntil('\n'); // Read incoming message
        processMessage(message);
    }

    delay(100);  // Adjust delay for smooth operation
}

void processMessage(String message) {
    // Process the incoming message
    if (message.startsWith("Node1:WhaleDetected")) {
        whaleCount++; // Increase whale count
        Serial.println("Whale Detected - Count Updated");
        playSound();  // Play sound immediately when a whale is detected
    }
}

void playSound() {
    // Placeholder for sound indication (optional on Mega)
    Serial.println("Sound Triggered");
}
