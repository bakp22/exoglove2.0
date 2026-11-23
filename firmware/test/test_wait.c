/* Host tests for the WAIT state, using fake hardware hooks. */
#include <assert.h>
#include <stdio.h>
#include "wait.h"

static float palm, tip;
static int pump_off_calls, valve_safe_calls;

static void  fake_pump_off(void)       { pump_off_calls++; }
static void  fake_valve_safe(void)     { valve_safe_calls++; }
static float fake_read_palm(void)      { return palm; }
static float fake_read_tip(void)       { return tip; }
static void  fake_log(const char *m)   { (void)m; }
static void  fake_delay(uint32_t ms)   { (void)ms; }

static const WaitDeps deps = {
    fake_pump_off, fake_valve_safe, fake_read_palm, fake_read_tip,
    fake_log, fake_delay,
};
static const SafetyConfig cfg = {
    .x_on = 1.0f, .x_off = 0.5f, .p_f_safe = 50.0f,
    .sensor_max = 100.0f, .debounce_samples = 3,
};

/* Fingertip contact alone must never start the ramp. */
static void test_fingertip_never_triggers(void)
{
    WaitState s;
    palm = 0.0f; tip = 10.0f;
    wait_enter(&s, &cfg, &deps);
    for (int i = 0; i < 20; i++)
        assert(wait_step(&s, &cfg, &deps) != WAIT_CONTACT);
}

int main(void)
{
    test_fingertip_never_triggers();
    /* Add tests as the TODOs in wait.c are filled in, e.g.
     * pump_off/valve_safe called on enter, 1-sample spike ignored,
     * NaN -> WAIT_FAULT, pressure >= p_f_safe -> WAIT_OVERPRESSURE. */
    puts("wait: all tests passed");
    return 0;
}
