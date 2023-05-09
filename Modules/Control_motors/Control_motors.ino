/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
Control motors software*/
char command;
// Define logic control pins of motors
#define rightMotorForward 7
#define rightMotorBackward 8
#define leftMotorForward 11
#define leftMotorBackward 12
void setup() { // Code executes only once
Serial.begin(9600); // Start serial channel (bluetooth)
// configure the motor control pins to behave as an output
pinMode(rightMotorForward, OUTPUT); // Motor 1 Forward
pinMode(rightMotorBackward, OUTPUT); // Motor 1 Backward
pinMode(leftMotorForward, OUTPUT); // Motor 2 Forward
pinMode(leftMotorBackward, OUTPUT); // Motor 2 Backward
}
void loop() { // Code executes repeatedly
if (Serial.available()) { // Checking if connection is available
Serial.write("Serial Connection Started...\n"); // Connection start
command = Serial.read(); // Read next command from the bluetooth connection
}
switch (command) { // Compare the received command to a list of
case 'f':
moveForward();
break;
case 'b':
moveBackward();
break;
case 'r':
moveRight();
break;
case 'l':
moveLeft();
break;
case 's':
stop();

break;
default: // No match from the list of known commands
Serial.write("Unknown Command \n");
break;
}
delay(200);
}
void moveForward() {
digitalWrite(rightMotorForward, HIGH); // Enable forward motion of 
digitalWrite(rightMotorBackward, LOW); // Disable backward motion of r
digitalWrite(leftMotorForward, HIGH); // Enable forward motion of left motor
digitalWrite(leftMotorBackward, LOW); // Disable forward motion of left motor
}
// The remaining functions act like the first but with different values
void moveBackward() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, HIGH);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, HIGH);
}
void moveRight() {
digitalWrite(rightMotorForward, HIGH);
digitalWrite(rightMotorBackward, LOW);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, LOW);
}
void moveLeft() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, LOW);
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
}
void stop() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, LOW);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, LOW);
}
