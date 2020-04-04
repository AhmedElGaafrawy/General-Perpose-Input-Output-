/*
 * main.c
 *
 *  Created on: Apr 2, 2020
 *      Author: hp
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"

#include "../MCAL/DIO_int.h"



int main(void)
{
	DIO_PINS_enuInit();
	DIO_PINS_enuSetPinValue(PIN9 ,1);
	u8 val=1;
	while (1)
	{
		DIO_PINS_enuGetPinValue(PIN9, &val);
		if (! val)
		{
			DIO_PINS_enuTogglePin(PIN0);
			DIO_PINS_enuTogglePin(PIN2);
			while (! val)DIO_PINS_enuGetPinValue(PIN9, &val);
		}
	}

	return 0;
}

