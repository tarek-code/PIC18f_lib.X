/* 
 * File:   SPI.h
 * Author: Unlimited
 *
 * Created on August 24, 2023, 11:55 PM
 */

#ifndef SPI_H
#define	SPI_H

/*Section includes */
#include <pic18f4620.h>
#include "../mcal_std.h"
#include "../device_config.h"   
#include "../GPIO/GPIO.h"
#include "../Interrupt/Interrupt_cfg.h"
#include "../../MCAL_Layer/Interrupt/Interrupt_internal.h"

/*Section macros */
#define SPI_SSPBUF_FULL    (1)
#define SPI_SSPBUF_EMPTY    (0)
/*Section macros function  */
#define SPI_MASTER_SAMPLE_AT_MIDDILE_CFG()                  (SSPSTATbits.SMP=0 )
#define SPI_MASTER_SAMPLE_AT_END_CFG()                      (SSPSTATbits.SMP=1)
#define SPI_TRANSMIT_OCCURS_FROM_ACTIVE_TO_IDLE_CFG()         (SSPSTATbits.CKE=1)
#define SPI_TRANSMIT_OCCURS_FROM_IDLE_TO_ACTIVE_CFG()           (SSPSTATbits.CKE=0)
#define SPI_SSPBUF_STATUSE_CFG()                       (SSPSTATbits.BF)
/*Section Data type */

/*Section function declaration  */

#endif	/* SPI_H */

