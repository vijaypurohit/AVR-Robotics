// Project name : Line Follower Robot
// Designed By  : ROBOMART
//                http://www.robomart.com

/* Program for "Black Line Follower Robot" 
___________________________________________________

Connection settings of Kit

Left Sensor---@------------->PC5
Right Sensor---@------------->PC6

RIGHT MOTOR(+)------->PB
RIGHT MOTOR(-)------->PB
LEFT MOTOR(-)-------->PB
LEFT MOTOR(+)-------->PB

RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 & PB7
VCC=Regulated 5V
Gnd=Ground(0V)
*/

#define F_CPU 1000000UL    // define cpu frequency for delay function
#include <avr/io.h>        // includes input/output header file     
#include <util/delay.h>    // includes delay header file  


int main(void)
{
DDRB=0b11111111;     //PORTB as output Port connected to motors
DDRC=0b0000000;      //PORTC Input port connected to Sensors

int left_sensor=0, right_sensor=0;

   while(1)    // infinite loop
   { 
   left_sensor=PINC&0b0010000;    // mask PC4 bit of Port C
   right_sensor=PINC&0b0100000;   // mask PC5 bit of Port C
	 
	 if((left_sensor==0b0000000) & (right_sensor==0b0000000)) //if both sensors "off"
     {
     
	 PORTB=0b00000000; // stop
			
     }

     if((left_sensor==0b0010000) & (right_sensor==0b0100000)) //if both sensors "on"
     {
      
	 PORTB=0b00001001; // move straight
               
     }
	
     if((left_sensor==0b0000000)&(right_sensor==0b0100000))
     {
     
	 PORTB=0b00000001; // turn left
	      
     }

     if((left_sensor==0b0010000)&(right_sensor==0b0000000))
     {
     
	 PORTB=0b00001000; // turn right

	 }
			 
   }
 
 }

