/*
 * HAL_LED.c
 *
 * Created: 10/29/2020 9:26:19 PM
 *  Author: bahaa
 */ 
#include "HAL_LED.h"


ret_status led_init(led_t *led){
	ret_status ret=R_NOK;
	if(led == NULL || led->port_info.port_name > PORT_MAX_NUMBERS || led->port_info.pin > PORT_PIN_MAX_NUMBERS){
		
		return ret;
	}else{
		pin_direction_init(led->port_info.port_name,led->port_info.pin,DIRECTION_OUTPUT);
		pin_write_value(led->port_info.port_name,led->port_info.pin,PIN_LOW);
		ret = R_OK;
	}
	return ret;
}
ret_status led_turn_on(led_t *led){
		ret_status ret=R_NOK;
		if(led == NULL || led->port_info.port_name > PORT_MAX_NUMBERS || led->port_info.pin > PORT_PIN_MAX_NUMBERS){
			return ret;
			}else{
				led->led_status=LED_ON;
				pin_write_value(led->port_info.port_name,led->port_info.pin,PIN_HIGH);
				ret=R_OK;
			}
			return ret;
}
ret_status led_turn_off(led_t *led){
		ret_status ret=R_NOK;
		if(led == NULL || led->port_info.port_name > PORT_MAX_NUMBERS || led->port_info.pin > PORT_PIN_MAX_NUMBERS){
			return ret;
			}else{
				led->led_status=LED_OFF;
			pin_write_value(led->port_info.port_name,led->port_info.pin,PIN_LOW);
			ret=R_OK;
		}
		return ret;
}
ret_status led_toggle(led_t *led){
		ret_status ret=R_NOK;
		if(led == NULL || led->port_info.port_name > PORT_MAX_NUMBERS || led->port_info.pin > PORT_PIN_MAX_NUMBERS){
			return ret;
			}else{
			pin_toggle_value(led->port_info.port_name,led->port_info.pin);
			ret=R_OK;
		}
		return ret;
	
}
