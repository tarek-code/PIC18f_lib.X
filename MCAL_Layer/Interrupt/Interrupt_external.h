/* 
 * File:   Interrupt_external.h
 * Author: Unlimited
 *
 * Created on May 19, 2023, 7:19 PM
 */

#ifndef INTERRUPT_EXTERNAL_H
#define	INTERRUPT_EXTERNAL_H

/*Section includes */
#include "Interrupt_cfg.h" 
#include "../GPIO/GPIO.h"
/*Section macros */

#if INTERRUPT_EXTERNAL_FEATURE == ENABLE_FEATURE

#define ENABLE_INT0_INTERRUPT()                     (INTCONbits.INT0IE=1)
#define DISABLE_INT0_INTERRUPT()                    (INTCONbits.INT0IE=0)
#define CLEAR_INT0_FLAG_INTERRUPT()                 (INTCONbits.INT0IF=0)
#define ENABLE_INT0_RISIG_EDGE_INTERRUPT()          (INTCON2bits.INTEDG0=1)
#define ENABLE_INT0_FALLING_EDGE_INTERRUPT()        (INTCON2bits.INTEDG0=0)

#define ENABLE_INT1_INTERRUPT()                     (INTCON3bits.INT1IE=1)
#define DISABLE_INT1_INTERRUPT()                    (INTCON3bits.INT1IE=0)
#define CLEAR_INT1_FLAG_INTERRUPT()                 (INTCON3bits.INT1IF=0)
#define ENABLE_INT1_RISIG_EDGE_INTERRUPT()          (INTCON2bits.INTEDG1=1)
#define ENABLE_INT1_FALLING_EDGE_INTERRUPT()        (INTCON2bits.INTEDG1=0)

#define ENABLE_INT2_INTERRUPT()                     (INTCON3bits.INT2IE=1)
#define DISABLE_INT2_INTERRUPT()                    (INTCON3bits.INT2IE=0)
#define CLEAR_INT2_FLAG_INTERRUPT()                 (INTCON3bits.INT2IF=0)
#define ENABLE_INT2_RISIG_EDGE_INTERRUPT()          (INTCON2bits.INTEDG2=1)
#define ENABLE_INT2_FALLING_EDGE_INTERRUPT()        (INTCON2bits.INTEDG2=1)



#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

#define ENABLE_INT1_HIGH_PRIPRITY_INTERRUPT()       (INTCON3bits.INT1IP=1)
#define ENABLE_INT1_LOW_PRIORETY_INTERRUPT()        (INTCON3bits.INT1IP=0)

#define ENABLE_INT2_HIGH_PRIPRITY_INTERRUPT()       (INTCON3bits.INT2IP=1)
#define ENABLE_INT2_LOW_PRIORETY_INTERRUPT()        (INTCON3bits.INT2IP=0)

#endif

#endif

                            /*ON CHANGE */
#if INTERRUPT_ONCHANGERBx_FEATURE == ENABLE_FEATURE
#define ENABLE_ONCHANGERBx_INTERRUPT()                   (INTCONbits.RBIE=1)
#define DISABLE_ONCHANGERBx_INTERRUPT()                  (INTCONbits.RBIE=0)
#define CLEAR_ONCHANGERBx_FLAG_INTERRUPT()               (INTCONbits.RBIF=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define ENABLE_ONCHANGERBx_HIGH_PRIORETY_INTERRUPT()    (INTCON2bits.RBIP=1)
#define ENABLE_ONCHANGERBx_LOW_PRIORETY_INTERRUPT()    (INTCON2bits.RBIP=0)
#endif
#endif
/*Section macros function  */

/*Section Data type */
typedef enum{
INTERRUPT_INT0,
        INTERRUPT_INT1,
        INTERRUPT_INT2
}interrupt_intx_t;

typedef enum{
    INTERRUPT_FALLING_EDGE,
            INTERRUPT_RISING_EDGE
}interrupt_edge_t;



typedef struct{
    void (* interrupt_callback)(void);
    pin_cfg_t pin;
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    priority_t priority;
    #endif
    interrupt_edge_t edge;
    interrupt_intx_t intx;
}external_intx_interrupt_t;

typedef struct{
    void (* interrupt_callback_LOW)(void);
    void (* interrupt_callback_HIGH)(void);
    pin_cfg_t pin;
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    priority_t priority;
    #endif
}external_rbx_interrupt_t;

/*Section function declaration  */
Std_ReturnType interrupt_intx_int(const external_intx_interrupt_t *intx);
Std_ReturnType interrupt_intx_deint(const external_intx_interrupt_t *intx);
Std_ReturnType interrupt_rbx_int(const external_rbx_interrupt_t *rbx);
Std_ReturnType interrupt_rbx_deint(const external_rbx_interrupt_t *rbx);
#endif	/* INTERRUPT_EXTERNAL_H */

