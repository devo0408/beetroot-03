//
// Created by Denys Vovk on 18.11.2026.
//

#include "../../Inc/components/light_sensor.h"

#include "main.h"

volatile uint32_t adc_value = 0;
volatile uint8_t  adc_ready = 0;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1)
    {
        adc_value = HAL_ADC_GetValue(hadc);
        adc_ready = 1;
    }
}
