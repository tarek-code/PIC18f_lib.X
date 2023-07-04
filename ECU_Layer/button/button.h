/* 
 * File:   button.h
 * Author: Unlimited
 *
 * Created on April 28, 2023, 1:15 AM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "button_cfg.h"
/*Section macros */

/*Section macros function  */

/*Section Data type */

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_type_t;

typedef struct{
    pin_cfg_t button_pin;
    button_state_t button_state;
    button_type_t  button_type;
}button_cfg_t;

/*Section function declaration  */
Std_ReturnType button_int(const button_cfg_t *button_cfg);
Std_ReturnType button_read(const button_cfg_t *button_cfg,button_state_t *button_state);
#endif	/* BUTTON_H */

