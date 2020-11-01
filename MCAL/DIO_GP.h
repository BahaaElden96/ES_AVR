/*
 * GDIO.h
 *
 * Created: 10/29/2020 11:38:05 AM
 *  Author: bahaa
 */ 


#ifndef GDIO_H_
#define GDIO_H_
#include "../DATATYPES/STD_TYPES.h"
#include "util/delay.h"
/************************************************************************/
/*                        PORT & PINS Definitions                                                        */
/************************************************************************/
#define PORT_MAX_NUMBERS 5U
#define PORT_PIN_MAX_NUMBERS 8U
#define PORT_DIRECTION_INPUT 0x00U
#define PORT_DIRECTION_OUTPUT 0xFFU
#define PIN_MASK_VALUE 1U
#define PORT_MASK_VALUE 0xFF

/************************************************************************/
/*                               MACRO DEFINTIONS OPERATIONS                                       */
/************************************************************************/

//				**************  PINS **********************
#define CLR_BIT(REG,BIT_POS) (REG &= ~(PIN_MASK_VALUE << BIT_POS))
#define SET_BIT(REG,BIT_POS) (REG |= (PIN_MASK_VALUE << BIT_POS))
#define TOG_BIT(REG,BIT_POS) (REG ^= (PIN_MASK_VALUE << BIT_POS))
#define GET_BIT(REG,BIT_POS) ((REG >> BIT_POS) & PIN_MASK_VALUE)

//				**************  PORTS **********************
#define  CLR_PORT(REG) (REG &=~PORT_MASK_VALUE)
#define  SET_PORT(REG) (REG |= PORT_MASK_VALUE)
#define  TOG_PORT(REG) (REG ^= PORT_MASK_VALUE)

typedef enum{
	PIN_LOW=0,
	PIN_HIGH
}pin_logic_t;

typedef enum{
DIRECTION_INPUT=0,
DIRECTION_OUTPUT
}direction_t;	
	
typedef enum {
PIN0,	
PIN1,	
PIN2,	
PIN3,	
PIN4,	
PIN5,	
PIN6,
PIN7
}pin_index;
typedef enum {
	PORTA_INDEX=0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX
	}port_index;
/************************************************************************/
/*                               PINS functions                         */
/************************************************************************/	
ret_status pin_direction_init(port_index port,pin_index pin,direction_t dir);
ret_status pin_get_direction_status(port_index port ,pin_index pin,direction_t *dir);
ret_status pin_write_value(port_index port,pin_index pin ,pin_logic_t logic_value);
ret_status pin_read_value(port_index port ,pin_index pin,pin_logic_t *logic_value);
ret_status pin_toggle_value(port_index port,pin_index pin);
/************************************************************************/
/*								PORT FUNCTIONS                           */
/************************************************************************/
ret_status port_all_init(u8 port_numbers);
ret_status port_direction_init(port_index port,direction_t dir);
ret_status port_get_direction_status(port_index port, direction_t *dir);
ret_status port_write_value(port_index port, u8 value);
ret_status port_read_value(port_index port, u8 *value);
ret_status port_toggle_value(port_index port);

#endif /* GDIO_H_ */