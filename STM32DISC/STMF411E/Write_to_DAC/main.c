#include "gpio_driver.h"
#include "main.h"


void pinInit(void);

int main(void){

	gpio_portD_init();
	write_to_portD(0xFFFF);
	while(1){}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Supporting Functions//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void gpio_portD_init(void){

	uint8_t count;
	gpio_pin_conf_t portD_pin_conf;
	
	_HAL_RCC_GPIOD_CLK_ENABLE();
	
	portD_pin_conf.mode       = GPIO_PIN_OUTPUT_MODE;
	portD_pin_conf.op_type    = GPIO_PIN_OP_TYPE_PUSHPULL;
	portD_pin_conf.speed		 	=	GPIO_PIN_SPEED_MEDIUM;
	portD_pin_conf.pull				= GPIO_PIN_NO_PULL_PUSH;
	
	for(count=0 ; count<=15 ; count++){
	
		portD_pin_conf.pin = count;
		hal_gpio_init(GPIO_PORT_D, &portD_pin_conf);
	}
}

void write_to_portD(uint16_t value){
	hal_gpio_write_to_port(GPIOD, value);
}
