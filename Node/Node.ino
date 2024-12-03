#define TRIG_PIN 7
#define ECHO_PIN 6
#define BUZZER_PIN 9

#define NODE_ID "Node1" // Change this ID for each node (e.g., Node2, Node3)

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600); // Communication with Mega
}

void loop() {
  long duration;
  float distance;

  // Ultrasonic sensor functionality
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2.0) * 0.0343; // Convert to cm

  // Detect whale (if within 50 cm)
  if (distance > 0 && distance <= 50) {
    Serial.println(String(NODE_ID) + ":WhaleDetected"); // Send message to Mega
    delay(500); // Prevent spamming
  }

  // Listen for approval from the Mega
  if (Serial.available()) {
    String message = Serial.readString();
    if (message == "Approved:" + String(NODE_ID)) {
      playRandomPattern(); // Play the sound pattern
    }
  }
}

void playRandomPattern() {
  int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Example notes (C4 to B4)
  for (int i = 0; i < 10; i++) { // Random pattern of 10 beeps
    int note = notes[random(0, 7)];
    int duration = random(100, 500); // Random duration between 100-500ms
    tone(BUZZER_PIN, note, duration);
    delay(duration + 50); // Short pause between notes
  }
  noTone(BUZZER_PIN); // Stop the sound
}
