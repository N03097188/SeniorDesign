#include <stdint.h>
#include "stm32f411xe.h"

RTC_TypeDef *pRTC;

int main(void){
	//pRTC = RTC;
	pRTC->ALRMBR = 0x24;
}
