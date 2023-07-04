/* 
 * File:   ecu_int.h
 * Author: Unlimited
 *
 * Created on May 3, 2023, 12:07 AM
 */

#ifndef ECU_INT_H
#define	ECU_INT_H

/*Section includes */
#include "ecu_int.h"
#include "LED/LED.h"
#include "button/button.h"
#include "relay/relay.h"
#include "dc_motor/dc_motor.h"
#include "seven_segment/seven_segment.h"
#include "keypad/keypad.h"
#include "chr_lcd/chr_lcd.h"
#include "../MCAL_Layer/Interrupt/Interrupt_external.h"
#include "../MCAL_Layer/Internal_EEPROM/Internal_EEPROM.h"
#include "../MCAL_Layer/ADC/ADC.h"
/*Section macros */


/*Section macros function  */

/*Section Data type */


/*Section function declaration  */
void ecu_Int(void);
#endif	/* ECU_INT_H */

