#include<avr/io.h>
#include<util/delay.h>
main()
{
 DDRB=0b11111111;
 DDRC=0b0000000;

 int ls,rs;

 while(1)
 { 
  ls=PINC&0b0001000;
  rs=PINC&0b0000001;

  if((ls=0b0001000)&&(rs=0b0000001))
   {
    PORTB=0b00011110;
    }
  if((ls=0b0001000)&&(rs=0b0000000))
   {
    PORTB=0b00000110;
    }
  }

}
