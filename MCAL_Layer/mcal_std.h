/* 
 * File:   mcal_std.h
 * Author: Unlimited
 *
 * Created on April 22, 2023, 11:00 PM
 */

#ifndef MCAL_STD_H
#define	MCAL_STD_H



/*Section includes */
#include "std_lib.h"
#include "Compiler.h"

/*Section macros */

/*Section Data type */
typedef uint8 Std_ReturnType ;

/*Section macros function  */
#define ZERO_INT         (0x00)
#define STD_HIGH        (0x01u) 
#define STD_LOW         (0x00u)

#define CONFIG_ENABLE   (0x01)
#define CONFIG_DISABLE  (0x00)

#define STD_ACTIVE      (0x01u)
#define STD_IDLE        (0x00u)

#define STD_ON          (0x01u)
#define STD_OFF         (0x00u)

#define E_OK            (0x00u)
#define E_NOT_OK        (0x01u)
#define _XTAL_FREQ 8000000UL // or replace with the actual frequency of your oscillator
/*Section function declaration  */
#endif	/* MCAL_STD_H */

