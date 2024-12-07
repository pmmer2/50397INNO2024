#include <SoftwareSerial.h>

// SoftwareSerial configuration
SoftwareSerial mySerial(2, 3); // RX, TX for communication with Mega

// Ultrasonic sensor pins
const int trigPin = 6;
const int echoPin = 5;

// Buzzer pin
const int buzzerPin = 9;

// Variables
long duration;
int distance;

void setup() {
    // Initialize pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);

    // Initialize serial communication
    mySerial.begin(9600);  // Communication with Mega
    Serial.begin(9600);    // For debugging

    // Debugging message
    Serial.println("Uno Initialized and Ready");
}

void loop() {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Calculate distance
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Convert to cm

    // Check if a whale is detected
    if (distance > 0 && distance <= 50) { // Object within 50 cm
        mySerial.println("Node1:WhaleDetected");  // Notify Mega
        Serial.println("Whale Detected");
        playSound();  // Play sound on detection
        delay(2000);  // Wait to avoid spamming detections
    }

    delay(100);  // Adjust delay for smoother operation
}

void playSound() {
    // Generate a simple sound pattern
    for (int i = 0; i < 3; i++) { // Play three tones
        tone(buzzerPin, 1000 + (i * 200), 300); // Frequency increases
        delay(400);  // Pause between tones
    }
    noTone(buzzerPin); // Ensure buzzer stops
}
