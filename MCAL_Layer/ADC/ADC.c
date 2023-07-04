#include "ADC.h"

/*Helper functions */

static inline void adc_pin_cfg(analog_channel_select_t analog_channel_select);
static inline void adc_Vref_cfg(const adc_t *adc);
static inline void adc_reading_mode_cfg(const adc_t *adc);

#if ADC_ENABLE_FEATURE==ENABLE_FEATURE
static void(* ADC_Interrupt_handler)(void)=NULL;
#endif




/**
 * 
 * @param adc
 * @return 
 */
Std_ReturnType adc_int(const adc_t *adc){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc){
         /*disable adc*/
        AD_Converter_module_is_disabled();
            /*choose type of Tad*/
        ADCON2bits.ACQT=(adc->AD_acquisition_time_select_bits);
       /*choose freq*/
        ADCON2bits.ADCS=(adc->AD_conversion_clock_select_bits);
        
       
      /*select channel*/
        ADCON0bits.CHS=adc->analog_channel_select;
         /* pin cfg & make pin as analog */
        adc_pin_cfg(adc->analog_channel_select);
        /*type of o/p */
        adc_Vref_cfg(adc);
        
        
        
    
        
        
        /*reading mode*/
        adc_reading_mode_cfg(adc);
       
        
        
        
        
        /*interrupt*/
        
        #if ADC_ENABLE_FEATURE==ENABLE_FEATURE
        ADC_Interrupt_handler=adc->ADC_callback;
            ADC_INRERRUPT_DISABLE();
            AD_Converter_Interrupt_CLEAR_Flag_bit();
            #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==adc->priority){
        ADC_ENABLE_HIGH_PRIORITY();
        }
        else{
        ADC_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
            ADC_INRERRUPT_ENABLE();
#endif
       
        
        
        /*enable adc */
        AD_Converter_module_is_enabled();
        
        
        
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @return 
 */
Std_ReturnType adc_start(const adc_t *adc){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc){
        /* start conversion*/
        ADC_START_CONVERSION();
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @param value
 * @return 
 */
Std_ReturnType adc_reading_value(const adc_t *adc,uint16 *value){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc && NULL!=value){
       if(ADC_RIGHT_MODE==adc->reading_mode){
            *value=(uint16)((ADRESH << 8)+ADRESL);
        }
        else if(ADC_LIFT_MODE==adc->reading_mode){
           *value=(uint16)(((ADRESH << 8)+ADRESL)>>6);
        }
        else{
           *value=(uint16)((ADRESH << 8)+ADRESL);
        }
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @param statuse
 * @return 
 */
Std_ReturnType adc_is_conversion_done(const adc_t *adc,uint8 *statuse){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc && NULL!=statuse){
        *statuse=(uint8)(!(AD_Conversion_Status()));
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @return 
 */
Std_ReturnType adc_deint(const adc_t *adc){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc){
        AD_Converter_module_is_disabled();
        #if ADC_ENABLE_FEATURE==ENABLE_FEATURE
         ADC_INRERRUPT_DISABLE();
        #endif
       
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @param analog_channel_select
 * @return 
 */
Std_ReturnType adc_select_channel(const adc_t *adc,analog_channel_select_t analog_channel_select){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc){
        
        /*select channel*/
        ADCON0bits.CHS=analog_channel_select;
         /* pin cfg & make pin as analog */
        adc_pin_cfg(analog_channel_select);
        returt_statuse=E_OK;
    }
    return returt_statuse;
}
/**
 * 
 * @param adc
 * @param value
 * @param analog_channel_select
 * @return 
 */
Std_ReturnType adc_get_conversion_blocking(const adc_t *adc,uint16 *value,analog_channel_select_t analog_channel_select){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc && NULL!=value){
        /*select channel */
        adc_select_channel(adc,analog_channel_select);
        /*start conversion */
        adc_start(adc);
        while(AD_Conversion_Status());
        adc_reading_value(adc,value);
        returt_statuse=E_OK;
    }
    return returt_statuse;
}


Std_ReturnType adc_start_conversion_interrupt(const adc_t *adc,analog_channel_select_t analog_channel_select){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
    if(NULL!=adc ){
        /*select channel */
        adc_select_channel(adc,analog_channel_select);
        /*start conversion */
        
        adc_start(adc);
        
       
        returt_statuse=E_OK;
    }
    return returt_statuse;
    
}

static inline void adc_pin_cfg(analog_channel_select_t analog_channel_select){


   
        switch(analog_channel_select){
            case Channel_0_A0:
               SET_BIT(TRISA,GPIO_PIN0);
                ADCON1bits.PCFG=(UNTILE_AN0);
                break;
                case Channel_1_A1:
                SET_BIT(TRISA,GPIO_PIN1);
                 ADCON1bits.PCFG=(UNTILE_AN1);
                break;
                case Channel_2_A2:
                SET_BIT(TRISA,GPIO_PIN2);
                 ADCON1bits.PCFG=(UNTILE_AN2);
                break;
                case Channel_3_A3:
                SET_BIT(TRISA,GPIO_PIN3);
                 ADCON1bits.PCFG=(UNTILE_AN3);
                break;
                case Channel_4_A5:
                SET_BIT(TRISA,GPIO_PIN5);
                 ADCON1bits.PCFG=(UNTILE_AN4);
                break;
                case Channel_5_E0:
                SET_BIT(TRISE,GPIO_PIN0);
                 ADCON1bits.PCFG=(UNTILE_AN5);
                break;
                case Channel_6_E1:
                SET_BIT(TRISE,GPIO_PIN1);
                 ADCON1bits.PCFG=(UNTILE_AN6);
                break;
                case Channel_7_E2:
               SET_BIT(TRISE,GPIO_PIN2);
                 ADCON1bits.PCFG=(UNTILE_AN7);
                break;
                case Channel_8_B2:
               SET_BIT(TRISB,GPIO_PIN2);
                 ADCON1bits.PCFG=(UNTILE_AN8);
                break;
                case Channel_9_B3:
                SET_BIT(TRISB,GPIO_PIN3);
                 ADCON1bits.PCFG=(UNTILE_AN9);
                break;
                case Channel_10_B1:
                SET_BIT(TRISB,GPIO_PIN1);
                 ADCON1bits.PCFG=(UNTILE_AN10);
                break;
                case Channel_11_B4:
                SET_BIT(TRISB,GPIO_PIN4);
                 ADCON1bits.PCFG=(UNTILE_AN11);
                break;
                case Channel_12_B0:
                SET_BIT(TRISB,GPIO_PIN0);
                 ADCON1bits.PCFG=(UNTILE_AN12);
                break;
            default:
                // do nothing
                break;
        }
    
        
    
}

static inline void adc_Vref_cfg(const adc_t *adc){
    
    if(NULL!=adc && NULL!=adc){
        
        if(VOLTAGE_EXTERNAL == adc->voltage_refrence_mode){
            voltage_reference_external();
        }
        else if(VOLTAGE_INTERRNAL==adc->voltage_refrence_mode){
            voltage_reference_internal();
        }
        else{
            voltage_reference_internal();
        }
    }
}







static inline void adc_reading_mode_cfg(const adc_t *adc){
    if(NULL!=adc){
        if(ADC_RIGHT_MODE==adc->reading_mode){
            Right_Justified();
        }
        else if(ADC_LIFT_MODE==adc->reading_mode){
            Left_Justified();
        }
        else{
            Right_Justified();
        }
        
    }
    
}


void ADC_ISR(void){
    AD_Converter_Interrupt_CLEAR_Flag_bit();
    
    if(ADC_Interrupt_handler){
        ADC_Interrupt_handler();
    }
}