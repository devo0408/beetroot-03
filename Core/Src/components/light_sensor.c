//
// Created by Denys Vovk on 18.11.2026.
//

#include "../../Inc/components/light_sensor.h"

volatile uint32_t adc_value;
volatile uint32_t adc_ready;

static ADC_HandleTypeDef* adc;

void light_sensor_init(ADC_HandleTypeDef* adc_handle_type_def) {
    adc = adc_handle_type_def;
    adc_value = 0;
    adc_ready = 0;
}

void light_sensor_measurement(void)
{
    HAL_ADC_Start_IT(adc);
    adc_ready = 0;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1)
    {
        adc_value = HAL_ADC_GetValue(hadc);
        adc_ready = 1;
    }
}
