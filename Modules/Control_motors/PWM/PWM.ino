#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define IN1 7
#define IN2 8
#define ENA 9 // this pin must be PWM enabled pin

// motor 2 settings
#define IN3 11
#define IN4 12
#define ENB 6 // this pin must be PWM enabled pin

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

// use the line below for single motor
//Robojax_L298N_DC_motor motor(IN1, IN2, ENA, true);

// use the line below for two motors
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, IN2, IN3, ENB, true);

void setup() {
  Serial.begin(9600);
  motor.begin();
  //L298N DC Motor by Robojax.com

}

void loop() {
  
  motor.demo(1);
 // motor.demo(2);  
  motor.rotate(motor1, 60, CW);//run motor1 at 60% speed in CW direction
  //motor.rotate(motor2, 60, CCW);//run motor2 at 60% speed in CCW direction  
 // delay(3000);
/*
  motor.brake(1);
  motor.brake(2);
  delay(2000);


  motor.rotate(motor1, 100, CW);//run motor1 at 60% speed in CW direction
  motor.rotate(motor2, 100, CCW);//run motor2 at 60% speed in CCW direction  
  delay(3000);

  motor.brake(1);
  motor.brake(2);
  delay(2000);  

  for(int i=0; i<=100; i++)
  {
    motor.rotate(motor1, i, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    delay(100);
  }
  delay(2000);
  
  motor.brake(1);
  motor.brake(2);
  delay(2000);  

  motor.rotate(motor1, 70, CCW);//run motor1 at 70% speed in CCW direction
  motor.rotate(motor2, 5, CW);//run motor2 at 50% speed in CW direction  
  delay(4000);

  motor.brake(3);
  delay(2000);    
 */
}
