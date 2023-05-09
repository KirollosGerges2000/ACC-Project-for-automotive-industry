/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
speed rpm sensor software*/
#include "Timer.h"
Timer t;
#define number_of_holes 20
#define interruptPin 6
int i = 0;

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), counter, RISING);
  Serial.begin(9600);
//  t.read(500, print_speed);
print_speed();
}

void loop() {
 
  t.state();
  print_speed();
}


void print_speed()
{
  i=digitalRead(interruptPin);
  Serial.print("Speed:  ");
  Serial.print(i * 120 / number_of_holes);
  Serial.println(" rpm");
  i = 0;
}

void counter() {
  i++;
}
