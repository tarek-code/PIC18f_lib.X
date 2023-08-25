/* 
 * File:   I2C.h
 * Author: Unlimited
 *
 * Created on August 24, 2023, 3:47 AM
 */

#ifndef I2C_H
#define	I2C_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */

#define I2C_SLEW_RATE_ENABLE    (0)
#define I2C_SLEW_RATE_DISABLE    (1)
#define I2C_MASTER (1)
#define I2C_SLAVE (0)
#define I2C_MASTER_TRANSMIT_IS_IN_PROGRESS (1)
#define I2C_MASTER_TRANSMIT_IS_NOT_IN_PROGRESS (0)
#define I2C_SLAVE_IN_READ (1)
#define I2C_SLAVE_IN_WRITE (0)
#define I2C_SLAVE_RECEIVED_OR_TRANSMITTED_BYTE_WAS_DATA (1)
#define I2C_SLAVE_RECEIVED_OR_TRANSMITTED_BYTE_WAS_ADDRESS (0)
#define I2C_STOP_BIT_DETECTED           (1)
#define I2C_STOP_BIT_NOT_DETECTED    (0)
#define I2C_START_BIT_DETECTED          (1)
#define I2C_START_BIT_NOT_DETECTED    (0)
#define I2C_REAPET_START_BIT_DETECTED          (1)
#define I2C_REAPET_START_BIT_NOT_DETECTED    (0)
#define I2C_SLAVE_10BIT_NEED_TO_UPDATE  (1)  
#define I2C_SLAVE_10BIT_DONT_NEED_TO_UPDATE  (0)  
#define I2C_BUFFER_IS_FULL  (1)
#define I2C_BUFFER_IS_EMPTY  (0)
#define I2C_SSPBUF_COLLISION_OCCURED  (1)
#define I2C_SSPBUF_COLLISION_NOT_OCCURED  (0)
#define I2C_RECEIVE_OVERFLOW_OCCURED    (1)
#define I2C_RECEIVE_OVERFLOW_NOT_OCCURED    (0)
#define I2C_MASTER_NOT_RECEIVED_ACK    (1)
#define I2C_MASTER_RECEIVED_ACK    (0)
#define I2C_SMBus_ENABLE                                        (1)
#define I2C_SMBus_DISABLE                                       (0)
#define I2C_SLAVE_GENERAL_CALL_ENABLE   (1)
#define I2C_SLAVE_GENERAL_CALL_DISABLE   (0)
#define I2C_MASTER_SEND_ACK (0)
#define I2C_MASTER_SEND_NACK (1)
/*Section macros function  */
#define I2C_SMBus_ENABLE_CFG()                                        (SSPSTATbits.CKE=1)
#define I2C_SMBus_DISABLE_CFG()                                       (SSPSTATbits.CKE=0)
#define I2C_SLAVE_RECEIVED_OR_TRANSMITTED_BYTE_STATUSE_CFG()   (SSPSTATbits.DA)
#define I2C_STANDARD_SPEED_MODE_100khz_CFG()                    (SSPSTATbits.SMP=1)
#define I2C_HIGH_SPEED_MODE_400khz_CFG()                        (SSPSTATbits.SMP=0)
#define I2C_STOP_BIT_STATUSE_CFG()                              (SSPSTATbits.P)
#define I2C_START_BIT_STATUSE_CFG()                             (SSPSTATbits.S)
#define I2C_ENABLE_CFG()                                        (SSPCON1bits.SSPEN=1)
#define I2C_DISABLE_CFG()                                       (SSPCON1bits.SSPEN=0)
#define I2C_MODE_SELECT_CFG(x)                                  (SSPCON1bits.SSPM=x)
#define I2C_MASTER_TRANSMIT_STATUSE_CFG()                       (SSPSTATbits.RW)
#define I2C_SLAVE_READ_WRITE_STATUSE_CFG()                       (SSPSTATbits.RW)
#define I2C_SLAVE_10BIT_CHANGE_ADDRES_STATUSE_CFG()               (SSPSTATbits.UA)
#define I2C_BUFFER_STATUSE_CFG()               (SSPSTATbits.BF)
#define I2C_SSPBUF_COLLISION_STATUSE_CFG()               (SSPCON1bits.WCOL)
#define I2C_SSPBUF_COLLISION_CLEAR_BIT_CFG()               (SSPCON1bits.WCOL=0)
#define I2C_RECEIVE_OVERFLOW_STATUSE_CFG()               (SSPCON1bits.SSPOV)
#define I2C_RECEIVE_OVERFLOW_CLEAR_BIT_CFG()               (SSPCON1bits.SSPOV=0)
#define I2C_SLAVE_CLOCK_RELEASES_CFG()               (SSPCON1bits.CKP=1)
#define I2C_SLAVE_CLOCK_STRETCH_CFG()               (SSPCON1bits.CKP=0)
#define I2C_SLAVE_GENERAL_CALL_ENABLE_CFG()    (SSPCON2bits.GCEN=1)
#define I2C_SLAVE_GENERAL_CALL_DISABLE_CFG()    (SSPCON2bits.GCEN=0)
#define I2C_MASTER_RECEIVED_ACKNOWLEDGE_STATUS_CFG() (SSPCON2bits.ACKSTAT) 
#define I2C_MASTER_SEND_ACK_CFG() (SSPCON2bits.ACKDT=0)
#define I2C_MASTER_SEND_NACK_CFG() (SSPCON2bits.ACKDT=1)
#define I2C_MASTER_INITIATES_ACKNOWLEDGE_SEQUENCE_CFG() (SSPCON2bits.ACKEN=1)
#define I2C_MASTER_RECEIVE_ENABLE_CFG() (SSPCON2bits.RCEN=1)
#define I2C_MASTER_RECEIVE_DISABLE_CFG() (SSPCON2bits.RCEN=0)
#define I2C_MASTER_STOP_ENABLE_CFG() (SSPCON2bits.PEN=1)
#define I2C_MASTER_STOP_READ_STATUSE_CFG() (SSPCON2bits.PEN)
#define I2C_MASTER_STOP_DISABLE_CFG() (SSPCON2bits.PEN=0)
#define I2C_MASTER_REAPTED_START_ENABLE_CFG() (SSPCON2bits.RSEN=1)
#define I2C_MASTER_REAPTED_START_READ_STATUSE_CFG() (SSPCON2bits.RSEN)
#define I2C_MASTER_REAPTED_START_DISABLE_CFG() (SSPCON2bits.RSEN=0)
#define I2C_MASTER_START_ENABLE_CFG() (SSPCON2bits.SEN=1)
#define I2C_MASTER_START_READ_STATUSE_CFG() (SSPCON2bits.SEN)
#define I2C_MASTER_START_DISABLE_CFG() (SSPCON2bits.SEN=0)
#define I2C_SLAVE_CLOCK_STRETCH_ENABLE_CFG() (SSPCON2bits.SEN=1)
#define I2C_SLAVE_CLOCK_STRETCH_DISABLE_CFG() (SSPCON2bits.SEN=0)





/*Section Data type */


typedef enum{
    I2C_SLAVE_MODE_7_BIT_ADDRESS=6,
            I2C_SLAVE_MODE_10_BIT_ADDRESS,
             I2C_MASTER_MODE,                                    
            I2C_FIRMWARE_CONTROLLED_MASTER_MODE=11,
            I2C_SLAVE_MODE_7_BIT_ADDRESS_INTERRUPTS_ENABLED=14,
    I2C_SLAVE_MODE_10_BIT_ADDRESS_INTERRUPTS_ENABLED=15
                       
}i2c_submode_t;
typedef struct{
    i2c_submode_t i2c_sub_mode;
    uint8 i2c_mode:1;
    uint8 i2c_slave_address;
    uint8 i2c_speed_mode:1;
    uint8 i2c_smbus_mode:1;
    uint8 i2c_general_call:1;   
    uint8 i2c_reserved:4;
}i2c_cfg_t;
typedef struct{
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    priority_t i2c_priority;
    priority_t i2c_BC_priority;
    #endif
    uint32 i2c_clock;
    void(*write_collision_ptr)(void);
    void(*recive_overflow_ptr)(void);
    void(*default_ptr)(void);
    i2c_cfg_t i2c_cfg;
}i2c_t;

/*Section function declaration  */
Std_ReturnType i2c_int(const i2c_t *ptr);
Std_ReturnType i2c_deint(const i2c_t *ptr);
Std_ReturnType i2c_master_send_start(void);
Std_ReturnType i2c_master_send_repet_start(void);
Std_ReturnType i2c_master_send_stop(void);
Std_ReturnType i2c_master_write_block(const i2c_t *ptr,uint8 data,uint8 *_ack);
Std_ReturnType i2c_master_write(const i2c_t *ptr,uint8 data,uint8 *_ack);
Std_ReturnType i2c_master_read_block(const i2c_t *ptr,uint8 ack ,uint8 *data);
#endif	/* I2C_H */

