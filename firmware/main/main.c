/**
 * @file main.c
 * @brief Entry point. Runs the glove state machine:
 *        STARTUP -> WAIT -> (ramp / hold / release, to be added).
 */
#include <stdio.h>
#include "startup.h"
#include "wait.h"

void app_main(void)
{
    /* TODO: call startup, then hand off to WAIT (see docs/images/startup_sequence.jpg). */
    printf("exoglove: boot\n");
}
