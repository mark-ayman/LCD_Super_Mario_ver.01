/*******************************************************/
/****   Author : Mohamed khaled       ******************/
/****   SWC:          CLCD             ******************/
/****   Date :        5/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/

/*	Includes */
	/*Libraries*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"

/*CLCD*/
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

void CLCD_voidInit		(	void	)
{
	// Data Port --> OUTPUT
	DIO_voidSetPortDirection(CLCD_DATA_PORT , DIO_OUTPUT);
	// Rs , RW , EN --> OUTPUT
	DIO_voidSetPinDirection(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CTRL_PORT , CLCD_EN_PIN , DIO_OUTPUT);

	/* Initilization Sequence */
	_delay_ms(50);
	/*Function Set */
	CLCD_voidSendCommand(0b00111000);
	_delay_us(50);
	/*Display ON/OFF*/
	CLCD_voidSendCommand(0b00001100);
	_delay_us(50);
	/*Display Clear */
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);
	/*Entry Mode Set */
	CLCD_voidSendCommand(0b00000110);

}

void CLCD_voidSendCommand	(u8 Copy_u8Command	)
{
	/*Rs -> Low (To Send Command )*/
	DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_LOW);
	/*Rw -> Low	(To Write)*/
	DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_LOW);
	/*	Send Command */
	DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8Command);
	/*Enable Sequence */
	DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , DIO_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , DIO_LOW);
	_delay_ms(1);

}
void CLCD_voidSendData		(u8 Copy_u8Data		)
{
	/*Rs -> High (To Send Data )*/
		DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_HIGH);
		/*Rw -> Low	(To Write)*/
		DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_LOW);
		/*	Send Command */
		DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8Data);
		/*Enable Sequence */
		DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , DIO_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_EN_PIN , DIO_LOW);
		_delay_ms(1);

}


void CLCD_voidSetPosition	(u8 Copy_u8Row , u8 Copy_u8Col)
{
	switch(Copy_u8Row)
	{
	case CLCD_ROW_1 :	CLCD_voidSendCommand(	0x80 + Copy_u8Col - 1	);
		break;
	case CLCD_ROW_2 :	CLCD_voidSendCommand(	0x80+ 64 + Copy_u8Col - 1	);
		break ;
	default :
		break;
	}
}

void CLCD_voidSendExtraChar	(u8 Copy_u8PatternLocation , u8 * Copy_pu8ExtraChar , u8 Copy_u8Row , u8 Copy_u8Col )
{
	u8 Local_u8Address = 0 ;
	Local_u8Address = Copy_u8PatternLocation * 8 ;
	/*Go To CGRAM*/
	CLCD_voidSendCommand( 64 + Local_u8Address );
	/*Generate Charachter  inside CGRAM*/
	for(u8 i = 0 ; i < 8 ; i++)
	{
		CLCD_voidSendData(Copy_pu8ExtraChar[i]);
	}
	/*Back to DDRAM */
	CLCD_voidSetPosition(Copy_u8Row , Copy_u8Col);
	/*Draw Charachter on display */
	CLCD_voidSendData(Copy_u8PatternLocation);
}

void CLCD_voidSendString	(u8 *Copy_pu8String )
{
	u8 Local_u8Iterator = 0 ;
	while(Copy_pu8String[Local_u8Iterator] != '\0')
	{
		CLCD_voidSendData(Copy_pu8String[Local_u8Iterator]);
		Local_u8Iterator ++ ;
	}
}






