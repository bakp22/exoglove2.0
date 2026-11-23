/**
 * @file safety_config.h
 * @brief Thresholds shared by the safety-relevant states.
 */
#pragma once
#include <stdint.h>

typedef struct {
    float    x_on;              /**< palm contact enter threshold (above baseline) */
    float    x_off;             /**< palm contact leave threshold (hysteresis, < x_on) */
    float    p_f_safe;          /**< overpressure limit */
    float    sensor_max;        /**< largest valid sensor reading */
    uint32_t debounce_samples;  /**< consecutive contact samples before WAIT_CONTACT */
} SafetyConfig;
