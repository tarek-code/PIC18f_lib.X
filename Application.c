/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"

  uint16 reading_1;
 uint16 reading_2;

  uint8 ADC_Start = 0;
 uint8 conv1[6];
 uint8 conv2[6];

 uint16 Degree_1;
  uint16 Degree_2;

chr_lcd_4_bit lcd = {
    .chr_lcd_e_pin.direction = GPIO_OUTPUT,
    .chr_lcd_e_pin.level = GPIO_LOW,
    .chr_lcd_e_pin.pin = GPIO_PIN1,
    .chr_lcd_e_pin.port = PORTC_INDX,

    .chr_lcd_rs_pin.direction = GPIO_OUTPUT,
    .chr_lcd_rs_pin.level = GPIO_LOW,
    .chr_lcd_rs_pin.pin = GPIO_PIN0,
    .chr_lcd_rs_pin.port = PORTC_INDX,

    .data_pin[0].direction = GPIO_OUTPUT,
    .data_pin[0].level = GPIO_LOW,
    .data_pin[0].pin = GPIO_PIN2,
    .data_pin[0].port = PORTC_INDX,

    .data_pin[1].direction = GPIO_OUTPUT,
    .data_pin[1].level = GPIO_LOW,
    .data_pin[1].pin = GPIO_PIN3,
    .data_pin[1].port = PORTC_INDX,

    .data_pin[2].direction = GPIO_OUTPUT,
    .data_pin[2].level = GPIO_LOW,
    .data_pin[2].pin = GPIO_PIN4,
    .data_pin[2].port = PORTC_INDX,

    .data_pin[3].direction = GPIO_OUTPUT,
    .data_pin[3].level = GPIO_LOW,
    .data_pin[3].pin = GPIO_PIN5,
    .data_pin[3].port = PORTC_INDX,
    

    
};

void ADC_interrupt(void);


adc_t adc_1 = {
    .ADC_callback = ADC_interrupt,
    
    .AD_acquisition_time_select_bits = TAD_12,
    .AD_conversion_clock_select_bits = FOSC_16,
    .analog_channel_select = Channel_0_A0,
    .priority = PRIORITY_HIGH,
    .reading_mode = ADC_RIGHT_MODE,
    .voltage_refrence_mode = VOLTAGE_INTERRNAL
};

void ADC_interrupt(void) {
  
    if (0 == ADC_Start) {
        adc_reading_value(&adc_1, &reading_1);
             
            ADC_Start=1;
        } else if (1 == ADC_Start) {
            adc_reading_value(&adc_1, &reading_2);
             
            ADC_Start=0;
        }  else {
            // do nothing 
        }
          
}

int main() {
    adc_int(&adc_1);
    chr_lcd_4_int(&lcd);
    chr_lcd_4_send_cmd(&lcd,_CHR_LCD_DISPLAY_ON_CURSOR_OFF);


   
    chr_lcd_4_send_cmd(&lcd,_CHR_LCD_CLEAR_DISPLAY);
    
            chr_lcd_4_send_string_pos(&lcd, 1, 1, "Deg_1: ");
   
    chr_lcd_4_send_string_pos(&lcd, 2, 1, "Deg_2: ");
    


    
    while (1) {

      
        if (0 == ADC_Start) {
             adc_start_conversion_interrupt(&adc_1, Channel_0_A0);
        } else if (1 == ADC_Start) {
            adc_start_conversion_interrupt(&adc_1, Channel_1_A1);
        }  else {
            // do nothing 
        }
          

        
        Degree_1=reading_1*4.88f;
                  Degree_1/=10;
                  
                   Degree_2=reading_2*4.88f;
                  Degree_2/=10;
                  
                convert_short_to_str(Degree_1,conv1);
                convert_short_to_str(Degree_2,conv2);
      
                 
                  
                   
             chr_lcd_4_send_string_pos(&lcd, 1, 7,conv1);
       
                
             chr_lcd_4_send_string_pos(&lcd, 2, 7,conv2);
             




        
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}