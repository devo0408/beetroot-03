//
// Created by Denys Vovk on 18.11.2026.
//

#ifndef BEETROOT_03_LIGHT_SENSOR_H
#define BEETROOT_03_LIGHT_SENSOR_H

#include "main.h"

void light_sensor_init(ADC_HandleTypeDef *hadc);

void light_sensor_measurement(void);

#endif //BEETROOT_03_LIGHT_SENSOR_H
