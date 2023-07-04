#include "keypad.h"

uint8 KEYPAD_SHAPE[KEYPAD_ROWS][KEYPAD_COLOMNS]={
                    {'7','8','9','/'},
                    {'4','5','6','*'},
                    {'1','2','3','-'},
                    {'#','0','=','+'}
                    };


Std_ReturnType keypad_int(const keypad_t *keypad){
    uint8 rows_counter=ZERO_INT;
    uint8 colomns_counter=ZERO_INT;
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=keypad){
        
        for(rows_counter=ZERO_INT;rows_counter<KEYPAD_ROWS;rows_counter++){
            gpio_pin_int(&(keypad->rows[rows_counter]));
        }
        
        for(colomns_counter=ZERO_INT;colomns_counter<KEYPAD_COLOMNS;colomns_counter++){
            gpio_pin_direction_int(&(keypad->colomns[colomns_counter]));
        }
        return_status=E_OK;
    }
    
    return return_status;
}

Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value){
    uint8 rows_counter=ZERO_INT;
    uint8 colomns_counter=ZERO_INT;
    uint8 counter=ZERO_INT;
    uint8 read_colomn=ZERO_INT;
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=keypad){
        
        for(rows_counter=0;rows_counter<KEYPAD_ROWS;rows_counter++){
            for(counter=0;counter<KEYPAD_ROWS;counter++){
                gpio_pin_write_level(&(keypad->rows[counter]),GPIO_LOW);             
            } 
           __delay_ms(1);// if the code didnt work again remember to focus in the delay and PORTC to trace the 1 for each row
            gpio_pin_write_level(&(keypad->rows[rows_counter]),GPIO_HIGH);
             
            for(colomns_counter=0;colomns_counter<KEYPAD_COLOMNS;colomns_counter++){
                gpio_pin_read_level(&(keypad->colomns[colomns_counter]),&read_colomn);
                if(read_colomn==GPIO_HIGH){
                 
                 *value=KEYPAD_SHAPE[rows_counter][colomns_counter];
             }
                
             
            }
            
             
             
        }
        
        return_status=E_OK;
    }
    
    return return_status;
}
