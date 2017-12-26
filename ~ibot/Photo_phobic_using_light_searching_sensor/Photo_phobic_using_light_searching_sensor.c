// Project name : Photo phobic for Atmega8 mini
// Compile Date : 31/10/2011 Time : (16:21)
// Designed By  : ROBOSAPIENS INDIA 
//                http://www.robosapiensindia.com
/* Program for "Photo phobic" 
 ___________________________________________________
Connection settings of Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
left sensor---------->PC0
right sensor--------->PC3
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLooder Condition Check----->PC5(f 0 bootler section else program execution
							  section of Flash memory)
RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#include<avr/io.h>


void main()
{
	
	DDRB=0b00011110;    //PB1, PB2, PB3, PB4 as output port and PB0 as input bit
    int ls=0;           // define & initialize ls integer as 0 to 
						// acquire the light sensor status in ls 
	while(1)            // create infinite loop
	{
	ls=(PINB&0b0000001);   //acquire only light sensor status connected at PB0
	
	if(ls==1)
	{
	PORTB=0b000010000;
	}	
	else
	PORTB=0b000000010;
	}
	}
