/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"


volatile uint8 flage=0;

void ccp1_calling(void);


void timer3_calling(void);


ccp1_t ccp1={
  .ccp1_callback=ccp1_calling,
.ccp1_mode=CCP1_COMPARE_MODE_SELECTED,
.ccp1_pin.port=PORTC_INDX,
.ccp1_pin.pin=GPIO_PIN2,
.ccp1_pin.direction=GPIO_OUTPUT,
.ccp1_capture_compare_timer=CCP1_CCP2_TIMER3,
.ccp1_sub_mode=CCP1_COMPARE_MODE_SET_PIN_LOW,

};





timer3_t timer3={
  .timer3_Prescaler_value=  TIMER3_DIV_BY_2,
  .timer3_callback=timer3_calling,
  .timer3_mode=TIMER3_TIMER,
  .timer3_preload_value=0,
  
};

int main() {

  ccp1_compare_set_value(37500);
  ccp1_int(&ccp1);


timer3_int(&timer3);


   




    while (1) {
 
      
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}

volatile uint8 kk=0;
void ccp1_calling(void){
     kk++;
     timer3_write(&timer3,0);
    if(1==kk){
         ccp1_compare_set_value(12500);
         CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_PIN_HIGH);

    }
    else if(2==kk){
        ccp1_compare_set_value(37500);
        CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_PIN_LOW);
        kk=0;
    }
   
    
   
}


void timer3_calling(void){

}
