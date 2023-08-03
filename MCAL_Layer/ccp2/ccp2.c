#include "ccp2.h"

#if CCP2_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* ccp2_callback_ptr)(void)=NULL;
    #endif
   




Std_ReturnType ccp2_int(const ccp2_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        CCP2_CHOOSEING_MODE(CCP2_DISABLE);
        if(CCP2_COMPARE_MODE_SELECTED ==ptr->ccp2_mode){
            switch(ptr->ccp2_sub_mode){
                case CCP2_COMPARE_MODE_SET_PIN_HIGH:
                    CCP2_CHOOSEING_MODE(CCP2_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP2_COMPARE_MODE_SET_PIN_LOW :
                    CCP2_CHOOSEING_MODE(CCP2_COMPARE_MODE_SET_PIN_LOW);
                    break;
                case CCP2_COMPARE_MODE_SET_INT_SW:
                    CCP2_CHOOSEING_MODE(CCP2_COMPARE_MODE_SET_INT_SW);
                    break;
                case CCP2_COMPARE_MODE_SET_PIN_TOGGILE:
                    CCP2_CHOOSEING_MODE(CCP2_COMPARE_MODE_SET_PIN_TOGGILE);
                    break;
                case CCP2_COMPARE_MODE_SET_SPECIAL_EVENT:
                    CCP2_CHOOSEING_MODE(CCP2_COMPARE_MODE_SET_SPECIAL_EVENT);
                    break;
                default:
                    returt_statuse=E_NOT_OK;
                    break;
            }
            gpio_pin_direction_int(&(ptr->ccp2_pin));
            if(dEFAULT == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=0;
                T3CONbits.T3CCP2=1;
            }
            else if(cCP1_TIMER1_CCP2_TIMER3 == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=1;
                T3CONbits.T3CCP2=0;
            }
            else if(cCP1_CCP2_TIMER1 == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=0;
                T3CONbits.T3CCP2=0;
            }
            else{
                // do nothing 
            }
        }
        else if(CCP2_CAPTURE_MODE_SELECTED ==ptr->ccp2_mode){
            switch(ptr->ccp2_sub_mode){
                case CCP2_CAPTURE_MODE_EVERY_FALLING_EDGE:
                    CCP2_CHOOSEING_MODE(CCP2_CAPTURE_MODE_EVERY_FALLING_EDGE);
                    break;
                case CCP2_CAPTURE_MODE_EVERY_RISING_EDGE :
                    CCP2_CHOOSEING_MODE(CCP2_CAPTURE_MODE_EVERY_RISING_EDGE);
                    break;
                case CCP2_CAPTURE_MODE_EVERY_4TH_RISING_EDGE:
                    CCP2_CHOOSEING_MODE(CCP2_CAPTURE_MODE_EVERY_4TH_RISING_EDGE);
                    break;
                case CCP2_CAPTURE_MODE_EVERY_16TH_RISING_EDGE:
                    CCP2_CHOOSEING_MODE(CCP2_CAPTURE_MODE_EVERY_16TH_RISING_EDGE);
                    break;
               
                default:
                    returt_statuse=E_NOT_OK;
                    break;
            }
             gpio_pin_direction_int(&(ptr->ccp2_pin));
             if(dEFAULT == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=0;
                T3CONbits.T3CCP2=1;
            }
            else if(cCP1_TIMER1_CCP2_TIMER3 == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=1;
                T3CONbits.T3CCP2=0;
            }
            else if(cCP1_CCP2_TIMER1 == ptr->ccp2_capture_compare_timer){
                T3CONbits.T3CCP1=0;
                T3CONbits.T3CCP2=0;
            }
            else{
                // do nothing 
            }
        }
        #if (CCP2_SELECT_MODE==CCP2_PWM_MODE_CFG)
        else if(CCP2_PWM_MODE_SELECTED ==ptr->ccp2_mode){
            if(CCP2_PWM_MODE == ptr->ccp2_sub_mode){
                CCP2_CHOOSEING_MODE(CCP2_PWM_MODE);
                gpio_pin_direction_int(&(ptr->ccp2_pin));
                PR2=(uint8)((_XTAL_FREQ/(ptr->ccp2_timer2_pre * ptr->ccp2_timer2_post * ptr->pwm_frq * 4.0))-1);
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
        #if CCP2_ENABLE_FEATURE==ENABLE_FEATURE
        CCP2_INRERRUPT_DISABLE();
        CCP2_Interrupt_CLEAR_Flag_bit();
        ccp2_callback_ptr=ptr->ccp2_callback;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->ccp2_priority){
        CCP2_ENABLE_HIGH_PRIORITY();
        }
        else{
       CCP2_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        CCP2_INRERRUPT_ENABLE();
        #endif

        
        
        
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

Std_ReturnType ccp2_deint(const ccp2_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        CCP2_CHOOSEING_MODE(CCP2_DISABLE);
        #if CCP2_ENABLE_FEATURE==ENABLE_FEATURE
   CCP2_INRERRUPT_DISABLE();
         #endif
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}


#if (CCP2_SELECT_MODE==CCP2_CAPTURE_MODE_CFG)

    Std_ReturnType ccp2_capture_check(uint8 *statuse ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=statuse){
        if(CCP2_CAPTURE_DONE ==CCP2_Interrupt_READ_Flag_bit()){
            *statuse=CCP2_CAPTURE_DONE;
        }
        else{
            *statuse=CCP2_CAPTURE_NOT_DONE;
        }
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

    Std_ReturnType ccp2_capture_read_value(uint16 *value ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=value){
       ccp2_reg_t ccp2_reg={.ccp2_16_reg=0};
       ccp2_reg.ccp2_reg_low=CCPR2L;
       ccp2_reg.ccp2_reg_high=CCPR2H;
       *value=ccp2_reg.ccp2_16_reg;
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

#endif

    #if (CCP2_SELECT_MODE==CCP2_COMPARE_MODE_CFG)

    Std_ReturnType ccp2_compare_check(uint8 *statuse ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=statuse){
       if(CCP2_COMPARE_DONE ==CCP2_Interrupt_READ_Flag_bit()){
            *statuse=CCP2_COMPARE_DONE;
        }
        else{
            *statuse=CCP2_COMPARE_NOT_DONE;
        }
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

    Std_ReturnType ccp2_compare_set_value(uint16 value ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=value){
       ccp2_reg_t ccp2_reg={.ccp2_16_reg=0};
       ccp2_reg.ccp2_16_reg=value;
       CCPR2L=ccp2_reg.ccp2_reg_low;
       CCPR2H=ccp2_reg.ccp2_reg_high;
        returt_statuse=E_OK;
    }
    
    return returt_statuse;
}

#endif

    #if (CCP2_SELECT_MODE==CCP2_PWM_MODE_CFG)

    Std_ReturnType ccp2_pwm_set_duty(uint8 duty ){
    Std_ReturnType returt_statuse=E_NOT_OK;
   
   
        uint16 l_value=0;
        l_value=(uint16)((PR2+1)*(duty/100.0)*4);
        CCP2CONbits.DC2B=(uint8)(l_value & 0x0003);
        CCPR2L=(uint8)(l_value>>2);
    
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

    Std_ReturnType ccp2_pwm_start(void ){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
       CCP2_CHOOSEING_MODE(CCP2_PWM_MODE);
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

    Std_ReturnType ccp2_pwm_stop(void){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
       CCP2_CHOOSEING_MODE(CCP2_DISABLE);
        returt_statuse=E_OK;
    
    
    return returt_statuse;
}

#endif






void CCP2_ISR(void){
    CCP2_Interrupt_CLEAR_Flag_bit();
   
    if(ccp2_callback_ptr){
        ccp2_callback_ptr();
    }
}
