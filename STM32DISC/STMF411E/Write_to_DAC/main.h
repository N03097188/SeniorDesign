#ifndef __MAIN_H
#define	__MAIN_H

#include "gpio_driver.h"

/**
	* @brief	Initializes all of port D as Digital outputs
	*	@param	None
	* @retval	None
*/
void gpio_portD_init(void);

/**
	* @brief	Initializes all of port D as Digital outputs
	*	@param	Value to be wriiten to PORTD
	* @retval	None
*/
void write_to_portD(uint16_t value);

#endif
