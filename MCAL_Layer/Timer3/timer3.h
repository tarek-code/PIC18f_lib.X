/* 
 * File:   timer3.h
 * Author: Unlimited
 *
 * Created on July 17, 2023, 3:00 AM
 */

#ifndef TIMER3_H
#define	TIMER3_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */
#define TIMER3_PREORITY_HIGH (1)
#define TIMER3_PREORITY_LOW (0)

#define TIMER3_ON       (1)
#define TIMER3_OFF      (0)



#define TIMER3_TIMER        (0)
#define TIMER3_COUNTER      (1)    

#define TIMER3_COUNTER_SYN (0)
#define TIMER3_COUNTER_ASYN (1)  
/*Analog configration*/



/*Section macros function  */
#define TIMER3_ON_CFG()     (T3CONbits.TMR3ON=1)
#define TIMER3_OFF_CFG()    (T3CONbits.TMR3ON=0)



#define TIMER3_16_BIT_MODE_SEPERATED_CFG()   (T3CONbits.RD16=0)  
#define TIMER3_16_BIT_MODE__CFG()  (T3CONbits.RD16=1)

#define TIMER3_TIMER_CFG()        (T3CONbits.TMR3CS=0)
#define TIMER3_COUNTER_CFG()      (T3CONbits.TMR3CS=1)    


#define TIMER3_COUNTER_SYN_CFG() (T3CONbits.T3SYNC=0)
#define TIMER3_COUNTER_ASYN_CFG() (T3CONbits.T3SYNC=1)

#define TIMER3_SET_PRESCALER_CFG(x)       (T3CONbits.T3CKPS=x)

/*Section Data type */

typedef enum{
    TIMER3_PRESCALER_OFF =0,
            TIMER3_DIV_BY_2,
            TIMER3_DIV_BY_4,
            TIMER3_DIV_BY_8
}timer3_Prescaler_t;


typedef enum{
    TIMER3_CCP_OFF =0,
            TIMER3_CCP2_CCP1,          
            TIMER3_CCP_on
}timer3_ccp_mode_t;

typedef struct {
    #if TIMER3_ENABLE_FEATURE==ENABLE_FEATURE
    void (* timer3_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 timer3_priority:1;
    uint8 timer3_reservid:6;
    #else
   // uint8 timer2_reservid:7;
    #endif
 uint8 timer3_preload_value;
timer3_Prescaler_t timer3_Prescaler_value;
    timer3_ccp_mode_t ccp_mode;
    uint8 timer3_syn_mode:1;
    uint8 timer3_mode:1;
}timer3_t;
/*Section function declaration  */
Std_ReturnType timer3_int(const timer3_t *ptr);
Std_ReturnType timer3_deint(const timer3_t* ptr);
Std_ReturnType timer3_write(const timer3_t *ptr,uint16 data);
Std_ReturnType timer3_read(const timer3_t *ptr,uint16 *data);

#endif	/* TIMER3_H */

