/* 
 * File:   LED.h
 * Author: Unlimited
 *
 * Created on April 22, 2023, 11:05 PM
 */

#ifndef LED_H
#define	LED_H



/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "led_cfg.h"
/*Section macros */

/*Section macros function  */

/*Section Data type */
typedef enum
{
            LED_OFF=0,
            LED_ON
}led_status_t;

typedef struct{
    
    uint8 port_name:4;
    uint8 pin_number:3;
    uint8 led_status:1;
}led_cfg_t;

/*Section function declaration  */
Std_ReturnType led_int(led_cfg_t *led_cfg);
Std_ReturnType led_on(led_cfg_t *led_cfg);
Std_ReturnType led_off(led_cfg_t *led_cfg);
Std_ReturnType led_toggel(led_cfg_t *led_cfg);
#endif	/* LED_H */

