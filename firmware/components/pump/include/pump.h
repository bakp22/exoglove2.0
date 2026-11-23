/**
 * @file pump.h
 * @brief Pump driver.
 */
#pragma once

void pump_init(void);
void pump_off(void);
void pump_set_duty(float duty); /* 0.0 .. 1.0 */
