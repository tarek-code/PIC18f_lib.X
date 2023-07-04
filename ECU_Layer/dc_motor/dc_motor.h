/* 
 * File:   dc_motor.h
 * Author: Unlimited
 *
 * Created on April 28, 2023, 9:59 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "dc_motor_cfg.h"
/*Section macros */

/*Section macros function  */

/*Section Data type */

typedef enum{
    MOTOR_OFF,
            MOTOR_ON
}motor_state_t;



typedef enum{
            MOTOR_PIN_1,
            MOTOR_PIN_2
}motor_number;
typedef struct{
    pin_cfg_t motor[2];
}motor_t;
/*Section function declaration  */
Std_ReturnType motor_int(const motor_t *motor);
Std_ReturnType motor_right(const motor_t *motor);
Std_ReturnType motor_left(const motor_t *motor);
Std_ReturnType motor_stop(const motor_t *motor);
#endif	/* DC_MOTOR_H */

