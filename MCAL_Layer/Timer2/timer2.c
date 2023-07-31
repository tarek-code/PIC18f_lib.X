#include "timer2.h"

#if TIMER2_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* timer2_callback_ptr)(void)=NULL;
    #endif
   static uint8 timer2_preload=ZERO_INT;


Std_ReturnType timer2_int(const timer2_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        TIMER2_OFF_CFG();
        TIMER2_SET_PRESCALER(ptr->timer2_Prescaler_value);
        TIMER2_SET_Postscale(ptr->timer2_Postscale_value);
         TMR2=ptr->timer2_preload_value;
        timer2_preload=ptr->timer2_preload_value;
       
         //if interrupt enable
        #if TIMER2_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER2_INRERRUPT_DISABLE();
        TIMER2_Interrupt_CLEAR_Flag_bit();
        timer2_callback_ptr=ptr->timer2_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->timer2_priority){
        TIMER2_ENABLE_HIGH_PRIORITY();
        }
        else{
       TIMER2_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        TIMER2_INRERRUPT_ENABLE();
        #endif
        
        TIMER2_ON_CFG();
        
        returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer2_deint(const timer2_t* ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        TIMER2_OFF_CFG();
        #if TIMER2_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER2_INRERRUPT_DISABLE();
         #endif
        
        returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer2_write(const timer2_t *ptr,uint8 data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
         timer2_preload=data;
        TMR2=data;
        returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer2_read(const timer2_t *ptr,uint8 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        
        *data=TMR2;
        returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}



void TIMER2_ISR(void){
    TIMER2_Interrupt_CLEAR_Flag_bit();
    TMR2=timer2_preload;
    
    if(timer2_callback_ptr){
        timer2_callback_ptr();
    }
}