#include <Servo.h> // Include the Servo library
#include <Arduino.h>

Servo servo1; // Create a servo object
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0;

void setup() {
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
   // Attach the servo to pin 
  Serial.begin(9600); // Initialize the serial communication at 9600 baud rate
  
}

void loop() {
  
  if (Serial.available()) { // Check if there is any data in the serial buffer
    // String input = Serial.readString(); // Read the input as a String object
    int pos1 = Serial.parseInt();
    int pos2 = Serial.parseInt();
    int pos3 = Serial.parseInt();
    int pos4 = Serial.parseInt();
    servo1.write(pos1);
    servo2.write(pos2);
    servo3.write(pos3);
    servo4.write(pos4);
  }
  
  delay(15);
}