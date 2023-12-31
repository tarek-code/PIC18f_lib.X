/* 
 * File:   timer0.h
 * Author: Unlimited
 *
 * Created on July 3, 2023, 8:29 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */
#define TIMER0_PREORITY_HIGH (1)
#define TIMER0_PREORITY_LOW (0)

#define TIMER0_ON       (1)
#define TIMER0_OFF      (0)

#define TIMER0_8_BIT_MODE   (1)  
#define TIMER0_16_BIT_MODE  (0)

#define TIMER0_TIMER        (0)
#define TIMER0_COUNTER      (1)    

#define TIMER0_HIGH_LOW_EDGE    (1)
#define TIMER0_LOW_HIGH_EDGE    (0)

#define TIMER0_PRESCALER_ON     (0)
#define TIMER0_PRESCALER_OFF    (1)


/*Analog configration*/



/*Section macros function  */

#define TIMER0_ON_CFG()     (T0CONbits.TMR0ON=1)
#define TIMER0_OFF_CFG()    (T0CONbits.TMR0ON=0)


#define TIMER0_8_BIT_MODE_CFG()   (T0CONbits.T08BIT=1)  
#define TIMER0_16_BIT_MODE_CFG()  (T0CONbits.T08BIT=0)

#define TIMER0_TIMER_CFG()        (T0CONbits.T0CS=0)
#define TIMER0_COUNTER_CFG()      (T0CONbits.T0CS=1)    

#define TIMER0_HIGH_LOW_EDGE_CFG()    (T0CONbits.T0SE=1)
#define TIMER0_LOW_HIGH_EDGE_CFG()    (T0CONbits.T0SE=0)

#define TIMER0_PRESCALER_ON_CFG()     (T0CONbits.PSA=0)
#define TIMER0_PRESCALER_OFF_CFG()    (T0CONbits.PSA=1)

#define TIMER0_SET_PRESCALER(x)       (T0CONbits.T0PS=x)


/*Section Data type */
typedef enum{
    TIMER0_DIV_BY_2 =0,
            TIMER0_DIV_BY_4,
            TIMER0_DIV_BY_8,
            TIMER0_DIV_BY_16,
            TIMER0_DIV_BY_32,
            TIMER0_DIV_BY_64,
            TIMER0_DIV_BY_128,
            TIMER0_DIV_BY_256
}timer0_Prescaler_t;


typedef struct {
    #if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE
    void (* timer0_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 timer0_priority:1;
    uint8 timer0_reservid:3;
    #else
    uint8 timer0_reservid:4;
    #endif
timer0_Prescaler_t timer0_Prescaler_type;
    uint16 timer0_preload_value;
    uint8 timer0_select_sourse :1;
    uint8 timer0_select_edge :1;
    uint8 timer0_prescaler_statuse :1;
    uint8 timer0_select_mode_bits :1;
    
    
}timer0_t;
/*Section function declaration  */

Std_ReturnType timer0_int(const timer0_t *ptr);
Std_ReturnType timer0_deint(const timer0_t* ptr);
Std_ReturnType timer0_write(const timer0_t *ptr,uint16 data);
Std_ReturnType timer0_read(const timer0_t *ptr,uint16 *data);


#endif	/* TIMER0_H */

