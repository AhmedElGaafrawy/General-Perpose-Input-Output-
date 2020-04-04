/*
 * DIO_prog.c
 *
 *  Created on: Apr 2, 2020
 *      Author: hp
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"

#include "DIO_priv.h"
#include "DIO_config.h"

/*****************************************************************************/
/**************   Use these function to configure DIO by PINS   **************/
/*****************************************************************************/

ERROR_STATES DIO_PINS_enuInit			(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	DDRA= DIO_U8_PORTA_DIRECTION;

	DDRB= DIO_U8_PORTB_DIRECTION;

	DDRC= DIO_U8_PORTC_DIRECTION;

	DDRD= DIO_U8_PORTD_DIRECTION;

	error_enuState = ES_OK;
	return error_enuState;
}

ERROR_STATES DIO_PINS_enuSetPinDirection(u8 Copy_u8PinID , u8 Copy_u8PinDirection)
{
	ERROR_STATES error_enuState =ES_OK;


	if( Copy_u8PinID < DIO_PIN8 )
	{
		if 		(Copy_u8PinDirection)		DDRA|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinDirection)		DDRA&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN8 && Copy_u8PinID < DIO_PIN16 )
	{
		Copy_u8PinID -= DIO_PIN8;
		if 		(Copy_u8PinDirection)		DDRB|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinDirection)		DDRB&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN16 && Copy_u8PinID < DIO_PIN24 )
	{
		Copy_u8PinID -= DIO_PIN16;
		if 		(Copy_u8PinDirection)		DDRC|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinDirection)		DDRC&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN24 && Copy_u8PinID < DIO_PIN31 )
	{
		Copy_u8PinID -= DIO_PIN24;
		if 		(Copy_u8PinDirection)		DDRD|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinDirection)		DDRD&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else
	{
		error_enuState	=	ES_NOT_SELECTED;
	}

	return error_enuState;
}


ERROR_STATES DIO_PINS_enuSetPinValue	(u8 Copy_u8PinID , u8 Copy_u8PinValue)
{
	ERROR_STATES error_enuState =ES_OK;

	if ( Copy_u8PinID < DIO_PIN8)
	{
		if 		(Copy_u8PinValue)		PORTA|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinValue)		PORTA&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN8 && Copy_u8PinID < DIO_PIN16 )
	{
		Copy_u8PinID -= DIO_PIN8;
		if 		(Copy_u8PinValue)		PORTB|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinValue)		PORTB&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN16 && Copy_u8PinID < DIO_PIN24 )
	{
		Copy_u8PinID -= DIO_PIN16;
		if 		(Copy_u8PinValue)		PORTC|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinValue)		PORTC&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else if (Copy_u8PinID >= DIO_PIN24 && Copy_u8PinID < DIO_PIN31 )
	{
		Copy_u8PinID -= DIO_PIN24;
		if 		(Copy_u8PinValue)		PORTD|= (ONE<<Copy_u8PinID);
		else if (! Copy_u8PinValue)		PORTD&=~(ONE<<Copy_u8PinID);
		else	error_enuState 		=		ES_OUT_OF_RANGE;
	}

	else
	{
		error_enuState	=	ES_NOT_SELECTED;
	}

	return error_enuState;
}


ERROR_STATES DIO_PINS_enuTogglePin		( u8 Copy_u8PinID )
{
	ERROR_STATES error_enuState =ES_NOT_OK;


	if ( Copy_u8PinID < DIO_PIN8 )
	{
		PORTA^= (ONE<<Copy_u8PinID);
		error_enuState =ES_OK;
	}

	else if (Copy_u8PinID >= DIO_PIN8 && Copy_u8PinID < DIO_PIN16 )
	{
		Copy_u8PinID -= DIO_PIN8;
		PORTB^= (ONE<<Copy_u8PinID);
		error_enuState =ES_OK;
	}

	else if (Copy_u8PinID >= DIO_PIN16 && Copy_u8PinID < DIO_PIN24 )
	{
		Copy_u8PinID -= DIO_PIN16;
		PORTC^= (ONE<<Copy_u8PinID);
		error_enuState =ES_OK;
	}
	else if (Copy_u8PinID >= DIO_PIN24 && Copy_u8PinID < DIO_PIN31 )
	{
		Copy_u8PinID -= DIO_PIN24;
		PORTD^= (ONE<<Copy_u8PinID);
		error_enuState =ES_OK;
	}

	else
	{
		error_enuState	=	ES_NOT_SELECTED;
	}

	return error_enuState;
}


ERROR_STATES DIO_PINS_enuGetPinValue	(u8 Copy_u8PinID , u8 * Copy_Pu8PinValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	if ( Copy_u8PinID < DIO_PIN8 )
	{
		*Copy_Pu8PinValue= ((PINA>>Copy_u8PinID) & ONE );
		error_enuState =ES_OK;
	}

	else if (Copy_u8PinID >= DIO_PIN8 && Copy_u8PinID < DIO_PIN16 )
	{
		Copy_u8PinID -= DIO_PIN8;
		*Copy_Pu8PinValue= ((PINB>>Copy_u8PinID) & ONE );
		error_enuState =ES_OK;
	}

	else if (Copy_u8PinID >= DIO_PIN16 && Copy_u8PinID < DIO_PIN24 )
	{
		Copy_u8PinID -= DIO_PIN16;
		*Copy_Pu8PinValue= ((PINC>>Copy_u8PinID) & ONE );
		error_enuState =ES_OK;
	}

	else if (Copy_u8PinID >= DIO_PIN24 && Copy_u8PinID < DIO_PIN31 )
	{
		Copy_u8PinID -= DIO_PIN24;
		*Copy_Pu8PinValue= ((PIND>>Copy_u8PinID) & ONE );
		error_enuState =ES_OK;
	}

	else
	{
		error_enuState	=	ES_NOT_SELECTED;
	}

	return error_enuState;
}


/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*************   Use these function to  configure DIO by PORTS   *************/
/*****************************************************************************/


ERROR_STATES DIO_enuSetPinDirection 	(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuSetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuTogglePinValue		(u8 Copy_u8PortID , u8 Copy_u8PinID )
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuGetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_Pu8PinValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuSetPortDirection 	(u8 Copy_u8PortID , u8 Copy_u8PortDirection)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuSetPortValue		(u8 Copy_u8PortID , u8 Copy_u8PortValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuTogglePortValue		(u8 Copy_u8PortID , u8 Copy_u8PortValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


ERROR_STATES DIO_enuGetPortValue		(u8 Copy_u8PortID , u8 * Copy_Pu8PortValue)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	return error_enuState;
}


/*****************************************************************************/
/*****************************************************************************/
