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

pin_cfg_t pin1={
  .direction=GPIO_INPUT,
  .level=GPIO_LOW,
  .pin=GPIO_PIN4,
  .port=PORTA_INDX
};


void timer0_ISR(){
    led_toggel(&led1);
}

timer0_t timer0={
  .timer0_select_edge=TIMER0_HIGH_LOW_EDGE,
.timer0_callback  =timer0_ISR,
  .timer0_select_mode_bits=TIMER0_16_BIT_MODE,
  .timer0_select_sourse=TIMER0_COUNTER,
  .timer0_prescaler_statuse=TIMER0_PRESCALER_OFF,
  .timer0_Prescaler_type=TIMER0_DIV_BY_16,
  .timer0_preload_value=0,
          
};




int main() {
 // gpio_pin_direction_int(&pin1);
led_int(&led1);
timer0_int(&timer0);

    
    while (1) {

       
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}