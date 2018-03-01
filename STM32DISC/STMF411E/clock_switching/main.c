//	Minh Nguyen



/*
			This prohram demostrates how to switch the clock source to a High Speed External (HSE)
			clock source
*/

#include <stdint.h>
#include "stm32f411xe.h"

int main(void){

	//	Step 1: Turn on the HSE Oscillator
	RCC_TypeDef *pRCC;
	pRCC  = RCC;
	pRCC->CR |= (1<<16);
	pRCC->CR &= ~(0x1<<0);
	//pRCC->CR &= 0xFFFFFFFE;
	
	// 	Step 2:	Wait until the HSE becomes stable. The crystal ocsillator takes more time than
	//					the RC HSI clock to become stable but is more accurate
	while(! (pRCC->CR & (1<<17)));
	
	//	Step 3: Select HSE as the system clock
	//pRCC->CR &= ~(1<<0);
	//pRCC->CR &= 0xFFFFFFFE;
	pRCC->CFGR &= ~(0x3 << 0); //<-- Clears bit 0, and 1
	pRCC->CFGR &= ~(0x1F << 26); //<-- Clears bit 27-31 for the MCO to mearsure the clock speed
	pRCC->CFGR |= (0x02);
	//pRCC->CFGR |= (0x10 << 27);
	pRCC->CFGR |= 0x80000000;

  
	for(;;);
	return 0;
}
