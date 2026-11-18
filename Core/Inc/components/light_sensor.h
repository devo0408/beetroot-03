//
// Created by Denys Vovk on 18.11.2026.
//

#ifndef BEETROOT_03_LIGHT_SENSOR_H
#define BEETROOT_03_LIGHT_SENSOR_H

#include "main.h"

#define LIGHT_SENSOR_SMA_WINDOW 8U
#define LIGHT_SENSOR_VREF_MV    VDD_VALUE  /* ADC reference voltage in mV */
#define LIGHT_SENSOR_ADC_MAX    4095U      /* 12-bit ADC full scale */

void light_sensor_init(ADC_HandleTypeDef *hadc);

void light_sensor_measurement(void);

#endif //BEETROOT_03_LIGHT_SENSOR_H
