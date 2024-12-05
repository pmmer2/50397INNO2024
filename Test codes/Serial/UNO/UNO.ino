//for uno

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX for communication with Mega

void setup() {
    mySerial.begin(9600);
    Serial.begin(9600);
    Serial.println("Uno Serial Test");
}

void loop() {
    mySerial.println("Hello from Uno");
    delay(1000); // Send a message every second
}
