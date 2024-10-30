#include <stdint.h>
#include "main.h"

// Define a simple delay function
void delay(volatile uint32_t count) {
    while (count--) {
        __asm("nop"); // No operation (do nothing)
    }
}

int main(void)
{
    // Pointer to AHB1 peripheral clock enable register (GPIOA clock control)
    RCC_AHB1ENR_t volatile *const pClkctrlreg = ADDR_REG_AHB1ENR;

    // Pointer to GPIOA mode register (to configure the pin mode)
    GPIOx_MODE_t volatile *const pPortAModereg = ADDR_REG_GPIOA_MODE;

	// Pointer to GPIOA output data register (to control output levels)
	GPIOx_ODR_t volatile *const pPortAOutreg = ADDR_REG_GPIOA_OA;

    // Enable GPIOA clock
    pClkctrlreg->gpioa_en = CLOCK_ENABLE;

    // Set pin 5 to output mode (01)
    pPortAModereg->pin_5 = MODE_CONF_OUTPUT;



    while (1)
    {
        // Turn on the LED (set pin 5)
        pPortAOutreg->pin_5 = PIN_STATE_HIGH;
        delay(DELAY); // Delay

        // Turn off the LED (clear pin 5)
        pPortAOutreg->pin_5 = PIN_STATE_LOW;
        delay(DELAY); // Delay
    }

    return 0;
}
