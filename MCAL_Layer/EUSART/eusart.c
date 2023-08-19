#include "eusart.h"


// helper functions declerations 
static void buadrate_calculation(const euasrt_t *ptr);
static void eusart_tx_int(const euasrt_t *ptr);
static void eusart_rx_int(const euasrt_t *ptr);

#if EUSART_ENABLE_FEATURE==ENABLE_FEATURE
 static void (* eusart_framerr_callback_ptr)(void)=NULL;
  static void (* eusart_overerr_callback_ptr)(void)=NULL;

 static void (* eusart_tx_callback_ptr)(void)=NULL;
   static void (* eusart_rx_callback_ptr)(void)=NULL;

  

   static void (* eusart_slave_callback_ptr)(void)=NULL;
   static void (* eusart_master_callback_ptr)(void)=NULL;
  
#endif

Std_ReturnType eusart_ASYN_int(const euasrt_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
         // eusart disable
        EUSART_SERIAL_PORTDISABLE();
        TRISCbits.RC6=1;
        TRISCbits.RC7=1;
        // calculate baudrate
        buadrate_calculation(ptr);
        eusart_tx_int(ptr);
        eusart_rx_int(ptr);
       
        
        
       
        
        //if interrupt enable
        #if EUSART_ENABLE_FEATURE==ENABLE_FEATURE
       
              
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();       
        #else       
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif

      
        #endif
        
        // eusart enable
        EUSART_SERIAL_PORT_ENABLED();
        
        returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType eusart_deint(const euasrt_t *ptr){
     Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        
        EUSART_SERIAL_PORTDISABLE();
        
        returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType eusart_ASYN_Read_block(uint8 *valu){
     Std_ReturnType returt_statuse=E_NOT_OK;
     while(!EUSART_RX_Interrupt_READ_Flag_bit());
         *valu=RCREG;
     
    return returt_statuse;
}

Std_ReturnType eusart_ASYN_Write_block(uint8 value){
     Std_ReturnType returt_statuse=E_NOT_OK;
    
        
        while(!TXSTAbits.TRMT);
            TXREG=value;
        
        
        returt_statuse=E_OK;
    
    return returt_statuse;
}


Std_ReturnType eusart_ASYN_WriteString_block(uint8 *value){
    uint8 counter=0;
    while(value[counter]!='\0'){
        eusart_ASYN_Write_block(value[counter]);
        counter++;
    }
}


#if EUSART_ENABLE_FEATURE==ENABLE_FEATURE

uint8 eusart_ASYN_Read(){
    return RCREG;
}
Std_ReturnType eusart_ASYN_Write(uint8 value){
     Std_ReturnType returt_statuse=E_NOT_OK;
    
        
        while(!TXSTAbits.TRMT);
            TXREG=value;
         EUSART_TX_INRERRUPT_ENABLE();
        
        returt_statuse=E_OK;
    
    return returt_statuse;
}
Std_ReturnType eusart_ASYN_WriteString(uint8 *value){
    uint8 counter=0;
    while(value[counter]!='\0'){
        eusart_ASYN_Write(value[counter]);
        counter++;
    }
}
#endif
Std_ReturnType eusart_RX_Restart(){
      Std_ReturnType returt_statuse=E_OK;
      EUSART_RX_ASYNCHRONOUS_RECEIVER_DISABLE();
      EUSART_RX_ASYNCHRONOUS_RECEIVER_ENABLE() ;
      return  returt_statuse;
}
uint8 eusart_frmeerror_Restart(void){
    return RCREG;
}

// helper functions 
static void eusart_rx_int(const euasrt_t *ptr){
    if(NULL!=ptr) {
        if(EUSART_ASYNCHRONOUS_RX_ENABLE==ptr->euasrt_rx.euasrt_rx_enable){
            EUSART_RX_ASYNCHRONOUS_RECEIVER_ENABLE();
            if(EUSART_ASYNCHRONOUS_RX_9_BIT_DATA_MODE ==ptr->euasrt_rx.euasrt_rx_9_bit_enable){
                EUSART_RX_9_BIT_MODE_CFG();
                
            }
            else{
                EUSART_RX_8_BIT_MODE_CFG();
            }
            if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE==ptr->euasrt_rx.euasrt_interrupt_rx_enable){
                EUSART_RX_INRERRUPT_DISABLE();
                eusart_rx_callback_ptr=ptr->EUASRT_RX_INTERRUPT_PTR;
                 eusart_framerr_callback_ptr=ptr->EUASRT_FRAMEERR_INTERRUPT_PTR;
                 eusart_overerr_callback_ptr=ptr->EUASRT_OVERERR_INTERRUPT_PTR;
                #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
                if(PRIORITY_HIGH==ptr->euasrt_rx_priority){
                     EUSART_RX_ENABLE_HIGH_PRIORITY();
                     }
                         else if(PRIORITY_LOW==ptr->euasrt_rx_priority){
                         EUSART_RX_ENABLE_LOW_PRIORITY();
                         }
                 #endif
                        EUSART_RX_INRERRUPT_ENABLE();
               
            }
            else{
                EUSART_RX_INRERRUPT_DISABLE();
            }
        }
        else{
            EUSART_RX_ASYNCHRONOUS_RECEIVER_DISABLE(); 
        }
        
         
    }
}

static void eusart_tx_int(const euasrt_t *ptr){
    if(NULL!=ptr) {
        if(EUSART_ASYNCHRONOUS_TX_ENABLE ==ptr->euasrt_tx.euasrt_tx_enable){
            EUSART_TX_TRANSMIT_ENABLE_CFG();
            if(EUSART_ASYNCHRONOUS_TX_9_BIT_DATA_MODE ==ptr->euasrt_tx.euasrt_tx_9_bit_enable){
                EUSART_TX_9_BIT_MODE_CFG();
                
            }
            else{
                EUSART_TX_8_BIT_MODE_CFG();
            }
            if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE==ptr->euasrt_tx.euasrt_interrupt_tx_enable){
                EUSART_TX_INRERRUPT_DISABLE();
                eusart_tx_callback_ptr=ptr->EUASRT_TX_INTERRUPT_PTR;
                #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
                if(PRIORITY_HIGH==ptr->euasrt_tx_priority){
                     EUSART_TX_ENABLE_HIGH_PRIORITY();
                     }
                         else if(PRIORITY_LOW==ptr->euasrt_tx_priority){
                         EUSART_TX_ENABLE_LOW_PRIORITY();
                         }
                 #endif
                        EUSART_TX_INRERRUPT_ENABLE();
               
            }
            else{
                EUSART_TX_INRERRUPT_DISABLE();
            }
        }
        else{
            EUSART_TX_TRANSMIT_DISABLE_CFG();
        }
    }
}
static void buadrate_calculation(const euasrt_t *ptr){
    
    if(NULL!=ptr) {
        
        f32 baudrate_local=0.0;
        switch(ptr->eusart_baudrate_formula){
            
            case EUASRT_8_BIT_ASYNCHRONOUS_LOW_SPEED :
                
                EUSART_TX_ASYNCHRONOUS_LOW_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_8BIT();
                EUSART_TX_ASYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/64)-1;
                
                break;
                
            case EUASRT_8_BIT_ASYNCHRONOUS_HIGH_SPEED :
                
                EUSART_TX_ASYNCHRONOUS_HIGH_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_8BIT();
                EUSART_TX_ASYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/16)-1;
                
                break;
                
            case EUASRT_16_BIT_ASYNCHRONOUS_LOW_SPEED :
                
                EUSART_TX_ASYNCHRONOUS_LOW_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_16BIT();
                EUSART_TX_ASYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/16.0)-1;
                
                break;
                
            case EUASRT_16_BIT_ASYNCHRONOUS_HIGH_SPEED:
                
                 EUSART_TX_ASYNCHRONOUS_HIGH_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_16BIT();
                EUSART_TX_ASYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/4.0)-1;
                
                break;
            case EUASRT_8_BIT_SYNCHRONOUS:
                 EUSART_TX_ASYNCHRONOUS_HIGH_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_8BIT();
                EUSART_TX_SYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/4.0)-1;
                break;
            case EUASRT_16_BIT_SYNCHRONOUS:
                
                 EUSART_TX_ASYNCHRONOUS_HIGH_SPEED_CFG();
                EUSART_BAUD_RATE_GENERATOR_16BIT();
                EUSART_TX_SYNCHRONOUS_MODE_CFG();
                baudrate_local=((_XTAL_FREQ/(f32)ptr->baudrate)/4.0)-1;
                
                break;
            default :
                // do nothing 
                break;
                
        }
        SPBRG=(uint8)((uint32)(baudrate_local));
        SPBRGH=(uint8)(((uint32)(baudrate_local))>>8);
        
        
    }
    
    
}


void EUSART_TX_ISR(void){
    
    EUSART_TX_INRERRUPT_DISABLE();
    if(eusart_tx_callback_ptr){
        eusart_tx_callback_ptr();
    }
}
void EUSART_RX_ISR(void){
    
    
    if(eusart_rx_callback_ptr){
        eusart_rx_callback_ptr();
    }
    if(eusart_framerr_callback_ptr){
        eusart_framerr_callback_ptr();
    }
    if(eusart_overerr_callback_ptr){
        eusart_overerr_callback_ptr();
    }
    
}


  void EUSART_SLAVE_ISR(void){
    EUSART_SLAVE_Interrupt_CLEAR_Flag_bit();
    
    if(eusart_slave_callback_ptr){
        eusart_slave_callback_ptr();
    }
}
void EUSART_MASTER_ISR(void){
    EUSART_MASTER_Interrupt_CLEAR_Flag_bit();
    
    if(eusart_master_callback_ptr){
        eusart_master_callback_ptr();
    }
}
 