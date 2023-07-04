/* 
 * File:   GPIO.h
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:43 PM
 */

#ifndef GPIO_H
#define	GPIO_H



/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "gpio_cfg.h"
/*Section macros */


#define HWREG8(x)       (*((volatile uint8 *)(x)))

#define LATA_REG        (HWREG8(0xF89))
#define LATB_REG        (HWREG8(0XF8A))
#define LATC_REG        (HWREG8(0xF8B))
#define LATD_REG        (HWREG8(0xF8C))
#define LATE_REG        (HWREG8(0xF8D))

#define TRISA_REG        (HWREG8(0xF92))
#define TRISB_REG        (HWREG8(0xF93))
#define TRISC_REG        (HWREG8(0xF94))
#define TRISD_REG        (HWREG8(0xF95))
#define TRISE_REG        (HWREG8(0xF96))

#define PORTA_REG        (HWREG8(0xF80))
#define PORTB_REG        (HWREG8(0xF81))
#define PORTC_REG        (HWREG8(0xF82))
#define PORTD_REG        (HWREG8(0xF83))
#define PORTE_REG        (HWREG8(0xF84))

#define PIN_MAX          (9)
#define PORT_MAX         (5)

#define PORT_MASK        (0xFF)
/*Section macros function  */

/*Section Data type */

typedef enum
{
    GPIO_LOW=0,
    GPIO_HIGH
    
}level_t;

typedef enum
{
    GPIO_OUTPUT=0,
    GPIO_INPUT
            
}direction_t;

typedef enum
{
    
            GPIO_PIN0=0,
            GPIO_PIN1,
            GPIO_PIN2,
            GPIO_PIN3,
            GPIO_PIN4,
            GPIO_PIN5,
            GPIO_PIN6,
            GPIO_PIN7
}pins_t;

typedef enum
{
            PORTA_INDX=0,
            PORTB_INDX,
            PORTC_INDX,
            PORTD_INDX,
            PORTE_INDX
}ports_indx_t;

typedef struct{
        
    uint8 direction:1;
    uint8 level    :1;
    uint8 pin     :3;
    uint8 port    :3;
}pin_cfg_t;
/*Section function declaration  */
Std_ReturnType gpio_pin_direction_int(const pin_cfg_t *pin_cfg);
Std_ReturnType gpio_pin_int(const pin_cfg_t *pin_cfg);
Std_ReturnType gpio_pin_get_direction_state(const pin_cfg_t *pin_cfg,direction_t *direction);
Std_ReturnType gpio_pin_write_level(const pin_cfg_t *pin_cfg,level_t level);
Std_ReturnType gpio_pin_read_level(const pin_cfg_t *pin_cfg,level_t *level);
Std_ReturnType gpio_pin_toggle_level(const pin_cfg_t *pin_cfg);

Std_ReturnType gpio_port_direction_int(ports_indx_t port,uint8 direction);
Std_ReturnType gpio_port_get_direction_state(ports_indx_t port,uint8 *direction);
Std_ReturnType gpio_port_write_level(ports_indx_t port,uint8 level);
Std_ReturnType gpio_port_read_level(ports_indx_t port,uint8 *level);
Std_ReturnType gpio_port_toggle_level(ports_indx_t port);
#endif	/* GPIO_H */

