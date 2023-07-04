#include "dc_motor.h"

/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_int(const motor_t *motor){
    
    Std_ReturnType return_state=E_NOT_OK;
    
    
    if(NULL!=motor){
        gpio_pin_direction_int(&(motor->motor[MOTOR_PIN_1]));
        gpio_pin_write_level(&(motor->motor[MOTOR_PIN_1]),motor->motor[MOTOR_PIN_1].level);
        gpio_pin_direction_int(&(motor->motor[MOTOR_PIN_2]));
        gpio_pin_write_level(&(motor->motor[MOTOR_PIN_2]),motor->motor[MOTOR_PIN_2].level);
        return_state=E_OK;
    }
    return return_state;
    
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_right(const motor_t *motor){
     Std_ReturnType return_state=E_NOT_OK;
    
    if(NULL!=motor){
        gpio_pin_write_level(&(motor->motor[MOTOR_PIN_1]),MOTOR_ON);
          gpio_pin_write_level(&(motor->motor[MOTOR_PIN_2]),MOTOR_OFF);
        return_state=E_OK;
    }
    return return_state;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_left(const motor_t *motor){
     Std_ReturnType return_state=E_NOT_OK;
    
    if(NULL!=motor){
        gpio_pin_write_level(&(motor->motor[MOTOR_PIN_1]),MOTOR_OFF);
          gpio_pin_write_level(&(motor->motor[MOTOR_PIN_2]),MOTOR_ON);
        return_state=E_OK;
    }
    return return_state;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_stop(const motor_t *motor){
     Std_ReturnType return_state=E_NOT_OK;
   
    if(NULL!=motor){
      gpio_pin_write_level(&(motor->motor[MOTOR_PIN_1]),MOTOR_OFF);
          gpio_pin_write_level(&(motor->motor[MOTOR_PIN_2]),MOTOR_OFF);
        return_state=E_OK;
    }
    return return_state;
}

