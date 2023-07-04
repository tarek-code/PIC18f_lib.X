#include "relay.h"

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_int(const relay_cfg_t *relay){
    
    pin_cfg_t relay_pin={
      .direction=GPIO_OUTPUT,
      .level=relay->relay_status,
      .pin=relay->relay_pin,
      .port=relay->relay_port
    };
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=relay){
        gpio_pin_direction_int(&relay_pin);
        gpio_pin_write_level(&relay_pin,relay->relay_status);
        return_status=E_OK;
    }
    return return_status;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_on(const relay_cfg_t *relay){
    pin_cfg_t relay_pin={
      .direction=GPIO_OUTPUT,
      .level=relay->relay_status,
      .pin=relay->relay_pin,
      .port=relay->relay_port
    };
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=relay){
        gpio_pin_write_level(&relay_pin,GPIO_HIGH);
        return_status=E_OK;
    }
    return return_status;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_off(const relay_cfg_t *relay){
    pin_cfg_t relay_pin={
      .direction=GPIO_OUTPUT,
      .level=relay->relay_status,
      .pin=relay->relay_pin,
      .port=relay->relay_port
    };
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=relay){
        gpio_pin_write_level(&relay_pin,GPIO_LOW);
        return_status=E_OK;
    }
    return return_status;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_toggel(const relay_cfg_t *relay){
    pin_cfg_t relay_pin={
      .direction=GPIO_OUTPUT,
      .level=relay->relay_status,
      .pin=relay->relay_pin,
      .port=relay->relay_port
    };
    Std_ReturnType return_status=E_NOT_OK;
    
    if(NULL!=relay){
        gpio_pin_toggle_level(&relay_pin);
        return_status=E_OK;
    }
    return return_status;
}
