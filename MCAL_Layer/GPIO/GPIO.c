#include "GPIO.h"

volatile uint8 *Port_Regs[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *Lat_Regs[]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *Tris_Regs[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};


#if PIN_CONFIG==CONFIG_ENABLE
/**
 * 
 * @param pin_cfg
 * @return 
 */
Std_ReturnType gpio_pin_direction_int(const pin_cfg_t *pin_cfg)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg)
    {
        switch(pin_cfg->direction)
        {
            case GPIO_OUTPUT:
                CLEAR_BIT(*Tris_Regs[pin_cfg->port],pin_cfg->pin);
                return_status=E_OK;
                break;
                
            case GPIO_INPUT:
                SET_BIT(*Tris_Regs[pin_cfg->port],pin_cfg->pin);
                return_status=E_OK;
                break;
                
            default:
                
                break;
                  
        }
    }
    return return_status;
}





/**
 * 
 * @param pin_cfg
 * @param direction
 * @return 
 */
Std_ReturnType gpio_pin_get_direction_state(const pin_cfg_t *pin_cfg,direction_t *direction)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg && NULL!=direction)
    {
        *direction=READ_BIT(*Tris_Regs[pin_cfg->port],pin_cfg->pin);
        return_status=E_OK;
    }
    return return_status;
}

/**
 * 
 * @param pin_cfg
 * @param level
 * @return 
 */
Std_ReturnType gpio_pin_write_level(const pin_cfg_t *pin_cfg,level_t level)
{
    
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg)
    {
        
        switch(level)
        {
            case GPIO_HIGH:
                 SET_BIT(*(Lat_Regs[pin_cfg->port]),pin_cfg->pin);
                
                break;
               
            case GPIO_LOW:
                CLEAR_BIT(*Lat_Regs[pin_cfg->port],pin_cfg->pin);
                return_status=E_OK;
                break;
        }
    }
    return return_status;
}

/**
 * 
 * @param pin_cfg
 * @param level
 * @return 
 */
Std_ReturnType gpio_pin_read_level(const pin_cfg_t *pin_cfg,level_t *level)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg && NULL!=level)
    {
        *level=READ_BIT(*Port_Regs[pin_cfg->port],pin_cfg->pin);
        return_status=E_OK;
    }
    return return_status;
}


/**
 * 
 * @param pin_cfg
 * @return 
 */
Std_ReturnType gpio_pin_toggle_level(const pin_cfg_t *pin_cfg)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg)
    {
        TOGGLE_BIT(*Lat_Regs[pin_cfg->port],pin_cfg->pin);
        return_status=E_OK;
    }
    return return_status;
}





Std_ReturnType gpio_pin_int(const pin_cfg_t *pin_cfg)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(NULL!=pin_cfg)
    {
            gpio_pin_direction_int(pin_cfg);
            gpio_pin_write_level(pin_cfg,pin_cfg->level);
    }
    
    return return_status;
}






#endif

#if PORT_CONFIG==CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
Std_ReturnType gpio_port_direction_int(ports_indx_t port,uint8 direction)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(port<PORT_MAX)
    {
        *Tris_Regs[port]=direction;
        return_status=E_OK;
    }
    else
    {
        //do nothing 
    }
    return return_status;
}
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
Std_ReturnType gpio_port_get_direction_state(ports_indx_t port,uint8 *direction)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(port<PORT_MAX && NULL!=direction)
    {
        *direction=*(Tris_Regs[port]);
        return_status=E_OK;
    }
    else
    {
        //do nothing 
    }
    return return_status;
}

/**
 * 
 * @param port
 * @param level
 * @return 
 */
Std_ReturnType gpio_port_write_level(ports_indx_t port,uint8 level)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(port<PORT_MAX)
    {
        *Lat_Regs[port]=level;
        return_status=E_OK;
    }
    else
    {
        //do nothing 
    }
    return return_status;
}

/**
 * 
 * @param port
 * @param level
 * @return 
 */
Std_ReturnType gpio_port_read_level(ports_indx_t port,uint8 *level)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(port<PORT_MAX && NULL!=level)
    {
       *level= *(Lat_Regs[port]);
        return_status=E_OK;
    }
    else
    {
        //do nothing 
    }
    return return_status;
}

/**
 * 
 * @param port
 * @return 
 */
Std_ReturnType gpio_port_toggle_level(ports_indx_t port)
{
    Std_ReturnType return_status=E_NOT_OK;
    if(port<PORT_MAX)
    {
      *(Lat_Regs[port])^=PORT_MASK;
        return_status=E_OK;
    }
    else
    {
        //do nothing 
    }
    return return_status;
}

#endif

