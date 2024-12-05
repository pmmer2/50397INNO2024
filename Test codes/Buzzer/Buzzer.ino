const int buzzerPin = 9;

void setup() {
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Buzzer Test");
}

void loop() {
    tone(buzzerPin, 1000, 500);  // 1000 Hz for 500 ms
    delay(1000);                 // Wait 1 second
    noTone(buzzerPin);           // Stop the tone
    delay(1000);
}

