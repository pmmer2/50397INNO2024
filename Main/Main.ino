#include <LiquidCrystal.h>  // Use this for standard LCD (non-I2C)

// Define the hardware serial communication on Mega (using Serial1)
HardwareSerial& mySerial = Serial1;  // Use Serial1 for communication with Uno node

// LCD display setup (using standard LCD)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Adjust pin numbers based on your wiring

int whaleCount = 0;  // Counter for detected whales

void setup() {
    // Start serial communication
    Serial.begin(9600);        // Serial monitor for debugging
    mySerial.begin(9600);      // Use Serial1 for Uno node communication
    lcd.begin(16, 2);          // Initialize LCD

    lcd.setCursor(0, 0);
    lcd.print("Whale Detection");

    pinMode(9, OUTPUT);  // Buzzer pin

    // Debugging message
    Serial.println("Mega Initialized and Ready");
}

void loop() {
    // Display whale count on LCD
    lcd.setCursor(0, 1);
    lcd.print("Whales: ");
    lcd.print(whaleCount);

    // Read messages from the Uno node if available
    if (mySerial.available()) {
        String message = mySerial.readStringUntil('\n');
        processMessage(message);
    }

    delay(500);  // Slow down the loop to make sure the LCD updates and we can see the count
}

void processMessage(String message) {
    // Display incoming message and update whale count
    if (message.startsWith("Node1:WhaleDetected")) {
        whaleCount++; // Increase whale count
        Serial.println("Whale Detected - Count Updated");
        playSound();  // Play sound immediately when a whale is detected
    }
}

void playSound() {
    // Simple tone to test buzzer
    tone(9, 1000, 500);  // Frequency 1000Hz for 500ms
    delay(600);  // Wait for the sound to finish before returning
    noTone(9);  // Stop the tone
}
