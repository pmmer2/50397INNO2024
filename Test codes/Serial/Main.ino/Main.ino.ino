//for mega

void setup() {
    Serial1.begin(9600); // Communication with Uno (Serial1)
    Serial.begin(9600);  // Debugging (Serial Monitor)
    Serial.println("Mega Serial Test");
}

void loop() {
    if (Serial1.available()) {
        String message = Serial1.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(message);
    }

    delay(100);
}
