/*
 * LED_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: First
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


#define LED_ACTIVE_HIGH			1
#define LED_ACTIVE_LOW			0

typedef struct
{
	u8 Port ;
	u8 Pin  ;
	u8 ActiveState ;
}LED_t;

void LED_voidInit		(LED_t * Copy_pstructLed );
void LED_voidOn			(LED_t * Copy_pstructLed );
void LED_voidOff		(LED_t * Copy_pstructLed );

#endif /* HAL_LED_LED_INTERFACE_H_ */
