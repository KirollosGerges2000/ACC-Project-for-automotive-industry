/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
ACC project software*/
#include <LiquidCrystal.h>
#include <Robojax_L298N_DC_motor.h>
const int rs = 10, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte PulsesPerRevolution = 2;
const unsigned long ZeroTimeout = 100000;
const byte numReadings = 2;

volatile unsigned long LastTimeWeMeasured;
volatile unsigned long PeriodBetweenPulses = ZeroTimeout + 1000;
volatile unsigned long PeriodAverage = ZeroTimeout + 1000;
unsigned long FrequencyRaw;
unsigned long FrequencyReal;
unsigned long RPM;
unsigned int PulseCounter = 1;
unsigned long PeriodSum;

unsigned long LastTimeCycleMeasure = LastTimeWeMeasured;
unsigned long CurrentMicros = micros();
unsigned int AmountOfReadings = 1;
unsigned int ZeroDebouncingExtra;
unsigned long readings[numReadings];
unsigned long readIndex;  
unsigned long total; 
unsigned long average;
char command;
int IR = A0;  //pin A0
// Define logic control pins of motors
#define pwm_1  9
#define pwm_2  6
#define rightMotorForward 7
#define rightMotorBackward 8
#define leftMotorForward 11
#define leftMotorBackward 12
int value = analogRead(IR);
 int sensor_reading =value;


void setup(){
 Serial.begin(9600);
 // configure the motor control pins to behave as an output
 pinMode(IR,INPUT);
    pinMode(en,OUTPUT);
    pinMode(d7,OUTPUT);
pinMode(pwm_1, OUTPUT);
pinMode(rightMotorForward, OUTPUT); // Motor 1 Forward
pinMode(rightMotorBackward, OUTPUT); // Motor 1 Backward
pinMode(leftMotorForward, OUTPUT); // Motor 2 Forward
pinMode(leftMotorBackward, OUTPUT); // Motor 2 Backward
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);  // Print a message to the LCD.

  pinMode(PulsesPerRevolution,INPUT);
  attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);

}

void loop(){
  
 lcd_Band();
if (Serial.available()) { 
  // Checking if connection is available
  lcd_Band();
Serial.write("Serial Connection Started...\n"); // Connection start
command = Serial.read(); // Read next command from the bluetooth connection
}
switch (command) { // Compare the received command to a list of
case 'o':
speed_1();
lidar_S1();
speed_sensor();
break;
case 't':
speed_2();
lidar_S2();
speed_sensor();
break;
case 'T':
speed_3();
lidar_S3();
speed_sensor();
break;
case 'f':
speed_4();
lidar_S4();
speed_sensor();
break;
case 'F':
speed_5();
lidar_S5();
speed_sensor();
break;

case 'b':
moveBackward();
speed_sensor();
break;
case 'r':
moveRight();
break;
case 'l':
moveLeft();
break;
case 's':
stop();
speed_sensor();
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
analogWrite(pwm_1,100) ;
analogWrite(pwm_2,100) ;
  lcd.setCursor(0,1);
lcd.print("R");
}
void moveRight() {
digitalWrite(rightMotorForward, HIGH);
digitalWrite(rightMotorBackward, LOW);
digitalWrite(leftMotorForward, LOW);
digitalWrite(leftMotorBackward, HIGH);
analogWrite(pwm_1,255) ;
analogWrite(pwm_2,255) ;
}
void moveLeft() {
digitalWrite(rightMotorForward, LOW);
digitalWrite(rightMotorBackward, HIGH);
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,255) ;
analogWrite(pwm_2,255) ;
}
void stop() {
  digitalWrite(rightMotorForward,LOW) ;
digitalWrite(rightMotorBackward,LOW) ;
digitalWrite(leftMotorForward, HIGH);
digitalWrite(leftMotorBackward, LOW);
analogWrite(pwm_1,0);
analogWrite(pwm_2,0);
lcd_Band();

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

void lidar_S1()
{
  int value = analogRead(IR);
 int sensor_reading =value;
Serial.println(sensor_reading);
int speed =240-sensor_reading;
Serial.println(speed);
if(speed < 0)
{
stop();
}
else if(speed<=51)
  {
analogWrite(pwm_1,speed) ;
analogWrite(pwm_2,speed) ;
lcd_Band();
}
delay(10);
}

void lidar_S2()
{
  int value = analogRead(IR);
 int sensor_reading =value;
Serial.println(sensor_reading);
int speed =260-sensor_reading;
Serial.println(speed);
if(speed < 0)
{
lidar_S1();
}
else if(speed<=102)
  {
analogWrite(pwm_1,speed) ;
analogWrite(pwm_2,speed) ;
lcd_Band();
}
delay(10);
}

void lidar_S3()
{
  int value = analogRead(IR);
 int sensor_reading =value;
Serial.println(sensor_reading);
int speed =280-sensor_reading;
Serial.println(speed);
if(speed < 0)
{
lidar_S2();
}
else if(speed<=153)
  {
analogWrite(pwm_1,speed) ;
analogWrite(pwm_2,speed) ;
lcd_Band();
}
delay(10);
}

void lidar_S4()
{
  int value = analogRead(IR);
 int sensor_reading =value;
Serial.println(sensor_reading);
int speed =300-sensor_reading;
Serial.println(speed);
if(speed < 0)
{
lidar_S3();
}
else if(speed<=204)
  {
analogWrite(pwm_1,speed) ;
analogWrite(pwm_2,speed) ;
lcd_Band();
}
delay(10);
}

void lidar_S5()
{
  int value = analogRead(IR);
 int sensor_reading =value;
Serial.println(sensor_reading);
int speed =300-sensor_reading;
Serial.println(speed);
if(speed < 0)
{
lidar_S4();
}
else if(speed<=255)
  {
analogWrite(pwm_1,speed) ;
analogWrite(pwm_2,speed) ;
lcd_Band();
}
delay(10);
}

void lcd_Band()
{
  lcd.setCursor(0, 0);   
  lcd.print("ACC System Test");
}


void speed_sensor()
{
  LastTimeCycleMeasure = LastTimeWeMeasured;
  CurrentMicros = micros();
  if (CurrentMicros < LastTimeCycleMeasure) {
    LastTimeCycleMeasure = CurrentMicros;
  }
  FrequencyRaw = 10000000000 / PeriodAverage;
  if (PeriodBetweenPulses > ZeroTimeout - ZeroDebouncingExtra || CurrentMicros - LastTimeCycleMeasure > ZeroTimeout - ZeroDebouncingExtra) {
    FrequencyRaw = 0;  // Set frequency as 0.
    ZeroDebouncingExtra = 2000;
  } else {
    ZeroDebouncingExtra = 0;
  }
  FrequencyReal = FrequencyRaw / 10000;

  RPM = FrequencyRaw / PulsesPerRevolution * 60;
  RPM = RPM / 10000;
  total = total - readings[readIndex];
  readings[readIndex] = RPM;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  average = total / numReadings;
   lcd.setCursor(0,1); 
lcd.print("Speed=");
lcd.print(average/90
);
lcd.print("cm/sec");
}

void Pulse_Event() {
  PeriodBetweenPulses = micros() - LastTimeWeMeasured;
  LastTimeWeMeasured = micros();
  if (PulseCounter >= AmountOfReadings)  {
    PeriodAverage = PeriodSum / AmountOfReadings;
    PulseCounter = 1;
    PeriodSum = PeriodBetweenPulses;

    int RemapedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);
    RemapedAmountOfReadings = constrain(RemapedAmountOfReadings, 1, 10);
    AmountOfReadings = RemapedAmountOfReadings;
  } else {
    PulseCounter++;
    PeriodSum = PeriodSum + PeriodBetweenPulses;
  }
}
