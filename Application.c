/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"


led_cfg_t led1={
  .led_status=LED_OFF,
.pin_number=  GPIO_PIN0,
  .port_name=PORTC_INDX
};


void timer0(){
    led_toggel(&led1);
}

timer0_t timer0_module={
  .timer0_select_edge=TIMER0_HIGH_LOW_EDGE,
.timer0_callback  =timer0,
  .timer0_select_mode_bits=TIMER0_16_BIT_MODE,
  .timer0_select_sourse=TIMER0_TIMER,
  .timer0_prescaler_statuse=TIMER0_PRESCALER_ON,
  .timer0_Prescaler_type=TIMER0_DIV_BY_8,
  .timer0_preload_value=3036
          
};




int main() {
  
led_int(&led1);
timer0_int(&timer0);

    
    while (1) {

       
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}