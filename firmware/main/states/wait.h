/**
 * @file wait.h
 * @brief WAIT state: pump off, valve safe, watch the palm sensor and
 *        report when a debounced palm contact should start the ramp.
 *
 * Hardware is passed in through WaitDeps so the logic can be unit
 * tested on a laptop (see firmware/test/).
 */
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "safety_config.h"

/** Result of one wait_step() call. */
typedef enum {
    WAIT_CONTINUE = 0,  /**< keep waiting (fail-safe default) */
    WAIT_CONTACT,       /**< debounced palm contact: OK to ramp */
    WAIT_FAULT,         /**< invalid sensor data */
    WAIT_OVERPRESSURE,  /**< pressure at or above p_f_safe */
} WaitResult;

/** Internal state, zeroed by wait_enter(). */
typedef struct {
    float    palm_baseline;
    float    tip_baseline;
    float    palm_filtered;
    bool     in_contact;
    bool     release_required;
    uint32_t contact_count;
} WaitState;

/** Hardware hooks used by the WAIT state. */
typedef struct {
    void  (*pump_off)(void);
    void  (*valve_safe)(void);
    float (*read_palm)(void);
    float (*read_fingertip)(void);
    void  (*log_fault)(const char *msg);
    void  (*delay_ms)(uint32_t ms);
} WaitDeps;

/** @brief Enter WAIT: make the actuators safe and capture baselines. */
void wait_enter(WaitState *s, const SafetyConfig *cfg, const WaitDeps *d);

/** @brief Run one poll of WAIT. Never returns WAIT_CONTACT on bad data. */
WaitResult wait_step(WaitState *s, const SafetyConfig *cfg, const WaitDeps *d);
