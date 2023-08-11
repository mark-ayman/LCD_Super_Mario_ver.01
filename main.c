/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: First
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#define F_CPU		8000000UL
#include <util/delay.h>

u8 Array_1[]= {
		  0x0E,
		  0x11,
		  0x11,
		  0x0E,
		  0x04,
		  0x0E,
		  0x04,
		  0x0E
};

u8 Array_2[]={
		  0x00,
		  0x15,
		  0x0E,
		  0x04,
		  0x00,
		  0x00,
		  0x00,
		  0x00};

u8 Array_3[]={
			0x00,
			0x00,
			0x00,
			0x00,
			0x04,
			0x0E,
			0x1E,
			0x1F};




u8 Array_4[]={
		  0x11,
		  0x0A,
		  0x04,
		  0x0E,
		  0x0E,
		  0x04,
		  0x0A,
		  0x11
};
int main(void)
{
	u8 obj1,obj2,obj3;
	u8 obj1_R,obj2_R,obj3_R;
	CLCD_voidInit();
	/*Input*/
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_INPUT );
	/*Pull UP*/
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH);

	u8 Local_u8Pressed = 0 ;
	CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_3);
	CLCD_voidSendString((u8*)"...WELCOME...");
	_delay_ms(500);
	for(u8 k = 1 ; k < 16 ; k++){
		CLCD_voidSetPosition(CLCD_ROW_1 ,k);
		CLCD_voidSendString((u8*)"...Mark Ayman...");
		_delay_ms(250);
		CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
		_delay_ms(250);
	}

	_delay_ms(1000);
	while(1)
	{
		for(u8 i = 1 ; i < 16 ; i++)
		{

				CLCD_voidSendExtraChar(0 , Array_1 , obj1_R=CLCD_ROW_2 , obj1=i);
				CLCD_voidSendExtraChar(1 , Array_2 , CLCD_ROW_1 , (16-i));
				_delay_ms(250);
				CLCD_voidSendExtraChar(2 , Array_3 , obj3_R=CLCD_ROW_2 ,obj3=(16-2*i));
				_delay_ms(250);
				CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
				if(((obj3-1)==obj1)/*&&(obj3_R==obj1_R)*/){
					CLCD_voidSendExtraChar(4 , Array_4 , obj1_R , obj1);
					_delay_ms(250);
					CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

				}
				Local_u8Pressed = DIO_u8GetPinValue(DIO_PORTA , DIO_PIN0 );
				if(Local_u8Pressed == 0 ){
					CLCD_voidSendExtraChar(0 , Array_1 , CLCD_ROW_1 , i);
					_delay_ms(500);
					CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
					_delay_ms(500);
					Local_u8Pressed = DIO_u8GetPinValue(DIO_PORTA , DIO_PIN0 );
				}
		}

	}

	return 0 ;
}

