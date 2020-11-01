/*
 * HAL_BUT.c
 *
 * Created: 10/29/2020 9:26:36 PM
 *  Author: bahaa
 */ 
#include "HAL_BUT.h"
ret_status button_init(button_t *btn){
	ret_status ret=R_NOK;
	if((NULL == btn || (btn->port_name>PORT_MAX_NUMBERS-1) ||(btn->pin >PORT_PIN_MAX_NUMBERS-1))){
	return ret;
	}else{
	pin_direction_init(btn->port_name,btn->pin,DIRECTION_INPUT);
	ret =R_OK;
	}
	return ret;
}
ret_status button_get_status(button_t *btn, button_status *bstatus){
		ret_status ret=R_NOK;
		if( (NULL == btn) || (btn->port_name>PORT_MAX_NUMBERS-1) ||(btn->pin >PORT_PIN_MAX_NUMBERS-1) ){
			return ret;
			}else{
				pin_logic_t *p;
pin_read_value(btn->port_name,btn->pin,bstatus);
//*bstatus=*p;
btn->button_status=*p;
			ret =R_OK;
		}
		return ret;
}