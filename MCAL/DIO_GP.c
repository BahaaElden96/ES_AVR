/*
 * DIO_GP.c
 *
 * Created: 10/29/2020 11:39:14 AM
 *  Author: bahaa
 */ 
#include "DIO_GP.h"
#include "avr/io.h"

static volatile u8 *ddr_registers[]={&DDRA,&DDRB,&DDRC,&DDRD};
static volatile u8 *out_port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD};
static volatile u8 *input_pin_registers[]={&PINA,&PINB,&PINC,&PIND};
	
ret_status pin_direction_init(port_index port,pin_index pin,direction_t dir){
	ret_status ret=R_NOK;
	if ( port <ZERO_INIT || port > PORT_MAX_NUMBERS - 1 || pin <ZERO_INIT || pin > PORT_PIN_MAX_NUMBERS -1)
	{
		return ret;
	}else{
		ret = R_OK;
		switch (dir){
			case DIRECTION_INPUT : CLR_BIT(*ddr_registers[port],pin);
			break;
			case DIRECTION_OUTPUT : SET_BIT(*ddr_registers[port],pin);
			break;
			default:
			ret=R_NOK;
			break;
		}
		return ret;
	}
	
}



ret_status pin_get_direction_status(port_index port ,pin_index pin,direction_t *dir){
	ret_status ret=R_NOK;
	if ( port <ZERO_INIT || port > PORT_MAX_NUMBERS - 1 || pin <ZERO_INIT || pin > PORT_PIN_MAX_NUMBERS -1 || NULL == dir)
	{
		return ret;
	}else{
			*dir=GET_BIT(*ddr_registers[port],pin);
			ret=R_OK;
	}
	return ret;
}





ret_status pin_write_value(port_index port,pin_index pin ,pin_logic_t logic_value){
		ret_status ret=R_NOK;
		if ( port <ZERO_INIT || port > PORT_MAX_NUMBERS - 1 || pin <ZERO_INIT || pin > PORT_PIN_MAX_NUMBERS -1)
		{
			return ret;
			}else{
			switch(logic_value){
				case PIN_LOW:
				CLR_BIT(*out_port_registers[port],pin);
				break;
			case PIN_HIGH:
				SET_BIT(*out_port_registers[port],pin);
			break;
			}
			ret=R_OK;
		}
		return ret;	
}
ret_status pin_read_value(port_index port ,pin_index pin,pin_logic_t *logic_value){
ret_status ret=R_NOK;
if ( port <ZERO_INIT || port > PORT_MAX_NUMBERS - 1 || pin <ZERO_INIT || pin > PORT_PIN_MAX_NUMBERS -1 )
{
	return ret;
  }else
  {
	*logic_value=GET_BIT(*input_pin_registers[port],pin);
	ret=R_OK;
   }
return ret;
}

ret_status pin_toggle_value(port_index port,pin_index pin){
ret_status ret=R_NOK;
if ( port <ZERO_INIT || port > PORT_MAX_NUMBERS - 1 || pin <ZERO_INIT || pin > PORT_PIN_MAX_NUMBERS -1)
{
	return ret;
}else
{
	TOG_BIT(*out_port_registers[port],pin);
	ret=R_OK;
}
return ret;
}	
	
	
	
	
	






/************************************************************************/
/*								PORT FUNCTIONS                                                                     */
/************************************************************************/
ret_status port_all_init(u8 port_numbers){
	//port default init
ret_status ret =R_NOK;
if((port_numbers >PORT_MAX_NUMBERS-1)|| (port_numbers <ZERO_INIT))
return ret;

port_index LPort =ZERO_INIT;
for (LPort = PORTA_INDEX ;LPort <port_numbers;LPort++)
{
		CLR_PORT(*ddr_registers[LPort]);
}
		ret=R_OK;

return ret;
}

ret_status port_direction_init(port_index port,direction_t dir){
ret_status ret=R_NOK;
if (port < ZERO_INIT ||port > PORT_MAX_NUMBERS-1)
{
	return ret;
}else{
switch(dir){
	case DIRECTION_OUTPUT:
	ret=R_OK;
			SET_PORT(*ddr_registers[port]);
	break;
	
	case DIRECTION_INPUT:
	ret=R_OK;
			CLR_PORT(*ddr_registers[port]);
	break;
	default:
	ret =R_NOK;
}}
return ret;	
}
ret_status port_get_direction_status(port_index port, direction_t *dir){
	ret_status ret=R_NOK;
	if((port >PORT_MAX_NUMBERS -1)|| (port <0)|| (NULL == dir)){
		
		return ret;
	}else{
		*dir = *ddr_registers[port];
		ret=R_OK;
	}
	
	return ret;
}
ret_status port_write_value(port_index port, u8 value){
		ret_status ret=R_NOK;
if((port >PORT_MAX_NUMBERS -1)|| (port <0)){
ret =R_NOK;

}else{
	*out_port_registers[port]=value;
	ret=R_OK;
}	
return ret;	
}

ret_status port_read_value(port_index port, u8 *value){
			ret_status ret=R_NOK;
			if((port >PORT_MAX_NUMBERS -1)|| (port <0)){
				ret =R_NOK;

				}else{
					*value =*input_pin_registers[port];
					ret=R_OK;
				}
	return ret;
	
}
ret_status port_toggle_value(port_index port){
	ret_status ret=R_NOK;
	if((port >PORT_MAX_NUMBERS -1)|| (port <0)){
		ret =R_NOK;

		}else{
			TOG_PORT(*out_port_registers[port]);
		}
		return ret;
}