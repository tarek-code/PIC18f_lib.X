/* 
 * File:   Internal_EEPROM.h
 * Author: Unlimited
 *
 * Created on May 22, 2023, 5:17 PM
 */

#ifndef INTERNAL_EEPROM_H
#define	INTERNAL_EEPROM_H

/*Section includes */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include <pic18f4620.h>
#include "../Interrupt/Interrupt_cfg.h"

/*Section macros */

/*EEPGD*/
#define Access_Flash_program_memory (1u)
#define Access_data_EEPROM_memory   (0u)
/*CFGS*/
#define Access_Configuration_registers (1u)
#define Access_Flash_program_or_data_EEPROM_memory (0u)
/*WREN*/
#define Allows_write_cycles_to_Flash_program_data_EEPROM    (1u)
#define Inhibits_write_cycles_to_Flash_program_data_EEPROM  (0u)
/*WR*/
#define Initiates_a_data_EEPROM_erase_write_cycle_or_a_program_memory_erase_cycle_or_write_cycle    (1u)
#define Write_cycle_to_the_EEPROM_is_complete   (0u)
/*RD*/
#define Initiates_an_EEPROM_read (1u)
#define Does_not_initiate_an_EEPROM_read    (0u)

/*Section macros function  */

/*Section Data type */


/*Section function declaration  */

Std_ReturnType Internal_EEPROM_Write_Byte(uint16 adress ,uint8 data);
Std_ReturnType Internal_EEPROM_Read_Byte(uint16 adress ,uint8 *data);

#endif	/* INTERNAL_EEPROM_H */

