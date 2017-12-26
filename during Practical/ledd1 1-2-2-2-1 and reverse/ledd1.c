#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0b00011110;
while(1)
{
PORTB=0b00010000;
_delay_ms(1000);

PORTB=0b00011000;
_delay_ms(1000);

PORTB=0b00001100;
_delay_ms(1000);
PORTB=0b00000110;
_delay_ms(1000);
PORTB=0b00000010;
_delay_ms(1000);
PORTB=0b0000000;
_delay_ms(1000);

PORTB=0b00000010;
_delay_ms(1000);

PORTB=0b00000110;
_delay_ms(1000);
PORTB=0b00001100;
_delay_ms(1000);
PORTB=0b00011000;
_delay_ms(1000);
PORTB=0b00010000;
_delay_ms(1000);
PORTB=0b00000000;
_delay_ms(1000);
}
}

