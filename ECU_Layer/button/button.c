#include "button.h"

/**
 * 
 * @param button_cfg
 * @return 
 */
Std_ReturnType button_int(const button_cfg_t *button_cfg){
    
    Std_ReturnType return_state=E_NOT_OK;
    if(NULL!=button_cfg)
    {
        gpio_pin_direction_int(&(button_cfg->button_pin));
        return_state =E_OK;
    }
    return return_state;
}

/**
 * 
 * @param button_cfg
 * @param button_state
 * @return 
 */
Std_ReturnType button_read(const button_cfg_t *button_cfg,button_state_t *button_state){
    level_t level=0;
    Std_ReturnType return_state=E_NOT_OK;
    if(NULL!=button_cfg && NULL!=button_state)
    {
        switch(button_cfg->button_type){
            case BUTTON_ACTIVE_HIGH:
                gpio_pin_read_level(&(button_cfg->button_pin),&level);
                if(level==GPIO_HIGH){
                    *button_state=BUTTON_PRESSED;
                }
                else{
                    *button_state=BUTTON_RELEASED;
                }
                break;
                
            case BUTTON_ACTIVE_LOW:
                gpio_pin_read_level(&(button_cfg->button_pin),&level);
                if(level==GPIO_LOW){
                    *button_state=BUTTON_PRESSED;
                }
                else{
                    *button_state=BUTTON_RELEASED;
                }
                break;
            default:
                // do nothing 
                break;
        }
        return_state =E_OK;
    }
    return return_state;
}
