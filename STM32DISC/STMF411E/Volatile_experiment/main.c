	
#include <stdint.h>

#define SRAM_ADRESS1	0X20000004U

int main(void){
	
	uint32_t value = 0;
	uint32_t volatile *p = (uint32_t *) SRAM_ADRESS1;
	
	while(1){
		value = *p;
		if(value) break;}
	
	while(1);
}
