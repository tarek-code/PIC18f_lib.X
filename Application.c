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




void timer1_ISR(){
    led_toggel(&led1);
}


timer1_t timer1={
  
.timer1_callback  =timer1_ISR, 
 .timer1_select_sourse=TIMER1_COUNTER,
.timer1_select_mode_16_bits=TIMER1_16_BIT_MODE_SEPERATED,
.timer1_osc_statuse=TIMER1_OSCILLATOR_OFF,
.timer1_syn_mode=TIMER1_COUNTER_ASYN,

  .timer1_Prescaler_type=TIMER1_DIV_BY_8,
  .timer1_preload_value=0,

};




int main() {
 // gpio_pin_direction_int(&pin1);
//led_int(&led1);
timer1_int(&timer1);

    
    while (1) {

       
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}