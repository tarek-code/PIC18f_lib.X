/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */


#include "Application.h"
uint32 tx_counter=0;
uint32 rx_counter=0;
uint8 overrunerror=0;
uint8 frameerror=0;
void eusart_overrunerror_calling(){
    overrunerror++;
    eusart_RX_Restart();
}
void eusart_frameerror_calling(){
    frameerror++;
    eusart_frmeerror_Restart();
}

void eusart_tx_calling(){
    tx_counter++;
}
uint8 data=0;
void eusart_rx_calling(){
    rx_counter++;
    data=eusart_ASYN_Read();
    eusart_ASYN_Write(data);
            eusart_ASYN_Write('\r');
            switch(data){
                case 'a':
                    eusart_ASYN_WriteString("Tarek Adel");
                    break;
                case 'k':
                     eusart_ASYN_WriteString("Khaled Adel");
                     break;
            }
             eusart_ASYN_Write('\r');
}

euasrt_t eusart={
  .baudrate=9600,
  .eusart_baudrate_formula=EUASRT_8_BIT_ASYNCHRONOUS_LOW_SPEED,
.euasrt_tx.euasrt_tx_enable=EUSART_ASYNCHRONOUS_TX_ENABLE,
.euasrt_tx.euasrt_interrupt_tx_enable=EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE,
.euasrt_tx.euasrt_tx_9_bit_enable=EUSART_ASYNCHRONOUS_TX_8_BIT_DATA_MODE,  
  .euasrt_rx.euasrt_rx_enable=EUSART_ASYNCHRONOUS_RX_ENABLE,
.euasrt_rx.euasrt_interrupt_rx_enable=EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE,
.euasrt_rx.euasrt_rx_9_bit_enable=EUSART_ASYNCHRONOUS_RX_8_BIT_DATA_MODE,
  .EUASRT_FRAMEERR_INTERRUPT_PTR=eusart_frameerror_calling,
  .EUASRT_OVERERR_INTERRUPT_PTR=eusart_overrunerror_calling,
  .EUASRT_RX_INTERRUPT_PTR=eusart_rx_calling,
  .EUASRT_TX_INTERRUPT_PTR=eusart_tx_calling,
  
};
 


 uint8 value=0;
 
int main() {
eusart_ASYN_int(&eusart);



    while (1) {
     
 

     
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}

