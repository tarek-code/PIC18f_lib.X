/* 
 * File:   keypad.h
 * Author: Unlimited
 *
 * Created on May 2, 2023, 11:53 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/*Section includes */

#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "keypad_cfg.h"

/*Section macros */

#define KEYPAD_ROWS     4
#define KEYPAD_COLOMNS   4
/*Section macros function  */

/*Section Data type */
typedef struct{
    pin_cfg_t rows[KEYPAD_ROWS];
    pin_cfg_t colomns[KEYPAD_COLOMNS];
}keypad_t;

/*Section function declaration  */
Std_ReturnType keypad_int(const keypad_t *keypad);
Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value);
#endif	/* KEYPAD_H */

