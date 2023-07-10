#include "timer1.h"

#if TIMER1_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* timer1_callback_ptr)(void)=NULL;
    #endif
   static uint16 timer1_preload=ZERO_INT;

Std_ReturnType timer1_int(const timer1_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        
        
        // disable the timer 
        TIMER1_OFF_CFG();
        
        
            
            
        // choosing between timer & counter
        if(TIMER1_TIMER==ptr->timer1_select_sourse){
            TIMER1_TIMER_CFG();
        }
        else{
            TIMER1_COUNTER_CFG();
        }
        
        // choosing the mode of 16 bit mode 
        if(TIMER1_16_BIT_MODE_SEPERATED == ptr->timer1_select_mode_16_bits){
            TIMER1_16_BIT_MODE_SEPERATED_CFG();
            // put the value in the timer1 registers
        timer1_preload=ptr->timer1_preload_value;
        TMR1H=ptr->timer1_preload_value>>8;
        TMR1L =(uint8)ptr->timer1_preload_value;
        }
        else{
            TIMER1_16_BIT_MODE__CFG();
        }
        
        // choosing syn mode 
        if(TIMER1_COUNTER_SYN == ptr->timer1_syn_mode){
            
            TIMER1_COUNTER_SYN_CFG();
        }
        else{
            TIMER1_COUNTER_ASYN_CFG();
        }
        
        // choosing the OSC mode 
        if(TIMER1_OSCILLATOR_ON==ptr->timer1_osc_statuse){
            
            TIMER1_OSCILLATOR_ON_CFG();
        }
        else{
            TIMER1_OSCILLATOR_OFF_CFG();
        }
        
        TIMER1_SET_PRESCALER_CFG(ptr->timer1_Prescaler_type);
        
        //if interrupt enable
        #if TIMER1_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER1_INRERRUPT_DISABLE();
        TIMER1_Interrupt_CLEAR_Flag_bit();
        timer1_callback_ptr=ptr->timer1_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->timer1_priority){
        TIMER1_ENABLE_HIGH_PRIORITY();
        }
        else{
       TIMER1_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        TIMER1_INRERRUPT_ENABLE();
        #endif

        TIMER1_ON_CFG();
        
         returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer1_deint(const timer1_t* ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        TIMER1_OFF_CFG();
        #if TIMER1_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER1_INRERRUPT_DISABLE();
         #endif
        returt_statuse=E_OK;
    }
    else{
        // do nothing 
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer1_write(const timer1_t *ptr,uint16 data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        timer1_preload=data;
        
        TMR1H=data>>8;
        TMR1L =(uint8)data;
            
        returt_statuse=E_OK;
    }
    else{
        // do nothing 
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer1_read(const timer1_t *ptr,uint16 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
           uint8 high;
           uint8 low;
           low=TMR1L;
           high=TMR1H;
           *data=(uint16)(low +(high<<8));
           
        returt_statuse=E_OK;
    }
    else{
        // do nothing 
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

Std_ReturnType timer1_read_System_Clock_Status(const timer1_t *ptr,uint8 *statuse){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        *statuse=TIMER1_READ_STATUSE_SOURCE_CLOCK_FROM_TIMER1_CFG();
        returt_statuse=E_OK;
    }
    else{
        // do nothing 
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

void TIMER1_ISR(void){
    TIMER1_Interrupt_CLEAR_Flag_bit();
    TMR1H=timer1_preload>>8;
    TMR1L =(uint8)timer1_preload;
    if(timer1_callback_ptr){
        timer1_callback_ptr();
    }
}