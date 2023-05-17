/**
 * File: Robojax_L298N_DC_motor.h
Written by Ahmad Shamshiri (Robojax.com) on October 01, 2019

 * Description:

 * Author: Ahmad Shamshiri
 * Contact: robojax.com
 * Copyright: 2019 Ahmad Shamshiri


    Robojax_L298N_DC_motor is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef Robojax_L298N_DC_motor_H
#define Robojax_L298N_DC_motor_H

#include "Arduino.h"


class Robojax_L298N_DC_motor
{
public:

    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA);
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA, boolean debug);	
	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB);	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB, boolean debug);	
	

    /**
     * control motor
     */
    void rotate(int motor, int value, int dir);
   /**
    * Initializes the L298D motor driver
    */
   void begin();
   

   
   /*
   * brake the motor
   
   */
   void brake(int motor);
  
   /*
   * single motor demo
   
   */
   void demo(int motor);
	
private:

   /*
   * debug print
   */
   void printDebug1(int motor, int p1, int v1, int p2, int v2, int dir, int speed);
   void printDebug2(int motor1, int p1, int v1, int p2, int v2, int dir1, int speed1, int motor2, int p3, int v3, int p4, int v4, int dir2, int speed2) ;
   
   int _in1, _in2, _enA, _in3, _in4,  _enB;
   boolean _debug = false;
   boolean _dual;
 
   int toPWM(int v);   
};

#endif
