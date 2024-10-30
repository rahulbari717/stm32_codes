#include <stdint.h>

// Function to introduce a delay (approximately 1 second for STM32 systems)
void delay_ms(uint32_t delay)
{
    for(uint32_t i = 0; i < delay * 1000; i++);
}

int main(void)
{
    // 1. Pointer to AHB1 peripheral clock enable register (GPIOA clock control)
    uint32_t *pClkctrlreg = (uint32_t*) 0x40023830;

    // 2. Pointer to GPIOA mode register (to configure the pin mode)
    uint32_t *pPortAModereg = (uint32_t*) 0x40020000;

    // 3. Pointer to GPIOA output data register (to control output levels)
    uint32_t *pPortAOutreg = (uint32_t*) 0x40020014;

    // Step 1: Enable the clock for GPIOA in the AHB1ENR register
    *pClkctrlreg |= 0x01;  // Set bit 0 to enable GPIOA clock

    // Step 2: Configure GPIOA pin 5 as output
    *pPortAModereg &= 0xFFFFF3FF;  // Clear bits 10 and 11 (pin 5 mode)
    *pPortAModereg |= 0x00000400;  // Set bit 10 to 1 (output mode)

    // Step 3: Set GPIOA pin 5 (onboard LED) high to turn it ON
     *pPortAOutreg |= 0x0020;  // Set bit 5 to 1 (output high)

    // Infinite loop to keep the program running
//    for(;;)
//	{
//    	// Toggle GPIOA pin 5 (LED ON)
//    	        *pPortAOutreg |= 0x0020;  // Set bit 5 to 1 (turn ON)
//    	        delay_ms(1000);  // Delay approximately 1 second
//
//    	        // Toggle GPIOA pin 5 (LED OFF)
//    	        *pPortAOutreg &= ~0x0020;  // Clear bit 5 (turn OFF)
//    	        delay_ms(1000);  // Delay approximately 1 second
//	}
}
