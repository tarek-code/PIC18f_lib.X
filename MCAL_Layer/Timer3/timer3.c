#include "timer3.h"


#if TIMER3_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* timer3_callback_ptr)(void)=NULL;
    #endif
   static uint16 timer3_preload=ZERO_INT;

Std_ReturnType timer3_int(const timer3_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
    
        TIMER3_OFF_CFG() ;
        TIMER3_16_BIT_MODE_SEPERATED_CFG() ;
        TMR3=ptr->timer3_preload_value;
                timer3_preload=ptr->timer3_preload_value;
        TIMER3_SET_PRESCALER_CFG(ptr->timer3_Prescaler_value);
        
        if(TIMER3_TIMER==ptr->timer3_mode){
            TIMER3_TIMER_CFG();
        }
        else{
            TIMER3_COUNTER_CFG();
            if(TIMER3_COUNTER_SYN == ptr->timer3_syn_mode){
            
            TIMER3_COUNTER_SYN_CFG();
        }
        else{
            TIMER3_COUNTER_ASYN_CFG();
        }
        }
        
        
        
        //if interrupt enable
        #if TIMER3_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER3_INRERRUPT_DISABLE();
        TIMER3_Interrupt_CLEAR_Flag_bit();
        timer3_callback_ptr=ptr->timer3_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->timer3_priority){
        TIMER3_ENABLE_HIGH_PRIORITY();
        }
        else{
       TIMER3_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        TIMER3_INRERRUPT_ENABLE();
        #endif

        TIMER3_ON_CFG();
        
        
        returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer3_deint(const timer3_t* ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
    
        TIMER3_OFF_CFG();
        #if TIMER3_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER3_INRERRUPT_DISABLE();
         #endif
        returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer3_write(const timer3_t *ptr,uint16 data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
    
        timer3_preload=data;
        
        TMR3H=data>>8;
            TMR3L =(uint8)data;
        returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer3_read(const timer3_t *ptr,uint16 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr && NULL!=data){
        
           uint8 high;
           uint8 low;
           low=TMR3L;
           high=TMR3H;
           *data=(uint16)(low + (high<<8));
        
        returt_statuse=E_OK;
    }
    return returt_statuse;
}



void TIMER3_ISR(void){
    TIMER3_Interrupt_CLEAR_Flag_bit();
    TMR3H=timer3_preload>>8;
            TMR3L =(uint8)timer3_preload;
    
    if(timer3_callback_ptr){
        timer3_callback_ptr();
    }
}