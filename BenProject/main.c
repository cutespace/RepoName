#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <main.h>

get_selector(void)
{

}
l

//this is only for modify test ben;
int main(void)
{

    halInit();
    chSysInit();
    mpu_init();

    eft_motor_set_speed(int motor_leftspeed);
    right_motor_set_speed(int motor_rightspeed);

    /* Infinite loop. */
    while (1) {
    	//waits 1 second
        chThdSleepMilliseconds(1000);
    }
}

#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}
