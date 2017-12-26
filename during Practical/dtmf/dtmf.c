#include<avr/io.h>
#include<util/delay.h>

main()
{
 int d=0;
 int b=0;

 DDRB=0b00011110;     
 DDRD=0b00010000; 
 
 while(1)
 {
  b=PINB&0b00000001;
  d=PINB&0b11100000; 

  if((d==0b10000000) && (b==0b00000000))
     {
      PORTB=0b00010010;    //move straight
     }
  if((d==0b01000000) && (b==0b00000000))
   {
    PORTB=0b000010000;    //turn left
   }
  if((d==0b11000000) && (b==0b00000000))
   {
    PORTB=0b00000010;     //turn right
   }
  if((d==0b00100000) && (b==0b00000000))
   {
    PORTB=0b00001100;     //move back
   }
   if((d==0b00000000) && (b==0b00000001))
   {
    PORTB=0b000010000;    //turn left
   }
   if((d==0b10000000) && (b==0b00000001))
   {
    PORTB=0b00000010;     //turn right
   }
   if((d==0b00100000) && (b==0b00000001))
   {
    PORTB=0b00000100;     // right turn in forward motion
   }
   if((d==0b11000000) && (b==0b00000001))
   {
    PORTB=0b00001000;     //left turn in backward motion
   }
   if((d==0b01000000) && (b==0b00000001))
   {
    PORTB=0b00000000;     //stop
   }
 }
}
