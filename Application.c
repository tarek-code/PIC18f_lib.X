/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"











ccp1_t ccp1={
  .ccp1_callback=NULL,
.ccp1_mode=CCP1_PWM_MODE_SELECTED,
.ccp1_pin.port=PORTC_INDX,
.ccp1_pin.pin=GPIO_PIN2,
.ccp1_pin.direction=GPIO_OUTPUT,

.ccp1_sub_mode=CCP1_PWM_MODE,
.pwm_frq=20000,
.timer2_post=1,
.timer2_pre=1
};

timer2_t timer2={
  .timer2_Postscale_value=TIMER2_DIV_BY_1,
.timer2_Prescaler_value=TIMER2_PRE_DIV_BY_1,
.timer2_callback=NULL,
.timer2_preload_value=0  
};


int main() {

   //TRISC2 = 0;		/* Set CCP1 pin as output for PWM out */
   //CCPR1L = 40;	/* load duty cycle value */
   
  // CCP1CON = 0x0C;	/* Set PWM mode and no decimal for PWM */
ccp1_int(&ccp1);
 timer2_int(&timer2);

ccp1_pwm_set_duty(98);
ccp1_pwm_start();
     
    while (1) {

      
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}