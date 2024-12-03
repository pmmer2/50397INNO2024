#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX for communication with Mega (pins 2 and 3)

int trigPin = 7;   // Ultrasonic TRIG pin
int echoPin = 6;   // Ultrasonic ECHO pin
int buzzerPin = 9; // Buzzer pin
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);

    mySerial.begin(9600);  // Start communication with Mega
    Serial.begin(9600);    // For debugging

    // Send initial status
    mySerial.println("Node ready");
    Serial.println("Uno Initialized and Ready");
}

void loop() {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Calculate distance in cm

    if (distance > 0 && distance <= 50) { // Whale detected (within 50 cm)
        mySerial.println("Node1:WhaleDetected");  // Send message to Mega
        playSound();  // Play sound
    }

    delay(500); // Check every 500ms for new readings
}

void playSound() {
    // Simple tone to test buzzer
    tone(buzzerPin, 1000, 500);  // Frequency 1000Hz for 500ms
    delay(600);  // Wait for the sound to finish before returning
    noTone(buzzerPin);  // Stop the tone
}
