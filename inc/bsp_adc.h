#include <stdint.h>

#ifndef BSP_ADC_H
#define BSP_ADC_H

#define ADC1_BASE 0x40012000

typedef struct {
    volatile uint32_t SR;     // Status register (EOC flag)
    volatile uint32_t CR1;    // Control register 1
    volatile uint32_t CR2;    // Control register 2 (SWSTART)
    volatile uint32_t SMPR1;  // Sample time register 1 (channels 10-18)
    volatile uint32_t SMPR2;  // Sample time register 2 (channels 0-9)
    volatile uint32_t JOFR1;  // Injected channel offset register 1
    volatile uint32_t JOFR2;  // Injected channel offset register 2
    volatile uint32_t JOFR3;  // Injected channel offset register 3
    volatile uint32_t JOFR4;  // Injected channel offset register 4
    volatile uint32_t HTR;    // Watchdog high threshold register
    volatile uint32_t LTR;    // Watchdog low threshold register
    volatile uint32_t SQR1;   // Regular sequence register 1
    volatile uint32_t SQR2;   // Regular sequence register 2
    volatile uint32_t SQR3;   // Regular sequence register 3
    volatile uint32_t JSQR;   // Injected sequence register
    volatile uint32_t DR;     // Regular data register
} ADC_TypeDef;

#define ADC1 ((ADC_TypeDef *) ADC1_BASE)

uint16_t BSP_ADC_Read(void);

#endif /* BSP_ADC_H */

