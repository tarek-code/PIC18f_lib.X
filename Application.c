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



uint32 cc=0;
void timer3_ISR(){
    led_toggel(&led1);
    cc++;
}


timer3_t timer2={
  
.ccp_mode=TIMER3_CCP_OFF,
.timer3_Prescaler_value=TIMER1_DIV_BY_8,
.timer3_callback=timer3_ISR,
.timer3_mode=TIMER3_TIMER,
.timer3_preload_value=3036,
.timer3_syn_mode=TIMER3_COUNTER_SYN

};




int main() {
 // gpio_pin_direction_int(&pin1);
led_int(&led1);
timer3_int(&timer2);

//led_on(&led1);
    while (1) {

       
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}