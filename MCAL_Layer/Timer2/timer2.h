/* 
 * File:   timer2.h
 * Author: Unlimited
 *
 * Created on July 10, 2023, 2:59 AM
 */

#ifndef TIMER2_H
#define	TIMER2_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */
#define TIMER2_PREORITY_HIGH (1)
#define TIMER2_PREORITY_LOW (0)

#define TIMER2_ON       (1)
#define TIMER2_OFF      (0)
      
/*Analog configration*/



/*Section macros function  */

#define TIMER2_ON_CFG()     (T2CONbits.TMR2ON=1)
#define TIMER2_OFF_CFG()    (T2CONbits.TMR2ON=0)



#define TIMER2_SET_PRESCALER(x)       (T2CONbits.T2CKPS=x) 
#define TIMER2_SET_Postscale(x)       (T2CONbits.TOUTPS=x)

/*Section Data type */

typedef enum{
    TIMER2_PRE_DIV_BY_1 =0,
            TIMER2_PRE_DIV_BY_4,
            
            TIMER2_PRE_DIV_BY_16
           
}timer2_Prescaler_t;

typedef enum{
    TIMER2_DIV_BY_1 =0,
            TIMER2_DIV_BY_2,
            TIMER2_DIV_BY_3,
            TIMER2_DIV_BY_4,
            TIMER2_DIV_BY_5,
            TIMER2_DIV_BY_6,
            TIMER2_DIV_BY_7,
            TIMER2_DIV_BY_8,
            TIMER2_DIV_BY_9,
            TIMER2_DIV_BY_10,
            TIMER2_DIV_BY_11,
            TIMER2_DIV_BY_12,
            TIMER2_DIV_BY_13,
            TIMER2_DIV_BY_14,
            TIMER2_DIV_BY_15,
            TIMER2_DIV_BY_16
}timer2_Postscale_t;


typedef struct {
    #if TIMER2_ENABLE_FEATURE==ENABLE_FEATURE
    void (* timer2_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 timer2_priority:1;
    uint8 timer2_reservid:6;
    #else
   // uint8 timer2_reservid:7;
    #endif
 uint8 timer2_preload_value;
timer2_Postscale_t timer2_Postscale_value;
timer2_Prescaler_t timer2_Prescaler_value;
    
}timer2_t;
/*Section function declaration  */

Std_ReturnType timer2_int(const timer2_t *ptr);
Std_ReturnType timer2_deint(const timer2_t* ptr);
Std_ReturnType timer2_write(const timer2_t *ptr,uint8 data);
Std_ReturnType timer2_read(const timer2_t *ptr,uint8 *data);

#endif	/* TIMER2_H */

