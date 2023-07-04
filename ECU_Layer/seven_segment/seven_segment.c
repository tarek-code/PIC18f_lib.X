#include "seven_segment.h"

Std_ReturnType seven_segment_int(const seven_segment_t *seven_segment){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!= seven_segment){
       
      
            gpio_pin_direction_int(&(seven_segment->seven_pins[0]));
            gpio_pin_write_level(&(seven_segment->seven_pins[0]),seven_segment->seven_pins[0].level);
            
            gpio_pin_direction_int(&(seven_segment->seven_pins[1]));
            gpio_pin_write_level(&(seven_segment->seven_pins[1]),seven_segment->seven_pins[1].level);
            
            gpio_pin_direction_int(&(seven_segment->seven_pins[2]));
            gpio_pin_write_level(&(seven_segment->seven_pins[2]),seven_segment->seven_pins[2].level);
            
            gpio_pin_direction_int(&(seven_segment->seven_pins[3]));
            gpio_pin_write_level(&(seven_segment->seven_pins[3]),seven_segment->seven_pins[3].level);
        
        return_statuse=E_OK;
    }
    return return_statuse;
}

Std_ReturnType seven_segment_write_number(const seven_segment_t *seven_segment,uint8 number){
     Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!= seven_segment){
        if(seven_segment->seven_type==SEVEN_SEGMENT_CATHODE){
            gpio_pin_write_level(&(seven_segment->seven_pins[0]),(number>>0)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[1]),(number>>1)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[2]),(number>>2)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[3]),(number>>3)&0x01);
        }
        else{
            gpio_pin_write_level(&(seven_segment->seven_pins[0]),(number>>0)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[1]),(number>>1)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[2]),(number>>2)&0x01);
        
        gpio_pin_write_level(&(seven_segment->seven_pins[3]),(number>>3)&0x01);
        }
        
        return_statuse=E_OK;
    }
    return return_statuse;
    
}
