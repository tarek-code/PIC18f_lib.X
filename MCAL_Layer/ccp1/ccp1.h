/* 
 * File:   ccp1.h
 * Author: Unlimited
 *
 * Created on July 22, 2023, 7:07 PM
 */

#ifndef CCP1_H
#define	CCP1_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"
#include "ccp1_cfg.h"
#include "../Timer2/timer2.h"

/*Section macros */

#define CCP1_DISABLE                                   ((uint8)(0x00))
#define CCP1_CAPTURE_MODE_EVERY_FALLING_EDGE            ((uint8)(0x04))
#define CCP1_CAPTURE_MODE_EVERY_RISING_EDGE            ((uint8)(0x05))
#define CCP1_CAPTURE_MODE_EVERY_4TH_RISING_EDGE        ((uint8)(0x06))
#define CCP1_CAPTURE_MODE_EVERY_16TH_RISING_EDGE       ((uint8)(0x07))
#define CCP1_COMPARE_MODE_SET_PIN_HIGH                 ((uint8) (0x08))
#define CCP1_COMPARE_MODE_SET_PIN_LOW                   ((uint8)(0x09))
#define CCP1_COMPARE_MODE_SET_INT_SW                    ((uint8)(0x0A))
#define CCP1_COMPARE_MODE_SET_PIN_TOGGILE               ((uint8)(0x02))
#define CCP1_COMPARE_MODE_SET_SPECIAL_EVENT             ((uint8)(0x0B))
#define CCP1_PWM_MODE                                   ((uint8)(0x0C))


#define CCP1_COMPARE_DONE (0x01)
#define CCP1_COMPARE_NOT_DONE (0x00)

#define CCP1_CAPTURE_DONE (0x01)
#define CCP1_CAPTURE_NOT_DONE (0x00)




/*Section macros function  */
#define CCP1_CHOOSEING_MODE(x) (CCP1CONbits.CCP1M=x)


/*Section Data type */

typedef enum{
    DEFAULT=0,
    CCP1_CCP2_TIMER3 =0,
            CCP1_TIMER1_CCP2_TIMER3,
            CCP1_CCP2_TIMER1
}ccp1_capture_compare_timer_t;

typedef enum{
    CCP1_COMPARE_MODE_SELECTED =0,
            CCP1_CAPTURE_MODE_SELECTED,
            CCP1_PWM_MODE_SELECTED
}ccp1_modes_t;

typedef union {
    struct{
        uint8 ccp1_reg_low;
        uint8 ccp1_reg_high ;
    };
    struct{
        uint16 ccp1_16_reg;
    };
}ccp1_reg_t;


typedef struct {
    ccp1_modes_t ccp1_mode;
    uint8 ccp1_sub_mode;
    pin_cfg_t ccp1_pin;
    ccp1_capture_compare_timer_t ccp1_capture_compare_timer;
    #if CCP1_ENABLE_FEATURE==ENABLE_FEATURE
    void (* ccp1_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 ccp1_priority:1;
   
    #endif
#if (CCP1_SELECT_MODE==CCP1_PWM_MODE_CFG)
    uint32 pwm_frq;
    timer2_Prescaler_t ccp1_timer2_pre;
    timer2_Postscale_t ccp1_timer2_post;
#endif
}ccp1_t;




/*Section function declaration  */

Std_ReturnType ccp1_int(const ccp1_t *ptr);
Std_ReturnType ccp1_deint(const ccp1_t *ptr);

#if (CCP1_SELECT_MODE==CCP1_CAPTURE_MODE_CFG)
    Std_ReturnType ccp1_capture_check(uint8 *statuse );
    Std_ReturnType ccp1_capture_read_value(uint16 *value );
#endif

    #if (CCP1_SELECT_MODE==CCP1_COMPARE_MODE_CFG)
    Std_ReturnType ccp1_compare_check(uint8 *statuse );
    Std_ReturnType ccp1_compare_set_value(uint16 value );
#endif

    #if (CCP1_SELECT_MODE==CCP1_PWM_MODE_CFG)
    Std_ReturnType ccp1_pwm_set_duty(uint8 duty );
    Std_ReturnType ccp1_pwm_start(void );
    Std_ReturnType ccp1_pwm_stop(void);
#endif

#endif	/* CCP1_H */

