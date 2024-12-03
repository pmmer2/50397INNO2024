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
        delay(5000);   // Delay to avoid multiple detections in quick succession
    }
}

void playSound() {
    int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Frequencies for C4 to B4
    int numNotes = sizeof(notes) / sizeof(notes[0]);

    for (int i = 0; i < 5; i++) { // Play 5 random notes
        int note = notes[random(0, numNotes)];
        tone(buzzerPin, note, 300); // Play note for 300ms
        delay(350); // Small gap between notes
    }

    noTone(buzzerPin); // Stop the tone
}
  