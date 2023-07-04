#include "timer0.h"


#if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* timer0_callback_ptr)(void)=NULL;
    #endif

   
   
   Std_ReturnType timer0_int(const timer0_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        #if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
   
    #endif
    }
    else{
        
    }
    return returt_statuse;
}

Std_ReturnType timer0_deint(const timer0_t* ptr){
   Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        #if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
   
    #endif
    }
    else{
        
    }
    return returt_statuse;
}

Std_ReturnType timer0_write(const timer0_t *ptr,uint16 data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
       
    }
    else{
        
    }
    return returt_statuse;
}

Std_ReturnType timer0_read(const timer0_t *ptr,uint16 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
       
    }
    else{
        
    }
    return returt_statuse;
}



void TIMER0_ISR(void){
    TIMER0_Interrupt_CLEAR_Flag_bit();
    
    if(timer0_callback_ptr){
        timer0_callback_ptr();
    }
}
