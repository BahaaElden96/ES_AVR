/*
 * HAL_LED.h
 *
 * Created: 10/29/2020 9:24:58 PM
 *  Author: bahaa
 */ 


#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "../MCAL/DIO_GP.h"
typedef enum {
	LED_OFF,
	LED_ON
}led_status;

typedef struct {
	struct  
	{
		u8 port_name:4;
		u8 pin:4;
	}port_info;
	led_status led_status;
}led_t;


ret_status led_init(led_t *led);
ret_status led_turn_on(led_t *led);
ret_status led_turn_off(led_t *led);
ret_status led_toggle(led_t *led);





#endif /* HAL_LED_H_ */