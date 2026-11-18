//
// Created by Denys Vovk on 18.11.2026.
//

#include "../../Inc/components/light_sensor.h"

volatile uint32_t adc_value;
volatile uint32_t adc_ready;

static uint16_t sma_buffer[LIGHT_SENSOR_SMA_WINDOW];

static ADC_HandleTypeDef* adc;

static void light_sensor_buffer_push(uint16_t value)
{
    // Shift every value one position right, the last one falls off
    for (uint32_t i = LIGHT_SENSOR_SMA_WINDOW - 1U; i > 0U; i--) {
        sma_buffer[i] = sma_buffer[i - 1U];
    }

    sma_buffer[0] = value;
}

static uint32_t light_sensor_buffer_average(void)
{
    uint32_t sum = 0;
    uint32_t count = 0;

    for (uint32_t i = 0; i < LIGHT_SENSOR_SMA_WINDOW; i++) {
        if (sma_buffer[i] != 0U) {
            sum += sma_buffer[i];
            count++;
        }
    }

    if (count == 0U) {
        return 0;
    }

    return sum / count;
}

void light_sensor_init(ADC_HandleTypeDef* adc_handle_type_def) {
    adc = adc_handle_type_def;
    adc_value = 0;
    adc_ready = 0;
}

void light_sensor_measurement(void)
{
    adc_ready = 0;
    HAL_ADC_Start_IT(adc);
}

// static uint32_t light_sensor_to_mv(uint32_t raw)
// {
//     // Multiply first so integer division does not lose precision
//     return (raw * LIGHT_SENSOR_VREF_MV) / LIGHT_SENSOR_ADC_MAX;
// }

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1)
    {
        uint32_t raw_adc_value = HAL_ADC_GetValue(hadc);
        light_sensor_buffer_push(raw_adc_value);

        adc_value = light_sensor_buffer_average();

        adc_ready = 1;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        light_sensor_measurement();
    }
}
