#include "Internal_EEPROM.h"

Std_ReturnType Internal_EEPROM_Write_Byte(uint16 adress ,uint8 data){
    
    uint8 flage=0;
            
    Std_ReturnType return_result =E_NOT_OK; 
    
    if(0x400>=adress){
        
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        flage=RCONbits.IPEN;
        RCONbits.IPEN=0;
        #else
         flage=INTCONbits.GIE;
         INTCONbits.GIE=0;
        #endif
       
        /*adress */  
        EEADRH=(uint8)((adress>>8) & 0x03);
        
        EEADR=(uint8)(adress & 0xFF);
        /*data*/
        EEDATA=data;
        
        EECON1bits.EEPGD=Access_data_EEPROM_memory;
        EECON1bits.CFGS=Access_Flash_program_or_data_EEPROM_memory;
        EECON1bits.WREN=Allows_write_cycles_to_Flash_program_data_EEPROM;
        EECON2=0x55;
        EECON2=0xAA;
        EECON1bits.WR=Initiates_a_data_EEPROM_erase_write_cycle_or_a_program_memory_erase_cycle_or_write_cycle;
        while(EECON1bits.WR);
        EECON1bits.WREN=Inhibits_write_cycles_to_Flash_program_data_EEPROM;
       #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        RCONbits.IPEN=flage;
       
        #else
         INTCONbits.GIE=flage;
         
        #endif
        return_result=E_OK;
    }
    return return_result;
}

Std_ReturnType Internal_EEPROM_Read_Byte(uint16 adress ,uint8 *data){
    uint8 flage=0;
            
    Std_ReturnType return_result =E_NOT_OK; 
    
    if(0x400>=adress && NULL!=data){
        
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        flage=RCONbits.IPEN;
        RCONbits.IPEN=0;
        #else
         flage=INTCONbits.GIE;
         INTCONbits.GIE=0;
        #endif
       /*adress */  
        EEADRH=(uint8)((adress>>8) & 0x03);
        
        EEADR=(uint8)(adress & 0xFF);
        
        EECON1bits.EEPGD=Access_data_EEPROM_memory;
        EECON1bits.CFGS=Access_Flash_program_or_data_EEPROM_memory;
        EECON1bits.RD=Initiates_an_EEPROM_read;
        NOP();
        NOP();
        *data=EEDATA;
        EECON1bits.RD=Does_not_initiate_an_EEPROM_read;
        
       #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        RCONbits.IPEN=flage;
       
        #else
         INTCONbits.GIE=flage;
         
        #endif
    }
    
}
