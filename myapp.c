/*
 * my_app.c
 *
 * Created: 10/29/2020 11:31:43 AM
 * Author : bahaa
 */ 

#include "myapp.h"
//#include "util/delay.h"

int main(void)
{
    /* Replace with your application code */
led_t led1={.port_info.port_name=PORTB_INDEX,.port_info.pin=PIN2,.led_status=LED_OFF};
	button_t btn1={.port_name=PORTD_INDEX,.pin=PIN0,.button_status=BUTTON_NOT_PRESSED};
		led_init(&led1);
		button_init(&btn1);
		button_status bstate;
    while (1) 
    {
		button_get_status(&btn1,&bstate);
		if(bstate == BUTTON_PRESSED){
led_turn_on(&led1);
_delay_ms(500);
		}
led_turn_off(&led1);
		
	
    }
}

