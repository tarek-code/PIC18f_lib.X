/* 
 * File:   timer1.h
 * Author: Unlimited
 *
 * Created on July 9, 2023, 1:28 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */
#define TIMER1_PREORITY_HIGH (1)
#define TIMER1_PREORITY_LOW (0)

#define TIMER1_ON       (1)
#define TIMER1_OFF      (0)

#define TIMER1_16_BIT_MODE_SEPERATED   (0)  
#define TIMER1_16_BIT_MODE              (1)

#define TIMER1_TIMER        (0)
#define TIMER1_COUNTER      (1)    

#define TIMER1_COUNTER_SYN (0)
#define TIMER1_COUNTER_ASYN (1)

#define TIMER1_OSCILLATOR_ON  (1)
#define TIMER1_OSCILLATOR_OFF  (0)

#define TIMER1_COUNTER_SYN (0)
#define TIMER1_COUNTER_ASYN (1)

/*Analog configration*/



/*Section macros function  */

#define TIMER1_ON_CFG()     (T1CONbits.TMR1ON=1)
#define TIMER1_OFF_CFG()    (T1CONbits.TMR1ON=0)

#define TIMER1_READ_STATUSE_SOURCE_CLOCK_FROM_TIMER1_CFG() (T1CONbits.T1RUN)

#define TIMER1_16_BIT_MODE_SEPERATED_CFG()   (T1CONbits.RD16=0)  
#define TIMER1_16_BIT_MODE__CFG()  (T1CONbits.RD16=1)

#define TIMER1_TIMER_CFG()        (T1CONbits.TMR1CS=0)
#define TIMER1_COUNTER_CFG()      (T1CONbits.TMR1CS=1)    


#define TIMER1_OSCILLATOR_ON_CFG()  (T1CONbits.T1OSCEN=1)
#define TIMER1_OSCILLATOR_OFF_CFG()  (T1CONbits.T1OSCEN=0)

#define TIMER1_COUNTER_SYN_CFG() (T1CONbits.T1SYNC=0)
#define TIMER1_COUNTER_ASYN_CFG() (T1CONbits.T1SYNC=1)

#define TIMER1_SET_PRESCALER_CFG(x)       (T1CONbits.T1CKPS=x)


/*Section Data type */
typedef enum{
    TIMER1_PRESCALER_OFF =0,
            TIMER1_DIV_BY_2,
            TIMER1_DIV_BY_4,
            TIMER1_DIV_BY_8
}timer1_Prescaler_t;


typedef struct {
    #if TIMER1_ENABLE_FEATURE==ENABLE_FEATURE
    void (* timer1_callback)(void);
    #endif
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 timer1_priority:1;
    uint8 timer1_reservid:3;
    #else
    uint8 timer1_reservid:4;
    #endif
    timer1_Prescaler_t timer1_Prescaler_type;
    uint16 timer1_preload_value;
    uint8 timer1_select_sourse :1;
    
    uint8 timer1_osc_statuse:1;
    uint8 timer1_syn_mode:1;
    uint8 timer1_select_mode_16_bits :1;
    
    
}timer1_t;
/*Section function declaration  */

Std_ReturnType timer1_int(const timer1_t *ptr);
Std_ReturnType timer1_deint(const timer1_t* ptr);
Std_ReturnType timer1_write(const timer1_t *ptr,uint16 data);
Std_ReturnType timer1_read(const timer1_t *ptr,uint16 *data);
Std_ReturnType timer1_read_System_Clock_Status(const timer1_t *ptr,uint8 *statuse);

#endif	/* TIMER1_H */

