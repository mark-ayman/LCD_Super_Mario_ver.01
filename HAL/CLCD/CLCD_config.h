/*******************************************************/
/****   Author : Mohamed khaled       ******************/
/****   SWC:          CLCD             ******************/
/****   Date :        5/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/
#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_


/*
 Options:
 1.	 DIO_PORTA
 2.	 DIO_PORTB
 3.	 DIO_PORTC
 4.	 DIO_PORTD
 * */
#define CLCD_DATA_PORT			DIO_PORTC

#define CLCD_CTRL_PORT			DIO_PORTD

/*
 Options:
 1.	 DIO_PIN0
 2.	 DIO_PIN1
 3.	 DIO_PIN2
 4.	 DIO_PIN3
 5.  DIO_PIN4
 .
.
.

 * */
#define CLCD_RS_PIN				DIO_PIN2
#define CLCD_RW_PIN				DIO_PIN1
#define CLCD_EN_PIN				DIO_PIN0



#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
