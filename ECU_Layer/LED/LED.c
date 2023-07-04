#include "LED.h"

/**
 * 
 * @param led_cfg
 * @return 
 */
Std_ReturnType led_int(led_cfg_t *led_cfg)
{
    Std_ReturnType returt_state=E_NOT_OK;
    pin_cfg_t pin_cfg={
        .direction=GPIO_OUTPUT,
        .level=led_cfg->led_status,
        .pin=led_cfg->pin_number,
        .port=led_cfg->port_name
    };
    if(NULL!=led_cfg)
    {
        gpio_pin_int(&pin_cfg);
    }
    return returt_state;
}

/**
 * 
 * @param led_cfg
 * @return 
 */
Std_ReturnType led_on(led_cfg_t *led_cfg){
    Std_ReturnType returt_state=E_NOT_OK;
    pin_cfg_t pin_cfg={
        .direction=GPIO_OUTPUT,
        .level=led_cfg->led_status,
        .pin=led_cfg->pin_number,
        .port=led_cfg->port_name
    };
    if(NULL!=led_cfg)
    {
        gpio_pin_write_level(&pin_cfg,GPIO_HIGH);
    }
    return returt_state;
}

/**
 * 
 * @param led_cfg
 * @return 
 */
Std_ReturnType led_off(led_cfg_t *led_cfg){
    Std_ReturnType returt_state=E_NOT_OK;
    pin_cfg_t pin_cfg={
        .direction=GPIO_OUTPUT,
        .level=led_cfg->led_status,
        .pin=led_cfg->pin_number,
        .port=led_cfg->port_name
    };
    if(NULL!=led_cfg)
    {
        gpio_pin_write_level(&pin_cfg,GPIO_LOW);
    }
    return returt_state;
}


/**
 * 
 * @param led_cfg
 * @return 
 */
Std_ReturnType led_toggel(led_cfg_t *led_cfg){
    Std_ReturnType returt_state=E_NOT_OK;
    pin_cfg_t pin_cfg={
        .direction=GPIO_OUTPUT,
        .level=led_cfg->led_status,
        .pin=led_cfg->pin_number,
        .port=led_cfg->port_name
    };
    if(NULL!=led_cfg)
    {
        gpio_pin_toggle_level(&pin_cfg);
    }
    return returt_state;
}
