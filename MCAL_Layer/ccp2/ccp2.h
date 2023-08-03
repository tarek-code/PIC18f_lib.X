/* 
 * File:   ccp2.h
 * Author: Unlimited
 *
 * Created on July 22, 2023, 8:56 PM
 */

#ifndef CCP2_H
#define	CCP2_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"
#include "ccp2_cfg.h"
#include "../Timer2/timer2.h"

/*Section macros */

#define CCP2_DISABLE                                   ((uint8)(0x00))
#define CCP2_CAPTURE_MODE_EVERY_FALLING_EDGE            ((uint8)(0x04))
#define CCP2_CAPTURE_MODE_EVERY_RISING_EDGE            ((uint8)(0x05))
#define CCP2_CAPTURE_MODE_EVERY_4TH_RISING_EDGE        ((uint8)(0x06))
#define CCP2_CAPTURE_MODE_EVERY_16TH_RISING_EDGE       ((uint8)(0x07))
#define CCP2_COMPARE_MODE_SET_PIN_HIGH                 ((uint8) (0x08))
#define CCP2_COMPARE_MODE_SET_PIN_LOW                   ((uint8)(0x09))
#define CCP2_COMPARE_MODE_SET_INT_SW                    ((uint8)(0x0A))
#define CCP2_COMPARE_MODE_SET_PIN_TOGGILE               ((uint8)(0x02))
#define CCP2_COMPARE_MODE_SET_SPECIAL_EVENT             ((uint8)(0x0B))
#define CCP2_PWM_MODE                                   ((uint8)(0x0C))


#define CCP2_COMPARE_DONE (0x01)
#define CCP2_COMPARE_NOT_DONE (0x00)

#define CCP2_CAPTURE_DONE (0x01)
#define CCP2_CAPTURE_NOT_DONE (0x00)




/*Section macros function  */
#define CCP2_CHOOSEING_MODE(x) (CCP2CONbits.CCP2M=x)


/*Section Data type */

typedef enum{
    dEFAULT=0,
    cCP1_CCP2_TIMER3 =0,
            cCP1_TIMER1_CCP2_TIMER3,
            cCP1_CCP2_TIMER1
}ccp2_capture_compare_timer_t;

typedef enum{
    CCP2_COMPARE_MODE_SELECTED =0,
            CCP2_CAPTURE_MODE_SELECTED,
            CCP2_PWM_MODE_SELECTED
}ccp2_modes_t;

typedef union {
    struct{
        uint8 ccp2_reg_low;
        uint8 ccp2_reg_high ;
    };
    struct{
        uint16 ccp2_16_reg;
    };
}ccp2_reg_t;


typedef struct {
    ccp2_modes_t ccp2_mode;
    uint8 ccp2_sub_mode;
    pin_cfg_t ccp2_pin;
    ccp2_capture_compare_timer_t ccp2_capture_compare_timer;
    #if CCP2_ENABLE_FEATURE==ENABLE_FEATURE
    void (* ccp2_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 ccp2_priority:1;
   
    #endif
#if (CCP2_SELECT_MODE==CCP2_PWM_MODE_CFG)
    uint32 pwm_frq;
    timer2_Prescaler_t ccp2_timer2_pre;
    timer2_Postscale_t ccp2_timer2_post;
#endif
}ccp2_t;



/*Section function declaration  */

Std_ReturnType ccp2_int(const ccp2_t *ptr);
Std_ReturnType ccp2_deint(const ccp2_t *ptr);

#if (CCP2_SELECT_MODE==CCP2_CAPTURE_MODE_CFG)
    Std_ReturnType ccp2_capture_check(uint8 *statuse );
    Std_ReturnType ccp2_capture_read_value(uint16 *value );
#endif

    #if (CCP2_SELECT_MODE==CCP2_COMPARE_MODE_CFG)
    Std_ReturnType ccp2_compare_check(uint8 *statuse );
    Std_ReturnType ccp2_compare_set_value(uint16 value );
#endif

    #if (CCP2_SELECT_MODE==CCP2_PWM_MODE_CFG)
    Std_ReturnType ccp2_pwm_set_duty(uint8 duty );
    Std_ReturnType ccp2_pwm_start(void );
    Std_ReturnType ccp2_pwm_stop(void);
#endif

#endif	/* CCP2_H */

