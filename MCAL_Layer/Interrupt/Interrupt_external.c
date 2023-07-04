#include "Interrupt_external.h"

static Std_ReturnType interrupt_intx_enable(const external_intx_interrupt_t *intx);
static Std_ReturnType interrupt_intx_clear_flag(const external_intx_interrupt_t *intx);
static Std_ReturnType interrupt_intx_disable(const external_intx_interrupt_t *intx);
static Std_ReturnType interrupt_intx_priority(const external_intx_interrupt_t *intx);
static Std_ReturnType interrupt_intx_edge(const external_intx_interrupt_t *intx);
static Std_ReturnType interrupt_intx_pin(const external_intx_interrupt_t *intx);

static void(* Int0_interrupt_Handeler)(void)=NULL;
static void(* Int1_interrupt_Handeler)(void)=NULL;
static void(* Int2_interrupt_Handeler)(void)=NULL;

static void(* RB4_LOW_interrupt_Handeler)(void)=NULL;
static void(* RB4_HIGH_interrupt_Handeler)(void)=NULL;
static void(* RB5_LOW_interrupt_Handeler)(void)=NULL;
static void(* RB5_HIGH_interrupt_Handeler)(void)=NULL;
static void(* RB6_LOW_interrupt_Handeler)(void)=NULL;
static void(* RB6_HIGH_interrupt_Handeler)(void)=NULL;
static void(* RB7_LOW_interrupt_Handeler)(void)=NULL;
static void(* RB7_HIGH_interrupt_Handeler)(void)=NULL;

static Std_ReturnType Int0_set_interrupt_Handeler(void(* interrupt_Handeler)(void));
static Std_ReturnType Int1_set_interrupt_Handeler(void(* interrupt_Handeler)(void));
static Std_ReturnType Int2_set_interrupt_Handeler(void(* interrupt_Handeler)(void));

static Std_ReturnType Intx_set_interrupt_Handeler(const external_intx_interrupt_t *intx);


Std_ReturnType interrupt_intx_int(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        
       interrupt_intx_disable(intx);
       interrupt_intx_clear_flag(intx);
        interrupt_intx_edge(intx);
        
        interrupt_intx_pin(intx);
        Intx_set_interrupt_Handeler(intx);
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        interrupt_intx_priority(intx);
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        interrupt_intx_enable(intx);
        return_statuse=E_OK;
    }
    
    return return_statuse;
}

Std_ReturnType interrupt_intx_deint(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
       interrupt_intx_disable(intx);
        return_statuse=E_OK;
    }
    
    return return_statuse;
}

Std_ReturnType interrupt_rbx_int(const external_rbx_interrupt_t *rbx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=rbx){
        /*disabe interrupt in onChange*/
       DISABLE_ONCHANGERBx_INTERRUPT();
       /*clear flage interrupt in onChange*/
       CLEAR_ONCHANGERBx_FLAG_INTERRUPT();
       /*  intialize the pins */
       gpio_pin_direction_int(&(rbx->pin));
       /*set callback functions to pointers */
       switch(rbx->pin.pin){
           case GPIO_PIN4:
              RB4_LOW_interrupt_Handeler=rbx->interrupt_callback_LOW;
               RB4_HIGH_interrupt_Handeler=rbx->interrupt_callback_HIGH;
               break;
           case GPIO_PIN5:
                 RB5_LOW_interrupt_Handeler=rbx->interrupt_callback_LOW;
               RB5_HIGH_interrupt_Handeler=rbx->interrupt_callback_HIGH;
               break;
           case GPIO_PIN6:
                 RB6_LOW_interrupt_Handeler=rbx->interrupt_callback_LOW;
               RB6_HIGH_interrupt_Handeler=rbx->interrupt_callback_HIGH;
               break;
           case GPIO_PIN7:
                RB7_LOW_interrupt_Handeler=rbx->interrupt_callback_LOW;
               RB7_HIGH_interrupt_Handeler=rbx->interrupt_callback_HIGH;
               break;
           default:
               break;
       }
       /*set priority to RBx interrupt*/
       #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRORITY_LOW==rbx->priority){
        ENABLE_ONCHANGERBx_LOW_PRIORETY_INTERRUPT();
        }
        else{
        ENABLE_ONCHANGERBx_HIGH_PRIORETY_INTERRUPT();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        /*enable interrupt in onChange*/
        ENABLE_ONCHANGERBx_INTERRUPT();
        return_statuse=E_OK;
    }
    
    return return_statuse;
}

Std_ReturnType interrupt_rbx_deint(const external_rbx_interrupt_t *rbx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=rbx){
       
        return_statuse=E_OK;
    }
    
    return return_statuse;
}


/*helper function */
static Std_ReturnType interrupt_intx_enable(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        switch(intx->intx){
            case INTERRUPT_INT0:
                ENABLE_INT0_INTERRUPT();
                break;
            case INTERRUPT_INT1:
                ENABLE_INT1_INTERRUPT();
                break;
            case INTERRUPT_INT2:
                ENABLE_INT2_INTERRUPT();
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }
        return_statuse=E_OK;
    }
    
    return return_statuse;
}
static Std_ReturnType interrupt_intx_disable(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        switch(intx->intx){
            case INTERRUPT_INT0:
                DISABLE_INT0_INTERRUPT();
                break;
            case INTERRUPT_INT1:
                DISABLE_INT1_INTERRUPT();
                break;
            case INTERRUPT_INT2:
                DISABLE_INT2_INTERRUPT();
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }
        return_statuse=E_OK;
    }
    
    return return_statuse;
}
 
#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
static Std_ReturnType interrupt_intx_priority(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
       
        switch(intx->intx){            
            case INTERRUPT_INT1:
                if(intx->priority == PRORITY_LOW){
                     ENABLE_INT1_LOW_PRIORETY_INTERRUPT() ;
                }
                else{
                    ENABLE_INT1_HIGH_PRIPRITY_INTERRUPT();
                }
                break;
            case INTERRUPT_INT2:
                if(intx->priority == PRORITY_LOW){
                    ENABLE_INT2_LOW_PRIORETY_INTERRUPT() ;
                }
                else{
                    ENABLE_INT2_HIGH_PRIPRITY_INTERRUPT();
                }
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }

        return_statuse=E_OK;
    }
    
    return return_statuse;
}
#endif

static Std_ReturnType interrupt_intx_edge(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        switch(intx->intx){ 
            case INTERRUPT_INT0:
                if(intx->edge == INTERRUPT_FALLING_EDGE){
                     ENABLE_INT0_FALLING_EDGE_INTERRUPT() ;
                }
                else{
                   ENABLE_INT0_RISIG_EDGE_INTERRUPT() ;
                }
                break;
            case INTERRUPT_INT1:
                if(intx->edge == INTERRUPT_FALLING_EDGE){
                     ENABLE_INT1_FALLING_EDGE_INTERRUPT() ;
                }
                else{
                   ENABLE_INT1_RISIG_EDGE_INTERRUPT() ;
                }
                break;
            case INTERRUPT_INT2:
                if(intx->edge == INTERRUPT_FALLING_EDGE){
                     ENABLE_INT2_FALLING_EDGE_INTERRUPT() ;
                }
                else{
                   ENABLE_INT2_RISIG_EDGE_INTERRUPT() ;
                }
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }
        return_statuse=E_OK;
    }
    
    return return_statuse;
}


static Std_ReturnType interrupt_intx_pin(const external_intx_interrupt_t *intx){
   Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
       gpio_pin_direction_int(&(intx->pin));
        return_statuse=E_OK;
    }
    
    return return_statuse;
    
    
}


static Std_ReturnType interrupt_intx_clear_flag(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        switch(intx->intx){            
            case INTERRUPT_INT0:
                CLEAR_INT0_FLAG_INTERRUPT();
                break;
            case INTERRUPT_INT1:
                CLEAR_INT1_FLAG_INTERRUPT();
                break;
            case INTERRUPT_INT2:
                CLEAR_INT2_FLAG_INTERRUPT();
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }
#endif
        return_statuse=E_OK;
    }
    
    return return_statuse;
}


static Std_ReturnType Int0_set_interrupt_Handeler(void(* interrupt_Handeler)(void)){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=interrupt_Handeler){
       Int0_interrupt_Handeler=interrupt_Handeler;
        return_statuse=E_OK;
    }
    
    return return_statuse;
}

static Std_ReturnType Int1_set_interrupt_Handeler(void(* interrupt_Handeler)(void)){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=interrupt_Handeler){
       Int1_interrupt_Handeler=interrupt_Handeler;
        return_statuse=E_OK;
    }
    
    return return_statuse;
}
static Std_ReturnType Int2_set_interrupt_Handeler(void(* interrupt_Handeler)(void)){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=interrupt_Handeler){
       Int2_interrupt_Handeler=interrupt_Handeler;
        return_statuse=E_OK;
    }
    
    return return_statuse;
}

static Std_ReturnType Intx_set_interrupt_Handeler(const external_intx_interrupt_t *intx){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=intx){
        switch(intx->intx){
            case INTERRUPT_INT0:
                Int0_set_interrupt_Handeler(intx->interrupt_callback);
                break;
            case INTERRUPT_INT1:
                Int1_set_interrupt_Handeler(intx->interrupt_callback);
                break;
            case INTERRUPT_INT2:
              Int2_set_interrupt_Handeler(intx->interrupt_callback);
                break;
            default:
                return_statuse=E_NOT_OK;
                break;
        }
        return_statuse=E_OK;
    }
    
    return return_statuse;
}


void INT0_ISR(void){
    CLEAR_INT0_FLAG_INTERRUPT();
    
    if(Int0_interrupt_Handeler){
        Int0_interrupt_Handeler();
    }
}
void INT1_ISR(void){
    CLEAR_INT1_FLAG_INTERRUPT();
    
    if(Int1_interrupt_Handeler){
        Int1_interrupt_Handeler();
    }
}
void INT2_ISR(void){
    CLEAR_INT2_FLAG_INTERRUPT();
    
    if(Int2_interrupt_Handeler){
        Int2_interrupt_Handeler();
    }
}


void RB4_ISR(uint8 flage){
    CLEAR_ONCHANGERBx_FLAG_INTERRUPT();
    if(flage==1){
        if(RB4_HIGH_interrupt_Handeler){
        RB4_HIGH_interrupt_Handeler();
    }
    }
    else if(flage==0){
        if(RB4_LOW_interrupt_Handeler){
        RB4_LOW_interrupt_Handeler();
    }
    }
    else{
    }
    
}


void RB5_ISR(uint8 flage){
   CLEAR_ONCHANGERBx_FLAG_INTERRUPT();
    if(flage==1){
        if(RB5_HIGH_interrupt_Handeler){
        RB5_HIGH_interrupt_Handeler();
    }
    }
    else if(flage==0){
        if(RB5_LOW_interrupt_Handeler){
        RB5_LOW_interrupt_Handeler();
    }
    }
    else{
    }
    
}


void RB6_ISR(uint8 flage){
   CLEAR_ONCHANGERBx_FLAG_INTERRUPT();
    if(flage==1){
        if(RB6_HIGH_interrupt_Handeler){
        RB6_HIGH_interrupt_Handeler();
    }
    }
    else if(flage==0){
        if(RB6_LOW_interrupt_Handeler){
        RB6_LOW_interrupt_Handeler();
    }
    }
    else{
    }
    
}


void RB7_ISR(uint8 flage){
   CLEAR_ONCHANGERBx_FLAG_INTERRUPT();
    if(flage==1){
        if(RB7_HIGH_interrupt_Handeler){
        RB7_HIGH_interrupt_Handeler();
    }
    }
    else if(flage==0){
        if(RB7_LOW_interrupt_Handeler){
        RB7_LOW_interrupt_Handeler();
    }
    }
    else{
    }
    
}