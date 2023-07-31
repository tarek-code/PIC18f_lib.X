#include "ccp1.h"

#if CCP1_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* ccp1_callback_ptr)(void)=NULL;
    #endif
   




Std_ReturnType ccp1_int(const ccp1_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        CCP1_CHOOSEING_MODE(CCP1_DISABLE);
        if(CCP1_COMPARE_MODE_SELECTED ==ptr->ccp1_mode){
            switch(ptr->ccp1_sub_mode){
                case CCP1_COMPARE_MODE_SET_PIN_HIGH:
                    CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP1_COMPARE_MODE_SET_PIN_LOW :
                    CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_PIN_LOW);
                    break;
                case CCP1_COMPARE_MODE_SET_INT_SW:
                    CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_INT_SW);
                    break;
                case CCP1_COMPARE_MODE_SET_PIN_TOGGILE:
                    CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_PIN_TOGGILE);
                    break;
                case CCP1_COMPARE_MODE_SET_SPECIAL_EVENT:
                    CCP1_CHOOSEING_MODE(CCP1_COMPARE_MODE_SET_SPECIAL_EVENT);
                    break;
                default:
                    returt_statuse=E_NOT_OK;
                    break;
            }
            gpio_pin_direction_int(&(ptr->ccp1_pin));
        }
        else if(CCP1_CAPTURE_MODE_SELECTED ==ptr->ccp1_mode){
            switch(ptr->ccp1_sub_mode){
                case CCP1_CAPTURE_MODE_EVERY_FALLING_EDGE:
                    CCP1_CHOOSEING_MODE(CCP1_CAPTURE_MODE_EVERY_FALLING_EDGE);
                    break;
                case CCP1_CAPTURE_MODE_EVERY_RISING_EDGE :
                    CCP1_CHOOSEING_MODE(CCP1_CAPTURE_MODE_EVERY_RISING_EDGE);
                    break;
                case CCP1_CAPTURE_MODE_EVERY_4TH_RISING_EDGE:
                    CCP1_CHOOSEING_MODE(CCP1_CAPTURE_MODE_EVERY_4TH_RISING_EDGE);
                    break;
                case CCP1_CAPTURE_MODE_EVERY_16TH_RISING_EDGE:
                    CCP1_CHOOSEING_MODE(CCP1_CAPTURE_MODE_EVERY_16TH_RISING_EDGE);
                    break;
               
                default:
                    returt_statuse=E_NOT_OK;
                    break;
            }
             gpio_pin_direction_int(&(ptr->ccp1_pin));
        }
        #if (CCP1_SELECT_MODE==CCP1_PWM_MODE_CFG)
        else if(CCP1_PWM_MODE_SELECTED ==ptr->ccp1_mode){
            if(CCP1_PWM_MODE == ptr->ccp1_sub_mode){
                CCP1_CHOOSEING_MODE(CCP1_PWM_MODE);
                gpio_pin_direction_int(&(ptr->ccp1_pin));
                PR2=(uint8)((_XTAL_FREQ/(ptr->timer2_pre * ptr->timer2_post * ptr->pwm_frq * 4.0))-1);
            }
            else{
                returt_statuse=E_NOT_OK;
            }
             
        }
#endif
        else{
            // do nothing 
        }
        
        
        //if interrupt enable
        #if CCP1_ENABLE_FEATURE==ENABLE_FEATURE
        CCP1_INRERRUPT_DISABLE();
        CCP1_Interrupt_CLEAR_Flag_bit();
        ccp1_callback_ptr=ptr->ccp1_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->ccp1_priority){
        CCP1_ENABLE_HIGH_PRIORITY();
        }
        else{
       CCP1_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        CCP1_INRERRUPT_ENABLE();
        #endif

        
        
        
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

Std_ReturnType ccp1_deint(const ccp1_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        CCP1_CHOOSEING_MODE(CCP1_DISABLE);
        #if CCP1_ENABLE_FEATURE==ENABLE_FEATURE
   CCP1_INRERRUPT_DISABLE();
         #endif
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}


#if (CCP1_SELECT_MODE==CCP1_CAPTURE_MODE_CFG)

    Std_ReturnType ccp1_capture_check(uint8 *statuse ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=statuse){
        if(CCP1_CAPTURE_DONE ==CCP2_Interrupt_READ_Flag_bit()){
            *statuse=CCP1_CAPTURE_DONE;
        }
        else{
            *statuse=CCP1_CAPTURE_NOT_DONE;
        }
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

    Std_ReturnType ccp1_capture_read_value(uint16 *value ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=value){
       ccp1_reg_t ccp1_reg={.ccp1_16_reg=0};
       ccp1_reg.ccp1_reg_low=CCPR1L;
       ccp1_reg.ccp1_reg_high=CCPR1H;
       *value=ccp1_reg.ccp1_16_reg;
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

#endif

    #if (CCP1_SELECT_MODE==CCP1_COMPARE_MODE_CFG)

    Std_ReturnType ccp1_compare_check(uint8 *statuse ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=statuse){
       if(CCP1_COMPARE_DONE ==CCP2_Interrupt_READ_Flag_bit()){
            *statuse=CCP1_COMPARE_DONE;
        }
        else{
            *statuse=CCP1_COMPARE_NOT_DONE;
        }
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

    Std_ReturnType ccp1_compare_set_value(uint16 value ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=value){
       ccp1_reg_t ccp1_reg={.ccp1_16_reg=0};
       ccp1_reg.ccp1_16_reg=value;
       CCPR1L=ccp1_reg.ccp1_reg_low;
       CCPR1H=ccp1_reg.ccp1_reg_high;
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

#endif

    #if (CCP1_SELECT_MODE==CCP1_PWM_MODE_CFG)

    Std_ReturnType ccp1_pwm_set_duty(uint8 duty ){
    Std_ReturnType returt_statuse=E_NOT_OK;
   
   
        uint16 l_value=0;
        l_value=(uint16)((PR2+1)*(duty/100.0)*4);
        CCP1CONbits.DC1B=(uint8)(l_value & 0x0003);
        CCPR1L=(uint8)(l_value>>2);
    
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

    Std_ReturnType ccp1_pwm_start(void ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
       CCP1_CHOOSEING_MODE(CCP1_PWM_MODE);
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

    Std_ReturnType ccp1_pwm_stop(void){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
       CCP1_CHOOSEING_MODE(CCP1_DISABLE);
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

#endif






void CCP1_ISR(void){
    CCP1_Interrupt_CLEAR_Flag_bit();
   
    if(ccp1_callback_ptr){
        ccp1_callback_ptr();
    }
}
