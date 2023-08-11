/*
 * LED_program.c
 *
 *  Created on: Aug 3, 2023
 *      Author: First
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"



void LED_voidInit		(LED_t * Copy_pstructLed )
{
	DIO_voidSetPinDirection(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_OUTPUT);
	switch(Copy_pstructLed -> ActiveState)
	{
	case LED_ACTIVE_HIGH :
		DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_LOW);
		break;
	case LED_ACTIVE_LOW :
		DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_HIGH);
		break;
	default:
		break;
	}
}
void LED_voidOn			(LED_t * Copy_pstructLed )
{
	switch(Copy_pstructLed -> ActiveState)
		{
		case LED_ACTIVE_HIGH :
			DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_HIGH);
			break;
		case LED_ACTIVE_LOW :
			DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_LOW);
			break;
		default:
			break;
		}
}
void LED_voidOff		(LED_t * Copy_pstructLed )
{
	switch(Copy_pstructLed -> ActiveState)
		{
		case LED_ACTIVE_HIGH :
			DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_LOW);
			break;
		case LED_ACTIVE_LOW :
			DIO_voidSetPinValue(Copy_pstructLed->Port , Copy_pstructLed->Pin , DIO_HIGH);
			break;
		default:
			break;
		}
}

