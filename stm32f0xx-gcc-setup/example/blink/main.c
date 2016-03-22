#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"

GPIO_InitTypeDef  GPIO_InitStructure;

/// Spin delay
void delay(int count)
{
    // volatile so that the compiler doesn't optimise it out
    volatile int i;

    for (i = 0; i < count; i++)
    {
    }
}

/// Main function.  Called by the startup code.
int main(void)
{

  /* GPIOC Periph clock enable */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);


    for (;;)
    {
      // Turn on both LEDs
      GPIOC->BSRR = 0x0300;

      // Around 1/4 of a second
      delay(2400000);

      // Turn off the first led
      GPIOC->BRR = 0x0100;

      delay(2400000);

      // Turn off the second LED and the on the first
      GPIOC->BRR = 0x0200;
      GPIOC->BSRR = 0x0100;

      delay(2400000);

      // Turn off first
      GPIOC->BRR = 0x0100;

      delay(2400000);
    }
}
