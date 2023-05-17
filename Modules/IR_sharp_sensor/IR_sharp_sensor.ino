/*Developed by Eng/kirollos Gerges Asaad
ACC Project 
IR sharp sensor software*/
int IR = A0;  //pin A0
void setup(){
 Serial.begin(9600);
}
void loop(){
 int value = analogRead(IR);
 int sensor_reading =value;
 Serial.println(sensor_reading);
 delay(100);
}
