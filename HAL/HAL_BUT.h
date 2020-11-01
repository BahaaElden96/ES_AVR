/*
 * HAL_BUT.h
 *
 * Created: 10/29/2020 9:25:21 PM
 *  Author: bahaa
 */ 


#ifndef HAL_BUT_H_
#define HAL_BUT_H_
#include "../MCAL/DIO_GP.h"
typedef enum {
 BUTTON_NOT_PRESSED,
 BUTTON_PRESSED
}button_status;

typedef struct {
	u8 port_name:4;
	u8 pin:3;
	u8 button_status :1;
}button_t;
ret_status button_init(button_t *btn);
ret_status button_get_status(button_t *btn, button_status *bstatus);
#endif /* HAL_BUT_H_ */