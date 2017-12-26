// Project name : Swarm Robot
// Designed By  : ROBOMART
//                http://www.robomart.com

/*
___________________________________________________

Connection settings of Kit


RIGHT MOTOR(+)------->PB0
RIGHT MOTOR(-)------->PB1
LEFT MOTOR(-)-------->PB2
LEFT MOTOR(+)-------->PB3

RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 & PB7
VCC=Regulated 5V
Gnd=Ground(0V)
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay_basic.h>
#define F_CPU 1000000UL

void wait()   
{
uint8_t i;
for(i=0;i<1;i++)          // delay function
_delay_loop_2(0);
}

/*-------------program for swarm robots/ Synchronized Robots------------*/


void main()
{
   
   DDRB=0b11111111;   //Motor Output port for mother robot; only PB0, PB1, PB2 and PB3 are used
   DDRD=0b11001111;   //PD4 and PD5 are sensor input pins comming from baby Robot; 
   DDRC=0b0000000;    //sensor Input port for Mother robot only PC4 and PC5 are used

int baby_status=0, mother_status=1;               // Mother status variable
int baby_left_sensor=0, baby_right_sensor=0;      // baby sensor variable
int mother_left_sensor=0, mother_right_sensor=0;  // mother sensor variable
int state=0,finish=0;

PORTD=0b00001111;


while(1)              // infinite loop
{

mother_left_sensor=PINC&0b0010000;    // mask bit 4 i.e 5th bit from right
mother_right_sensor=PINC&0b0100000;   // mask bit 5 i.e 6th bit from right

baby_left_sensor=PIND&0b00010000;     // mask bit 4 i.e 5th bit from right
baby_right_sensor=PIND&0b00100000;    // mask bit 5 i.e 6th bit from right

if(!finish) {                         // run untill not finish
if(mother_status==1)
{

if((mother_left_sensor==0b0010000)&(mother_right_sensor==0b0100000))      //if both sensors "on"
{

PORTB=0b00001001;      // move straight

}

if((mother_left_sensor==0b0000000)&(mother_right_sensor==0b0100000))      //if left sensor is "off"
{

PORTB=0b00000001;      // turn left

}

if((mother_left_sensor==0b0010000)&(mother_right_sensor==0b0000000))     //if right sensor is "off"
{

PORTB=0b00001000;      // turn right

}

if((mother_left_sensor==0b0000000)&(mother_right_sensor==0b0000000)&state==0) //if both sensors "off"
{

PORTB=0b00000000;      //stop mother robot
mother_status=0;       // set mother status to 0
baby_status=1;         //enable baby robot by setting baby status to 1
PORTD=0b00001001;      // move baby robot straight for 100 miliseconds so that it shift itself slightly to overcome both sensor off condition
wait();                // wait for 100 ms
state++;               // increase state counter

mother_left_sensor=127;   // reset sensors to some illigal values
mother_right_sensor=127;  // so that if conditions after this line wont execute with old sensor value

baby_left_sensor=127; 
baby_right_sensor=127; 

}


if((mother_left_sensor==0b0000000)&(mother_right_sensor==0b0000000)&state==2) //if both sensors "on"
{

PORTB=0b00000000; //stop
mother_status=0;  // same as described in privious if loop
baby_status=1;
PORTD=0b00001001; // move straight baby robot to overcome both sensor off condition
wait();
state++;
mother_left_sensor=127; // reset sensors to some illigal values
mother_right_sensor=127; 

baby_left_sensor=127; 
baby_right_sensor=127; 

}

if((mother_left_sensor==0b0000000)&(mother_right_sensor==0b0000000)&state==4) //if both sensors "on"
{

PORTB=0b00000000;  //stop
mother_status=0;
baby_status=1;
PORTD=0b00001001;  // move straight
wait();
state++;

mother_left_sensor=127;  // reset sensors to some illigal values
mother_right_sensor=127; 

baby_left_sensor=127; 
baby_right_sensor=127; 

}


}    // mother if closed


if(baby_status==1)
{

if((baby_left_sensor==0b0010000)&(baby_right_sensor==0b0100000))        //if both sensors "on"
{

PORTD=0b00001001;       // move straight

}

if((baby_left_sensor==0b0000000)&(baby_right_sensor==0b0100000))        //if both sensors "on"
{

PORTD=0b00000001;       // turn left

}

if((baby_left_sensor==0b0010000)&(baby_right_sensor==0b0000000)) //if both sensors "on"
{

PORTD=0b00001000;       // turn right

}

if((baby_left_sensor==0b0000000)&(baby_right_sensor==0b0000000)&(state==1)) //if both sensors "on"
{

PORTD=0b00000000;    //stop baby robot
baby_status=0;       // set baby status to 0
mother_status=1;     // set mother status to 1
PORTB=0b00001001;    // move Mother robot straight for few miliseconds so that it shifts itself slightly to overcome both sensor off condition
wait();              // wait for 100 ms
state++;             // increase state

}

if((baby_left_sensor==0b0000000)&(baby_right_sensor==0b0000000)&state==3) //if both sensors "on"
{

PORTD=0b00000000;     //same as previous if loop
baby_status=0;
mother_status=1;
PORTB=0b00001001;     // move straight
wait();
state++;

}

if((baby_left_sensor==0b0000000)&(baby_right_sensor==0b0000000)&state==5) //if both sensors "on"
{
    
PORTD=0b00000000;    //stop
baby_status=0;
mother_status=0;
PORTB=0b00000000; 
wait();
state++;
finish=1;

}


}        // baby if closed

}        // finish closed
}        //while closed
}
