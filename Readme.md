
Whale Detection System with Arduino Mega and Uno Nodes
Overview
This project is a whale detection and alert system using Arduino Mega 2560 as the base station and multiple Arduino Uno nodes. Each node consists of an ultrasonic sensor for detection and a buzzer for sound playback. The Mega displays real-time updates and node activity on a 16x2 LCD.

Features:

Detect objects (whales) within a specified range using ultrasonic sensors.
Log and display which node detected the object on the LCD.
Approve detections and trigger a random sound pattern on the detecting node.
Track detection counts for each node.
Display elapsed system runtime.
Hardware Requirements
Base Station (Arduino Mega 2560):

Arduino Mega 2560
16x2 LCD with I2C or standard pin wiring
Breadboard and jumper wires
Nodes (Arduino Uno):

Arduino Uno (one for each node)
Ultrasonic sensor (HC-SR04 or similar)
Buzzer with transistor (optional: resistor)
Breadboard and jumper wires
Communication:

Serial communication via TX/RX pins between Mega and Uno(s).
Wiring
Mega (Base Station):

LCD RS: Pin 12
LCD Enable: Pin 11
LCD D4: Pin 5
LCD D5: Pin 4
LCD D6: Pin 3
LCD D7: Pin 2
Uno (Node):

Ultrasonic TRIG: Pin 7

Ultrasonic ECHO: Pin 6

Buzzer: Pin 9

Software Requirements

Arduino IDE: Download from https://www.arduino.cc/en/software.

LiquidCrystal Library: Pre-installed with Arduino IDE.

Installation

Open the Arduino IDE.

Connect the Mega and upload the mega_base code.

Connect each Uno node and upload the node_sensor_buzzer code with unique NODE_ID values (e.g., Node1, Node2).



Connect the Mega and Uno boards via TX/RX pins:

Mega TX1 (Pin 18) ↔ Uno RX (Pin 0)

Mega RX1 (Pin 19) ↔ Uno TX (Pin 1)

Usage

Power on the Mega and Uno nodes.

The LCD on the Mega will display:

Idle...

Time: 00:00

When a node detects an object within range:

The node sends a message to the Mega (NodeX:WhaleDetected).

The Mega approves the detection and displays:

From: Node1

Whale Spotted!

The node plays a random sound pattern on the buzzer.

After detection, the Mega displays stats:

N1: 2 N2: 0

Idle...


Troubleshooting


No LCD Display: Check wiring and ensure the LiquidCrystal library is included.

No Detection: Verify ultrasonic sensor connections and range settings.

No Sound: Ensure the buzzer and transistor are wired correctly.


License

This project is open-source and free to use under the MIT License.

