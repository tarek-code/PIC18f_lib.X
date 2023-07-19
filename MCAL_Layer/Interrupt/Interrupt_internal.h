/* 
 * File:   Interrupt_internal.h
 * Author: Unlimited
 *
 * Created on May 19, 2023, 7:19 PM
 */

#ifndef INTERRUPT_INTERNAL_H
#define	INTERRUPT_INTERNAL_H

/*Section includes */
#include "Interrupt_cfg.h" 

/*Section macros */

// interrupt for ADC 

#if ADC_ENABLE_FEATURE==ENABLE_FEATURE

#define AD_Converter_Interrupt_CLEAR_Flag_bit() (PIR1bits.ADIF=0)
#define AD_Converter_Interrupt_READ_Flag_bit() (PIR1bits.ADIF)

#define ADC_INRERRUPT_ENABLE()  (PIE1bits.ADIE=1)
#define ADC_INRERRUPT_DISABLE()  (PIE1bits.ADIE=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define ADC_ENABLE_HIGH_PRIORITY()    (IPR1bits.ADIP=1)
#define ADC_ENABLE_LOW_PRIORITY()    (IPR1bits.ADIP=0)

#endif
#endif


// INTERNAL INTERRUPT FOR TIMER0
#if TIMER0_ENABLE_FEATURE==ENABLE_FEATURE

#define TIMER0_Interrupt_CLEAR_Flag_bit() (INTCONbits.TMR0IF=0)
#define TIMER0_Interrupt_READ_Flag_bit() (INTCONbits.TMR0IF)

#define TIMER0_INRERRUPT_ENABLE()  (INTCONbits.TMR0IE=1)
#define TIMER0_INRERRUPT_DISABLE()  (INTCONbits.TMR0IE=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define TIMER0_ENABLE_HIGH_PRIORITY()    (INTCON2bits.TMR0IP=1)
#define TIMER0_ENABLE_LOW_PRIORITY()    (INTCON2bits.TMR0IP=0)

#endif
#endif

// INTERNAL INTERRUPT FOR TIMER1
#if TIMER1_ENABLE_FEATURE==ENABLE_FEATURE

#define TIMER1_Interrupt_CLEAR_Flag_bit() (PIR1bits.TMR1IF=0)
#define TIMER1_Interrupt_READ_Flag_bit() (PIR1bits.TMR1IF)

#define TIMER1_INRERRUPT_ENABLE()  (PIE1bits.TMR1IE=1)
#define TIMER1_INRERRUPT_DISABLE()  (PIE1bits.TMR1IE=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define TIMER1_ENABLE_HIGH_PRIORITY()    (IPR1bits.TMR1IP=1)
#define TIMER1_ENABLE_LOW_PRIORITY()    (IPR1bits.TMR1IP=0)

#endif
#endif


// INTERNAL INTERRUPT FOR TIMER2
#if TIMER2_ENABLE_FEATURE==ENABLE_FEATURE

#define TIMER2_Interrupt_CLEAR_Flag_bit() (PIR1bits.TMR2IF=0)
#define TIMER2_Interrupt_READ_Flag_bit() (PIR1bits.TMR2IF)

#define TIMER2_INRERRUPT_ENABLE()  (PIE1bits.TMR2IE=1)
#define TIMER2_INRERRUPT_DISABLE()  (PIE1bits.TMR2IE=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define TIMER2_ENABLE_HIGH_PRIORITY()    (IPR1bits.TMR2IP=1)
#define TIMER2_ENABLE_LOW_PRIORITY()    (IPR1bits.TMR2IP=0)

#endif
#endif

// INTERNAL INTERRUPT FOR TIMER3
#if TIMER3_ENABLE_FEATURE==ENABLE_FEATURE

#define TIMER3_Interrupt_CLEAR_Flag_bit() (PIR2bits.TMR3IF=0)
#define TIMER3_Interrupt_READ_Flag_bit() (PIR2bits.TMR3IF)

#define TIMER3_INRERRUPT_ENABLE()  (PIE2bits.TMR3IE=1)
#define TIMER3_INRERRUPT_DISABLE()  (PIE2bits.TMR3IE=0)

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define TIMER2_ENABLE_HIGH_PRIORITY()    (IPR2bits.TMR3IP=1)
#define TIMER2_ENABLE_LOW_PRIORITY()    (IPR2bits.TMR3IP=0)

#endif
#endif
/*Section macros function  */

/*Section Data type */


/*Section function declaration  */

#endif	/* INTERRUPT_INTERNAL_H */

