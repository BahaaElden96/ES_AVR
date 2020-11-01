/*
 * STD_TYPES.h
 *
 * Created: 10/29/2020 11:40:43 AM
 *  Author: bahaa
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
#ifndef NULL
#define NULL ((void *)0)
#endif
/*unsgined*/
typedef unsigned char u8;
typedef unsigned short int u16t;
typedef unsigned long int u32;

/*signed*/
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

/*floating */
typedef float f32;
typedef double f64;

#define ZERO_INIT 0
#define TRUE 1
#define FALSE 0

typedef enum{
R_NOK=0,
R_OK
}ret_status;

#endif /* STD_TYPES_H_ */