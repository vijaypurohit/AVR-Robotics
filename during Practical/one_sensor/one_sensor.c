#include<avr/io.h>
#include<util/delay.h>

main()
{
 DDRB=0b11111111;     
 DDRC=0b0000000; 
  
 int ls;
 
 while(1)
 {
  ls=PINC&0b0001000; 

  if((ls==0b0001000))
     {
    PORTB=0b00010000;
    }
  if((ls==0b0000000))
   {
    PORTB=0b00000010;
    }

 }
}
