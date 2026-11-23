/**
 * @file pressure_sensor.h
 * @brief Palm and fingertip pressure sensors.
 */
#pragma once

void  pressure_sensor_init(void);
float pressure_read_palm(void);
float pressure_read_fingertip(void);
