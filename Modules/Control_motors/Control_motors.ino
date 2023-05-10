/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
Control motors software*/
#include <Robojax_L298N_DC_motor.h>
char command;
// Define logic control pins of motors
#define pwm_1  9
#define pwm_2  6
#define rightMotorForward 7
#define rightMotorBackward 8
#define leftMotorForward 11
#define leftMotorBackward 12
void setup() { // Code executes only once
Serial.begin(9600); // Start serial channel (bluetooth)
// configure the motor control pins to behave as an output
pinMode(pwm_1, OUTPUT);
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
case 'o':
speed_1();
break;
case 't':
speed_2();
break;
case 'T':
speed_3();
break;
case 'f':
speed_4();
break;
case 'F':
speed_5();
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

// The remaining functions act like the first but with different values
void moveBackward() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, HIGH);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, HIGH);
analogWrite(pwm_1,51) ;
analogWrite(pwm_2,51) ;
}
void moveRight() {
digitalWrite(rightMotorForward, HIGH);
digitalWrite(rightMotorBackward, LOW);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, HIGH);
analogWrite(pwm_1,51) ;
analogWrite(pwm_2,51) ;
}
void moveLeft() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, HIGH);
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,51) ;
analogWrite(pwm_2,51) ;
}
void stop() {
  digitalWrite(rightMotorForward,LOW) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,0);
analogWrite(pwm_2,0);
}
void speed_1()
{
digitalWrite(rightMotorForward,HIGH) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,51) ;
analogWrite(pwm_2,51) ;
}
void speed_2()
{
digitalWrite(rightMotorForward,HIGH) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,102) ;
analogWrite(pwm_2,102) ;
}
void speed_3()
{
digitalWrite(rightMotorForward,HIGH) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,153) ;
analogWrite(pwm_2,153) ;
}
void speed_4()
{
digitalWrite(rightMotorForward,HIGH) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,204) ;
analogWrite(pwm_2,204) ;
}
void speed_5()
{
digitalWrite(rightMotorForward,HIGH) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,255) ;
analogWrite(pwm_2,255) ;
}
