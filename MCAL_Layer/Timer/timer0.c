#include "timer0.h"


#if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* timer0_callback_ptr)(void)=NULL;
    #endif
   static uint16 timer0_preload=ZERO_INT;
   
   /**
    * 
    * @param ptr
    * @return 
    */
   Std_ReturnType timer0_int(const timer0_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        timer0_preload=ptr->timer0_preload_value;
        //close timer
        TIMER0_OFF_CFG();
        //see the mode of the timer
        if(ptr->timer0_select_mode_bits ==TIMER0_8_BIT_MODE){
            TIMER0_8_BIT_MODE_CFG();
            TMR0L =ptr->timer0_preload_value;
        }
        else{
            TIMER0_16_BIT_MODE_CFG();
            TMR0H=ptr->timer0_preload_value>>8;
            TMR0L =(uint8)ptr->timer0_preload_value;
        }
        // prescaler on or off
        if(ptr->timer0_prescaler_statuse== TIMER0_PRESCALER_ON){
            TIMER0_PRESCALER_ON_CFG();
            TIMER0_SET_PRESCALER(ptr->timer0_Prescaler_type);
        }
        else{
            TIMER0_PRESCALER_OFF_CFG();
        }
        // timer or counter 
        if(ptr->timer0_select_sourse == TIMER0_COUNTER){
            TIMER0_COUNTER_CFG();
            // type of edge 
            if(ptr->timer0_select_edge==TIMER0_HIGH_LOW_EDGE){
                TIMER0_HIGH_LOW_EDGE_CFG();
            }
            else{
                TIMER0_LOW_HIGH_EDGE_CFG();
            }
        }
        else{
            TIMER0_TIMER_CFG();
        }
        
        
        
        //if interrupt enable
        #if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
        TIMER0_INRERRUPT_DISABLE();
        TIMER0_Interrupt_CLEAR_Flag_bit();
        timer0_callback_ptr=ptr->timer0_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->timer0_priority){
        TIMER0_ENABLE_HIGH_PRIORITY();
        }
        else{
       TIMER0_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        TIMER0_INRERRUPT_ENABLE();
        #endif

        TIMER0_ON_CFG();
         returt_statuse=E_OK;
    }
    else{
         returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

   /**
    * 
    * @param ptr
    * @return 
    */
Std_ReturnType timer0_deint(const timer0_t* ptr){
   Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        TIMER0_OFF_CFG();
        #if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
   TIMER0_INRERRUPT_DISABLE();
         #endif
 returt_statuse=E_OK;
    }
    else{
         returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

/**
 * 
 * @param ptr
 * @param data
 * @return 
 */
Std_ReturnType timer0_write(const timer0_t *ptr,uint16 data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        timer0_preload=data;
        if(ptr->timer0_select_mode_bits==TIMER0_8_BIT_MODE){
            TMR0L =data;
        }
        else{
            TMR0H=data>>8;
            TMR0L =(uint8)data;
        }
         returt_statuse=E_OK;
    }
    else{
        returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}

/**
 * 
 * @param ptr
 * @param data
 * @return 
 */
Std_ReturnType timer0_read(const timer0_t *ptr,uint16 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
       if(ptr->timer0_select_mode_bits==TIMER0_8_BIT_MODE){
            
            *data=TMR0L;
        }
        else{
           uint8 high;
           uint8 low;
           low=TMR0L;
           high=TMR0H;
           *data=(uint16)(low + (high<<8));
        }
        returt_statuse=E_OK;
    }
    else{
         returt_statuse=E_NOT_OK;
    }
    return returt_statuse;
}



void TIMER0_ISR(void){
    TIMER0_Interrupt_CLEAR_Flag_bit();
    TMR0H=timer0_preload>>8;
    TMR0L =(uint8)timer0_preload;
    if(timer0_callback_ptr){
        timer0_callback_ptr();
    }
}
