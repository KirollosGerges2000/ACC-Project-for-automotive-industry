/*
 * Library Example for L298N Module to control DC motors
 * 
 * This code is to control two DC motors. 
 * 
 * Written by Ahmad Shamshiri on October 01, 2019 at 21:26 
 * in Ajax, Ontario, Canada. www.robojax.com
 * 
 Need wiring diagram from this code: Purchase My course on Udemy.com http://robojax.com/L/?id=62
 * 
 * Watch video instruction for this code: https://youtu.be/wn5D7j1ybxY
 * 
 * Get this code and other Arduino codes from Robojax.com
Learn Arduino step by step in structured course with all material, wiring diagram and library
all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63

or make donation using PayPal http://robojax.com/L/?id=64

 *  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define IN1 2
#define IN2 4
#define ENA 3 // this pin must be PWM enabled pin

// motor 2 settings
#define IN3 7
#define IN4 8
#define ENB 9 // this pin must be PWM enabled pin

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

// use the line below for single motor
//Robojax_L298N_DC_motor motor(IN1, IN2, ENA, true);

// use the line below for two motors
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, IN2, IN3, ENB, true);

void setup() {
  Serial.begin(115200);
  motor.begin();
  //L298N DC Motor by Robojax.com

}

void loop() {
  
  motor.demo(1);
  motor.demo(2);  
  motor.rotate(motor1, 60, CW);//run motor1 at 60% speed in CW direction
  motor.rotate(motor2, 60, CCW);//run motor2 at 60% speed in CCW direction  
  delay(3000);

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
  
}
