/* 
 * File:   eusart.h
 * Author: Unlimited
 *
 * Created on August 10, 2023, 9:46 PM
 */

#ifndef EUSART_H
#define	EUSART_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"
#include "eusart_cfg.h"

/*Section macros */

                                    
#define EUSART_MASTER_MODE  (1)
#define EUSART_SLAVE_MODE   (0)
#define EUSART_16_BIT_BAUDRATE_MODE   (1)
#define EUSART_8_BIT_BAUDRATE_MODE   (0)

#define EUSART_ASYNCHRONOUS_TX_9_BIT_DATA_MODE   (1)
#define EUSART_ASYNCHRONOUS_TX_8_BIT_DATA_MODE   (0)
#define EUSART_ASYNCHRONOUS_TX_ENABLE  (1)
#define EUSART_ASYNCHRONOUS_TX_DISABLE   (0)
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE  (1)
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE   (0)

#define EUSART_ASYNCHRONOUS_RX_9_BIT_DATA_MODE   (1)
#define EUSART_ASYNCHRONOUS_RX_8_BIT_DATA_MODE   (0)
#define EUSART_ASYNCHRONOUS_RX_ENABLE  (1)
#define EUSART_ASYNCHRONOUS_RX_DISABLE   (0)
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE  (1)
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE   (0)

#define EUSART_FRAM_ERROR_DETECTED  (1)
#define EUSART_FRAM_ERROR_CLEARED  (0)
//#define EUSART_OVERRUN_ERROR_DETECTED  (1)
//#define EUSART_OVERRUN_ERROR_DETECTED  (0)





#define EUSART_SYNCHRONOUS_MODE (1)
#define EUSART_ASYNCHRONOUS_MODE (0)

#define EUSART_ASYNCHRONOUS_HIGH_SPEED   (1)
#define EUSART_ASYNCHRONOUS_LOW_SPEED    (0)

                                

/*Section macros function  */

#define EUSART_SERIAL_PORT_ENABLED()       (RCSTAbits.SPEN=1)
#define EUSART_SERIAL_PORTDISABLE()       (RCSTAbits.SPEN=0)

// ----------------------------------------for TX---------------------------------------------------------------
#define EUSART_TX_SYNCHRONOUS_MASTER_MODE_CFG()                         (TXSTAbits.CSRC=1)          //SYN mode only
#define EUSART_TX_SYNCHRONOUS_SLAVE_MODE_CFG()                          (TXSTAbits.CSRC=0)          //SYN mode only
#define EUSART_TX_9_BIT_MODE_CFG()                          (TXSTAbits.TX9=1)
#define EUSART_TX_8_BIT_MODE_CFG()                          (TXSTAbits.TX9=0)
#define EUSART_TX_TRANSMIT_ENABLE_CFG()                     (TXSTAbits.TXEN=1)
#define EUSART_TX_TRANSMIT_DISABLE_CFG()                    (TXSTAbits.TXEN=0)
#define EUSART_TX_SYNCHRONOUS_MODE_CFG()                    (TXSTAbits.SYNC=1)
#define EUSART_TX_ASYNCHRONOUS_MODE_CFG()                   (TXSTAbits.SYNC=0)
#define EUSART_TX_ASYNCHRONOUS_SEND_SYNC_BREAK_CFG()                     (TXSTAbits.SENDB=1)         //ASYN mode only
#define EUSART_TX_ASYNCHRONOUS_READ_STATUSE_SEND_SYNC_BREAK_CFG()        (TXSTAbits.SENDB)           //ASYN mode only
#define EUSART_TX_ASYNCHRONOUS_HIGH_SPEED_CFG()                          (TXSTAbits.BRGH=1)         
#define EUSART_TX_ASYNCHRONOUS_LOW_SPEED_CFG()                           (TXSTAbits.BRGH=0)         
#define EUSART_TX_READ_TSR_STATUSE_CFG()                         (TXSTAbits.TRMT)
#define EUSART_TX_READ_9th_BIT_R_W_CFG()                         (TXSTAbits.TX9D)

 // ---------------------------------------for RX---------------------------------------------------------------
#define EUSART_RX_9_BIT_MODE_CFG()                          (RCSTAbits.RX9=1)
#define EUSART_RX_8_BIT_MODE_CFG()                          (RCSTAbits.RX9=0)
#define EUSART_RX_SYNCHRONOUS_MASTER_SINGLE_RECEIVE_ENABLE()              (RCSTAbits.SREN=1) //master only
#define EUSART_RX_SYNCHRONOUS_MASTER_SINGLE_RECEIVE_DISABLE()              (RCSTAbits.SREN=0) //master only 
#define EUSART_RX_ASYNCHRONOUS_RECEIVER_ENABLE()             (RCSTAbits.CREN=1)
#define EUSART_RX_ASYNCHRONOUS_RECEIVER_DISABLE()             (RCSTAbits.CREN=0)
#define EUSART_RX_SYNCHRONOUS_CONTINUOUS_RECEIVE_ENABLE()     (RCSTAbits.CREN=1)
#define EUSART_RX_SYNCHRONOUS_CONTINUOUS_RECEIVE_DISABLE()     (RCSTAbits.CREN=0)
#define EUSART_RX_ASYNCHRONOUS_9BIT_MODE_ADDRESS_DETECT_ENABLE()         (RCSTAbits.ADDEN=1)
#define EUSART_RX_ASYNCHRONOUS_9BIT_MODE_ADDRESS_DETECT_DISABLE()         (RCSTAbits.ADDEN=0)
#define EUSART_RX_READING_FRAMING_ERROR_STATUSE()   (RCSTAbits.FERR)
#define EUSART_RX_READING_OVERRUN_ERROR_STATUSE()   (RCSTAbits.OERR)

 // ---------------------------------------for BAUD RATE---------------------------------------------------------------
#define EUSART_AUTO_BAUD_ACQUISITION_ROLLOVER_STATUS()  (BAUDCONbits.ABDOVF)
#define EUSART_AUTO_BAUD_ACQUISITION_ROLLOVER_CLEAR()  (BAUDCONbits.ABDOVF=0)
#define EUSART_RECEIVE_OPERATION_STATUSE()  (BAUDCONbits.RCIDL)
#define EUSART_ASYNCHRONOUS_RECEIVED_DATA_POLARITY_SELECT_ENABLE()  (BAUDCONbits.RXDTP=1)
#define EUSART_ASYNCHRONOUS_RECEIVED_DATA_POLARITY_SELECT_DISABLE()  (BAUDCONbits.RXDTP=0)
#define EUSART_ASYNCHRONOUS_IDLE_STATE_TX_LOW_LEVEL()    (BAUDCONbits.TXCKP=1)
#define EUSART_ASYNCHRONOUS_IDLE_STATE_TX_HIGH_LEVEL()    (BAUDCONbits.TXCKP=0)
#define EUSART_SYNCHRONOUS_IDLE_STATE_CLK_LOW_LEVEL()    (BAUDCONbits.TXCKP=1)
#define EUSART_SYNCHRONOUS_IDLE_STATE_CLK_HIGH_LEVEL()    (BAUDCONbits.TXCKP=0)
#define EUSART_BAUD_RATE_GENERATOR_16BIT()   (BAUDCONbits.BRG16=1)
#define EUSART_BAUD_RATE_GENERATOR_8BIT()   (BAUDCONbits.BRG16=0)
/*Section Data type */

typedef enum{
    EUASRT_8_BIT_ASYNCHRONOUS_LOW_SPEED,
             EUASRT_8_BIT_ASYNCHRONOUS_HIGH_SPEED,
             EUASRT_16_BIT_ASYNCHRONOUS_LOW_SPEED,
             EUASRT_16_BIT_ASYNCHRONOUS_HIGH_SPEED,
             EUASRT_8_BIT_SYNCHRONOUS,
             EUASRT_16_BIT_SYNCHRONOUS
}eusart_baudrate_formula_cfg_t;

typedef struct{
    uint8 eusrt_tx_reserved :5;
    uint8 euasrt_tx_enable:1;
    uint8 euasrt_interrupt_tx_enable:1;
    uint8 euasrt_tx_9_bit_enable:1;
}euasrt_tx_t;

typedef struct{
    uint8 eusrt_rx_reserved :5;
    uint8 euasrt_rx_enable:1;
    uint8 euasrt_interrupt_rx_enable:1;
    uint8 euasrt_rx_9_bit_enable:1;
}euasrt_rx_t;

typedef union {
    struct{
        uint8 reserved:6;
        uint8 euasrt_ferr:1;
        uint8 euasrt_oerr:1;
    };
    uint8 statuse;
}euasrt_statuse_err_t;


typedef struct{
    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
    uint8 euasrt_tx_priority;
    uint8 euasrt_rx_priority;
#endif
    void (*EUASRT_TX_INTERRUPT_PTR)(void);
    void (*EUASRT_RX_INTERRUPT_PTR)(void);
    void (*EUASRT_FRAMEERR_INTERRUPT_PTR)(void);
    void (*EUASRT_OVERERR_INTERRUPT_PTR)(void);
    uint32 baudrate;
    eusart_baudrate_formula_cfg_t eusart_baudrate_formula;
    euasrt_tx_t euasrt_tx;
    euasrt_rx_t euasrt_rx;
    euasrt_statuse_err_t euasrt_statuse_err;
    
}euasrt_t;
/*Section function declaration  */


Std_ReturnType eusart_ASYN_int(const euasrt_t *ptr);
Std_ReturnType eusart_RX_Restart(void);
uint8 eusart_frmeerror_Restart(void);
Std_ReturnType eusart_ASYN_deint(const euasrt_t *ptr);
Std_ReturnType eusart_ASYN_Read_block(uint8 *value);
Std_ReturnType eusart_ASYN_Write_block(uint8 value);
Std_ReturnType eusart_ASYN_WriteString_block(uint8 *value);
#if EUSART_ENABLE_FEATURE==ENABLE_FEATURE
Std_ReturnType eusart_ASYN_Write(uint8 value);
Std_ReturnType eusart_ASYN_WriteString(uint8 *value);
uint8 eusart_ASYN_Read();
#endif

#endif	/* EUSART_H */

