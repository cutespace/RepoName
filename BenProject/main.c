#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <main.h>

#include "leds.h"
#include "spi_comm.h"

#include "motors.h"
#include "selector.h"



void clear_leds(void);
void spi_comm_start(void);
//void set_led(led_name_1 led_1, unsigned int 0;led_name_3 led_3, unsigned int 0;
		//led_name_5 led_5, unsigned int 0;);led_name_7 led_7, unsigned int 0)
//void set_led(led_name_2 led_2, unsigned int 0);
//void set_led(led_name_3 led_3, unsigned int 0);
//void set_led(led_name_4 led_4, unsigned int 0);
void set_led(led_name_t led_number, unsigned int value);



//this is only for modify test ben;
int main(void)
{

    halInit();
    chSysInit();
    mpu_init();

    clear_leds();
    spi_comm_start();

    motors_init();
    //left_motor_set_speed();
    //right_motor_set_speed();
    //left_motor_set_speed(int motor_leftspeed);
    //right_motor_set_speed(int motor_rightspeed);
    left_motor_get_desired_speed();
    right_motor_get_desired_speed();



    /* Infinite loop. */
    while (1) {
    	//waits 1 second
        chThdSleepMilliseconds(1000);
        //set_led(LED1, 2);
        //set_led(LED3, 2);
        //set_led(LED5, 2);
        //set_led(LED7, 2);
        //set_rgb_led(LED2, 9,1,1);
        //set_rgb_led(LED4, 1,9,2);
       // set_rgb_led(LED6, 1,3,9);
        //set_rgb_led(LED8, 5,5,5);
       // set_body_led(0);
        set_front_led(2);

        get_selector();
           if(get_selector() == 1)
           {
           	set_led(LED1, 0);
            left_motor_set_speed(1000);
            right_motor_set_speed(-1000);
           }
           else if(get_selector() == 2)
           {
        	    left_motor_set_speed(-1000);
        	    right_motor_set_speed(1000);
        	  // set_rgb_led(LED8, 10,10,10);
           }
           else if(get_selector() == 3)
                    {
                  	    left_motor_set_speed(0);
                  	    right_motor_set_speed(0);
                  	  // set_rgb_led(LED8, 10,10,10);
                     }



    }
}

#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}
