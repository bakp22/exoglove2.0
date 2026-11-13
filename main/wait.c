/**
 * @file wait.c
 * @brief Skeleton of the Wait state. See wait.h and docs/TASKS.md.
 *
 * INVARIANT: pump is OFF and valve is SAFE whenever Wait is active.
 * INVARIANT: ramp is never entered on fingertip-only, a 1-sample spike,
 *            an already-pressed palm at entry, or invalid sensor data.
 */
#include "wait.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

void wait_enter(WaitState *s, const SafetyConfig *cfg, const WaitDeps *d)
{
    (void)cfg;
    memset(s, 0, sizeof(*s));

    /* TODO 1: d->pump_off(); d->valve_safe();
     * TODO 2: capture baselines: s->palm_baseline / s->tip_baseline
     * TODO 3: clear filter + debounce state (memset above covers zeros;
     *         decide if the filter needs seeding from the first sample)
     * TODO 4: read palm; if already > x_on, s->release_required = true
     */
    (void)d;
}

WaitResult wait_step(WaitState *s, const SafetyConfig *cfg, const WaitDeps *d)
{
    (void)s; (void)cfg;

    /* TODO 1: p = d->read_palm(); t = d->read_fingertip();
     * TODO 2: invalid (isnan, <0, >sensor_max, stuck-high) -> reset debounce,
     *         d->log_fault(...), return WAIT_FAULT   (never ramp)
     * TODO 3: p >= cfg->p_f_safe -> WAIT_OVERPRESSURE
     * TODO 4: subtract baseline, filter
     * TODO 5: hysteresis: enter contact above x_on, leave below x_off
     * TODO 6: release latch: while release_required, ignore palm until it
     *         has been released once (then clear the latch)
     * TODO 7: debounce: only after cfg->debounce_samples consecutive palm
     *         contact samples return WAIT_CONTACT. Fingertip NEVER triggers.
     * TODO 8: d->delay_ms(poll period)
     */
    d->delay_ms(10);
    return WAIT_CONTINUE; /* fail-safe default: never ramp */
}
