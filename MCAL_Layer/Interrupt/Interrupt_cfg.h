/* 
 * File:   Interrupt_cfg.h
 * Author: Unlimited
 *
 * Created on May 19, 2023, 7:19 PM
 */

#ifndef INTERRUPT_CFG_H
#define	INTERRUPT_CFG_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "interrupt_gen_cfg.h"
/*Section macros */
#define INTERRUPT_ENABLE (1)
#define INTERRUPT_DISABLE (0)
#define INTERRUPT_OCCURE (1)
#define INTERRUPT_NOT_OCCURE (0)
#define INTERRUPT_PRIORITY_ENABLE (1)
#define INTERRUPT_PRIORITY_DISABLE (0)
/*Section macros function  */
#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

#define ENABLE_PRIORITY_INTERRUPT() (RCONbits.IPEN=1)
#define DISABLE_PRIORITY_INTERRUPT() (RCONbits.IPEN=0)

#define ENABLE_HIGH_PRIORITY() (INTCONbits.GIEH=1)
#define DISABLE_HIGH_PRIORITY() (INTCONbits.GIEH=0)

#define ENABLE_LOW_PRIORITY() (INTCONbits.GIEL=1)
#define DISABLE_LOW_PRIORITY() (INTCONbits.GIEL=0)
#else
#define ENABLE_GLOBAL_INTERRUPT() (INTCONbits.GIE=1)
#define DISABLE_GLOBAL_INTERRUPT() (INTCONbits.GIE=0)

#define ENABLE_PREFRAL_INTERRUPT() (INTCONbits.PEIE=1)
#define DISABLE_PREFRAL_INTERRUPT() (INTCONbits.PEIE=0)
#endif
/*Section Data type */
typedef enum{
    PRORITY_LOW =0,
    PRIORITY_HIGH     
}priority_t;

/*Section function declaration  */

#endif	/* INTERRUPT_CFG_H */

