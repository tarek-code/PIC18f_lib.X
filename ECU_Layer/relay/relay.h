/* 
 * File:   relay.h
 * Author: Unlimited
 *
 * Created on April 28, 2023, 7:19 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "relay_cfg.h"
/*Section macros */

/*Section macros function  */

/*Section Data type */

typedef enum{
     RELAY_OFF,
    RELAY_ON
   
}relay_status_t;

typedef struct{
    uint8 relay_pin:3;
    uint8 relay_port:4;
    uint8 relay_status:1;
    
}relay_cfg_t;

/*Section function declaration  */
Std_ReturnType relay_int(const relay_cfg_t *relay);
Std_ReturnType relay_on(const relay_cfg_t *relay);
Std_ReturnType relay_off(const relay_cfg_t *relay);
Std_ReturnType relay_toggel(const relay_cfg_t *relay);
#endif	/* RELAY_H */

