#include <stdint.h>
#include "stm32f411xe.h"

int main(void){
	ADC_TypeDef *pADC;
	RCC_TypeDef *pRCC;
	GPIO_TypeDef *pGPIO;
	pADC = ADC1;
	pRCC = RCC;
	pGPIO = GPIOA;
	//First enable the clock, then, access the peripheral register
	pRCC->APB2ENR |= (1<<8);
	pRCC->AHB1ENR |= (1<<0);
	pADC->CR1 = 0x55;
	pGPIO->PUPDR = 0x11;
}
