/* 
 * File:   ADC.h
 * Author: Unlimited
 *
 * Created on May 26, 2023, 5:42 PM
 */

#ifndef ADC_H
#define	ADC_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"
#include "ADC_cfg.h"
/*Section macros */
#define ADC_INTERRUPT_ENABLE (0x01u)
#define ADC_INTERRUPT_DISABLE (0x00u)

#define VOLTAGE_EXTERNAL  (0x01u)
#define VOLTAGE_INTERRNAL  (0x00u)

#define ADC_RIGHT_MODE  (0x01u)
#define ADC_LIFT_MODE   (0x00u)

#define AD_Conversion_Status() (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION() (ADCON0bits.GO_nDONE=1)

#define AD_Converter_module_is_enabled()  (ADCON0bits.ADON=1) 
#define AD_Converter_module_is_disabled()  (ADCON0bits.ADON=0)

#define voltage_reference_external() do{ADCON1bits.VCFG1=1;\
                                        ADCON1bits.VCFG0=1;\
                                       }while(0)
                                                                            
#define voltage_reference_internal() do{ADCON1bits.VCFG1=0;\
                                        ADCON1bits.VCFG0=0;\
                                        }while(0)


/*Analog configration*/
#define UNTILE_AN0  (0b1110)
#define UNTILE_AN1  (0b1101)
#define UNTILE_AN2  (0b1100)
#define UNTILE_AN3  (0b1011)
#define UNTILE_AN4  (0b1010)
#define UNTILE_AN5  (0b1001)
#define UNTILE_AN6  (0b1000)
#define UNTILE_AN7  (0b0111)
#define UNTILE_AN8  (0b0110)
#define UNTILE_AN9  (0b0101)  
#define UNTILE_AN10 (0b0100)
#define UNTILE_AN11 (0b0011)
#define UNTILE_AN12 (0b0010)
#define ALL_ANALOG  (0b0000)
#define ALL_DIGITAL (0b1111)

#define RIGHT_CONFIG_ANALOG_MODE(congif) (ADCON1bits.PCFG=config)

#define Right_Justified() (ADCON2bits.ADFM=1)
#define Left_Justified() (ADCON2bits.ADFM=0)


#define Acquisition_Time_Select_MODE(congif) (ADCON2bits.ACQT=config)
#define Conversion_Clock_Select_MODE(_congif) (ADCON2bits.ADCS=_config)


/*Section macros function  */

/*Section Data type */

typedef enum{
    Channel_0_A0=0,
            Channel_1_A1,
            Channel_2_A2, //V-
            Channel_3_A3,   //V+
            Channel_4_A5,
            Channel_5_E0,
            Channel_6_E1,
            Channel_7_E2,
            Channel_8_B2,
            Channel_9_B3,
            Channel_10_B1,
            Channel_11_B4,
            Channel_12_B0,
}analog_channel_select_t;

typedef enum{
    FOSC_2=0 ,
             FOSC_8, 
             FOSC_32 ,
             FRC ,
             FOSC_4 ,
             FOSC_16 ,
             FOSC_64 
            
}AD_conversion_clock_select_bits_t;


typedef enum{
    TAD_0 = 0,
            TAD_2,
            TAD_4,
            TAD_6,
            TAD_8,
            TAD_12,
            TAD_16,
            TAD_20
}AD_acquisition_time_select_bits_t;


typedef struct{
#if ADC_ENABLE_FEATURE==ENABLE_FEATURE
    void (* ADC_callback)(void);
    priority_t priority;
#endif
    AD_acquisition_time_select_bits_t AD_acquisition_time_select_bits;
    AD_conversion_clock_select_bits_t   AD_conversion_clock_select_bits;
    analog_channel_select_t analog_channel_select;
    uint8 reading_mode:1;
    uint8 voltage_refrence_mode:1;
}adc_t;
/*Section function declaration  */
Std_ReturnType adc_int(const adc_t *adc);
Std_ReturnType timer0();
Std_ReturnType adc_start(const adc_t *adc);
Std_ReturnType adc_reading_value(const adc_t *adc,uint16 *value);
Std_ReturnType adc_is_conversion_done(const adc_t *adc,uint8 *statuse);
Std_ReturnType adc_deint(const adc_t *adc);
Std_ReturnType adc_select_channel(const adc_t *adc,analog_channel_select_t analog_channel_select);
Std_ReturnType adc_get_conversion_blocking(const adc_t *adc,uint16 *value,analog_channel_select_t analog_channel_select);
Std_ReturnType adc_start_conversion_interrupt(const adc_t *adc,analog_channel_select_t analog_channel_select);
#endif	/* ADC_H */

