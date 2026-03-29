
#include<switch.h>

void switch_init(uint8_t pin)
{
	RCC->AHB1ENR |= BV(GPIOA_CLK_EN);

	// input mode
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));

	// enable pull-down (10)
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	SWITCH_GPIO->PUPDR |= BV(pin * 2 + 1);
}

uint8_t switch_status(uint8_t pin)
{
	return SWITCH_GPIO->IDR & BV(pin) ? 1 : 0;
}








