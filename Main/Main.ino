#include <LiquidCrystal.h>

// Initialize the LCD (adjust pins if needed)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Node detection counters
int node1Count = 0;
int node2Count = 0; // Add more nodes as needed

unsigned long startTime;
unsigned long currentTime;

String receivedMessage = "";

void setup() {
  lcd.begin(16, 2); // Initialize the LCD
  Serial.begin(9600); // Communication with nodes
  startTime = millis();
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
  lcd.print("Idle...");
}

void loop() {
  // Check for messages from nodes
  if (Serial.available()) {
    receivedMessage = Serial.readString();
    processMessage(receivedMessage);
  }

  // Update timer display every second
  if (millis() - currentTime >= 1000) {
    updateTimer();
    currentTime = millis();
  }
}

void processMessage(String message) {
  if (message.startsWith("Node")) {
    String nodeId = message.substring(0, 5); // Extract Node ID
    lcd.clear();
    lcd.print("From: ");
    lcd.print(nodeId);

    if (message.endsWith("WhaleDetected")) {
      lcd.setCursor(0, 1);
      lcd.print("Whale Spotted!");

      // Update detection count
      if (nodeId == "Node1") {
        node1Count++;
      } else if (nodeId == "Node2") {
        node2Count++;
      }

      // Send approval to the specific node
      Serial.println("Approved:" + nodeId);

      delay(2000); // Display the message for 2 seconds
      displayNodeStats();
    }
  }
}

void displayNodeStats() {
  lcd.clear();
  lcd.print("N1: ");
  lcd.print(node1Count);
  lcd.print(" N2: ");
  lcd.print(node2Count);
  lcd.setCursor(0, 1);
  lcd.print("Idle...");
}

void updateTimer() {
  unsigned long elapsedTime = (millis() - startTime) / 1000; // Time in seconds
  int minutes = elapsedTime / 60;
  int seconds = elapsedTime % 60;

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}
