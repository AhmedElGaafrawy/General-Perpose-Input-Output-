/*
 * DIO_int.h
 *
 *  Created on: Apr 2, 2020
 *      Author: hp
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


/*****************************************************************************/
/**********   Use these enumerators to pass them to your function   **********/
/*****************************************************************************/

enum
{
	PORT_A,			PORT_B,			PORT_C,			PORT_D,

	PIN0=0,			PIN1,			PIN2,			PIN3,
	PIN4,			PIN5,			PIN6,			PIN7,
	PIN8,			PIN9,			PIN10,			PIN11,
	PIN12,			PIN13,			PIN14,			PIN15,
	PIN16,			PIN17,			PIN18,			PIN19,
	PIN20,			PIN21,			PIN22,			PIN23,
	PIN24,			PIN25,			PIN26,			PIN27,
	PIN28,			PIN29,			PIN30,			PIN31,

	DIO_PIN_INPUT=0,	DIO_PIN_OUTPUT,
	DIO_PIN_LOW=0,		DIO_PIN_HIGH,

	ALL_PORT_INPUT=0,				ALL_PORT_OUTPUT=0xFF,
	ALL_PORT_LOW=0,					ALL_PORT_HIGH=0xFF,

}DIO;

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/**************   Use these function to configure DIO by PINS   **************/
/*****************************************************************************/

ERROR_STATES DIO_PINS_enuInit			(void);

ERROR_STATES DIO_PINS_enuSetPinDirection(u8 Copy_u8PinID , u8 Copy_u8PinDirection);

ERROR_STATES DIO_PINS_enuSetPinValue	(u8 Copy_u8PinID , u8 Copy_u8PinValue);

ERROR_STATES DIO_PINS_enuTogglePin		( u8 Copy_u8PinID );

ERROR_STATES DIO_PINS_enuGetPinValue	(u8 Copy_u8PinID , u8 * Copy_Pu8PinValue);

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*************   Use these function to  configure DIO by PORTS   *************/
/*****************************************************************************/

ERROR_STATES DIO_enuSetPinDirection 	(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection);

ERROR_STATES DIO_enuSetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue);

ERROR_STATES DIO_enuTogglePinValue		(u8 Copy_u8PortID , u8 Copy_u8PinID );

ERROR_STATES DIO_enuGetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_Pu8PinValue);

ERROR_STATES DIO_enuSetPortDirection 	(u8 Copy_u8PortID , u8 Copy_u8PortDirection);

ERROR_STATES DIO_enuSetPortValue		(u8 Copy_u8PortID , u8 Copy_u8PortValue);

ERROR_STATES DIO_enuTogglePortValue		(u8 Copy_u8PortID);

ERROR_STATES DIO_enuGetPortValue		(u8 Copy_u8PortID , u8 * Copy_Pu8PortValue);

/*****************************************************************************/
/*****************************************************************************/


#endif /* DIO_INT_H_ */
