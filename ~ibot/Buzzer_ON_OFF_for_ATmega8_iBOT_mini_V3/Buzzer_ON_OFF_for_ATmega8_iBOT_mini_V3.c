/* Project name		: Buzzer_ON_OFF_for_ATmega8_iBOT_mini_V3
// Compiled Date 	: 28/03/2013 Time : (12:32)
// Complied by 		: Pradeep Kumar Sharma (Pradeep.elcom@gmail.com)
// Designed By 		: ROBOSAPIENS TECHNOLOGIES PVT. LTD 
//                	  http://www.robosapiensindia.com
// Designed for		: Robosapiens Product id RSI-05,RSI-05A
/* Program for "Buzzer ON-OFF/Toggeling BUZZER ON and OFF connected with PD4" 
 ___________________________________________________
Connection settings of Kit

LEDs---@--------------------->PB1
LEDs---@--------------------->PB2
LEDs---@--------------------->PB3
LEDs---@--------------------->PB4
RIGHT MOTOR(+)--------------->PB1
RIGHT MOTOR(-)--------------->PB2
LEFT MOTOR(-)---------------->PB3
LEFT MOTOR(+)---------------->PB4
Buzzer----------------------->PD4
BOOTLoader Condition Check--->PC5(If 0 bootloader section else program execution section of Flash memory)
RESET------------------------>PC6
Crystal Ossilator(12MHz)----->PB6 and PB7(hence PB6 & PB7 are not available for user)
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 120000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "robosapiens.c"
int main(void)
{

DDRD=0b00010000;  // PD4 of PORTD are set as output.  
 while(1)         // infinite while loop
    {
    PORTD=0b00010000;  //PD4 BUZZER are set ON 
wait(0.5);               // wait function defined in robosapiens.c file function argument: time in seconds
    PORTD=0b00000000; // PD4 BUZZER are set OFF   
wait(0.5);
	}
}



