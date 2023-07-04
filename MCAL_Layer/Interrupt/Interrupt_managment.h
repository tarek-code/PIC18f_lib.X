/* 
 * File:   Interrupt_managment.h
 * Author: Unlimited
 *
 * Created on May 19, 2023, 7:19 PM
 */

#ifndef INTERRUPT_MANAGMENT_H
#define	INTERRUPT_MANAGMENT_H

/*Section includes */
#include "Interrupt_cfg.h" 

/*Section macros */


/*Section macros function  */

/*Section Data type */


/*Section function declaration  */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 flage);
void RB5_ISR(uint8 flage);
void RB6_ISR(uint8 flage);
void RB7_ISR(uint8 flage);

/*ADC*/
void ADC_ISR(void);
#endif	/* INTERRUPT_MANAGMENT_H */

