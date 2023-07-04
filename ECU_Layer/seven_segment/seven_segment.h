/* 
 * File:   seven_segment.h
 * Author: Unlimited
 *
 * Created on May 2, 2023, 2:55 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "seven_segment_cfg.h"
/*Section macros */
#define MAX_NUMBER_SEVEN_SEGMENT_PINS 4
/*Section macros function  */

/*Section Data type */
typedef enum{
            SEVEN_SEGMENT_PIN_0=0,
            SEVEN_SEGMENT_PIN_1,
            SEVEN_SEGMENT_PIN_2,
            SEVEN_SEGMENT_PIN_3
            
}seven_segment_pins_t;

typedef enum{
    SEVEN_SEGMENT_ANODE,
           SEVEN_SEGMENT_CATHODE 
}seven_segment_type_t;

typedef struct{
    pin_cfg_t seven_pins[MAX_NUMBER_SEVEN_SEGMENT_PINS];
    seven_segment_type_t seven_type;
}seven_segment_t;

/*Section function declaration  */
Std_ReturnType seven_segment_int(const seven_segment_t *seven_segment);
Std_ReturnType seven_segment_write_number(const seven_segment_t *seven_segment,uint8 number);
#endif	/* SEVEN_SEGMENT_H */

