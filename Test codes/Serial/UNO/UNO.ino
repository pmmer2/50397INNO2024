#include <SoftwareSerial.h>

// SoftwareSerial configuration
SoftwareSerial mySerial(2, 3); // RX, TX for communication with Mega

void setup() {
    // Initialize serial communication
    mySerial.begin(9600);  // Communication with Mega
    Serial.begin(9600);    // For debugging

    Serial.println("Uno Test Initialized");
}

void loop() {
    // Check for incoming messages from Mega
    if (mySerial.available()) {
        String message = mySerial.readStringUntil('\n');
        Serial.print("Received from Mega: ");
        Serial.println(message);
    }

    // Send test message to Mega
    static unsigned long lastSendTime = 0;
    if (millis() - lastSendTime > 2000) { // Every 2 seconds
        mySerial.println("TestMessageFromUno");
        Serial.println("Sent: TestMessageFromUno");
        lastSendTime = millis();
    }
}
