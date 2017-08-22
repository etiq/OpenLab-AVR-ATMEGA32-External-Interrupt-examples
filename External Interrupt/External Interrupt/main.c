/*
 * External interrupt.c
 *
 * Created: 4/1/2016 10:23:52 AM
 * Author : Etiq Technologies
 */ 
#ifdef F_CPU              //defines the CPU clock to be 8 MHz
#define F_CPU 8000000UL
#endif // F_CPU

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/*external interrupt service routine*/
ISR(INT1_vect)
{
unsigned char i;
PORTC=0x01;
_delay_ms(1000);
for(i=0;i<8;i++)
{  
	 
	PORTC=PORTC<<1;
	_delay_ms(1000);
}	


}
/*enable the external interrupt*/
void enable_INT1_interrupt()
{
	    MCUCR=(1<<ISC11);
	    GICR=(1<<INT1);
	    sei();
}
/*main function*/
int main(void)
{  
	DDRC=0xFF;
	DDRD=0x00;
	PORTD=0xFF;
    enable_INT1_interrupt();
	/*All LEDs connected to PORTC blink continously if external interrup occurs ISR changes the pattern of LED blinking*/
    while (1) 
    {
		PORTC=0xFF;
		_delay_ms(250);
		PORTC=0x00;
		_delay_ms(250);
    }
}

