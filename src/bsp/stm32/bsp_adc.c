#include "bsp_adc.h"

uint16_t BSP_ADC_Read(void){
    ADC1->CR2 |= (1U << 30);

    while ((ADC1->SR & (1U << 1)) == 0U){
        //Wait the end of the conversation (EOC = 1)
    }
    return (uint16_t)ADC1->DR;
}