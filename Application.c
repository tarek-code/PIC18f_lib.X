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
    //led_toggel(&led1);
    cc++;
}


timer3_t timer2={
  
.ccp_mode=TIMER3_CCP_OFF,
.timer3_Prescaler_value=TIMER1_PRESCALER_OFF,
.timer3_callback=timer3_ISR,
.timer3_mode=TIMER3_COUNTER,
.timer3_preload_value=0,
.timer3_syn_mode=TIMER3_COUNTER_ASYN

};



uint16 timer3_counter=0;
int main() {
 // gpio_pin_direction_int(&pin1);
//led_int(&led1);
timer3_int(&timer2);

//led_on(&led1);
    while (1) {

       timer3_read(&timer2,&timer3_counter);
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}