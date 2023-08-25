#include "I2C.h"

#if MSSP_ENABLE_FEATURE==ENABLE_FEATURE
   static void (* i2c_callback_ptr)(void)=NULL;
   static void (* recive_overflow_callback_ptr)(void)=NULL;
   static void (* write_collision_callback_ptr)(void)=NULL;
   
    #endif

Std_ReturnType i2c_int(const i2c_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        // diable module        
        I2C_DISABLE_CFG();
        
        TRISCbits.RC4=1;    // Serial data (SDA)
        TRISCbits.RC3=1;    // Serial clock (SCL) 
        
        // master mode
        if(I2C_MASTER==ptr->i2c_cfg.i2c_mode){
            switch(ptr->i2c_cfg.i2c_sub_mode){
                case I2C_MASTER_MODE:
                    I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                    SSPADD=(uint8)((_XTAL_FREQ/(4.0*ptr->i2c_clock))-1);
                    break;
                case I2C_FIRMWARE_CONTROLLED_MASTER_MODE:
                    I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                    break;
                default:
                    // do nothing
                    break;
            }
        }
        
        // slave mode
        else if(I2C_SLAVE==ptr->i2c_cfg.i2c_mode){
            
            // General call 
            if(I2C_SLAVE_GENERAL_CALL_ENABLE == ptr->i2c_cfg.i2c_general_call){
                I2C_SLAVE_GENERAL_CALL_ENABLE_CFG();
            }
            else if(I2C_SLAVE_GENERAL_CALL_DISABLE == ptr->i2c_cfg.i2c_general_call){
                I2C_SLAVE_GENERAL_CALL_DISABLE_CFG();
            }
            else{
                // do nothing 
            }
            //switching on slave mode
            switch(ptr->i2c_cfg.i2c_sub_mode){
                case I2C_SLAVE_MODE_7_BIT_ADDRESS:
                        I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                        break;
                caseI2C_SLAVE_MODE_10_BIT_ADDRESS:
                    I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                    break;
                case I2C_SLAVE_MODE_7_BIT_ADDRESS_INTERRUPTS_ENABLED:
                        I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                        break;
                I2C_SLAVE_MODE_10_BIT_ADDRESS_INTERRUPTS_ENABLED:
                    I2C_MODE_SELECT_CFG(ptr->i2c_cfg.i2c_sub_mode);
                    break;
                default:
                    // do nothing
                    break;
            }
            //clear write collision
            I2C_SSPBUF_COLLISION_CLEAR_BIT_CFG();
            // clear overflow
            I2C_RECEIVE_OVERFLOW_CLEAR_BIT_CFG();
            // slave release clock
            I2C_SLAVE_CLOCK_RELEASES_CFG();
            // assign address for slave
            SSPADD=ptr->i2c_cfg.i2c_slave_address;
        }
        else{
            //do nothing
        }
        
        // slew rate enable or disable
        if(I2C_SLEW_RATE_ENABLE == ptr->i2c_cfg.i2c_speed_mode){
            I2C_HIGH_SPEED_MODE_400khz_CFG();
        }
        else if(I2C_SLEW_RATE_DISABLE == ptr->i2c_cfg.i2c_speed_mode){
            I2C_STANDARD_SPEED_MODE_100khz_CFG();
        }
        else{
            // do nothing 
        }
        
        // SMBus enable or disable
        if(I2C_SMBus_ENABLE == ptr->i2c_cfg.i2c_speed_mode){
            I2C_SMBus_ENABLE_CFG();
        }
        else if(I2C_SMBus_DISABLE == ptr->i2c_cfg.i2c_speed_mode){
            I2C_SMBus_DISABLE_CFG();
        }
        else{
            // do nothing 
        }
        
        
        
        
        //if interrupt enable
        #if MSSP_ENABLE_FEATURE==ENABLE_FEATURE
        MSSP_INRERRUPT_DISABLE();
        MSSP_Interrupt_CLEAR_Flag_bit();
        i2c_callback_ptr=ptr->default_ptr;
        recive_overflow_callback_ptr=ptr->recive_overflow_ptr;
        write_collision_callback_ptr=ptr->write_collision_ptr;
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        ENABLE_PRIORITY_INTERRUPT();
        ENABLE_HIGH_PRIORITY();
        ENABLE_LOW_PRIORITY();
        if(PRIORITY_HIGH==ptr->i2c_priority){
        MSSP_ENABLE_HIGH_PRIORITY();
        }
        else{
        MSSP_ENABLE_LOW_PRIORITY();
        }
         if(PRIORITY_HIGH==ptr->i2c_BC_priority){
        MSSP_BC_ENABLE_HIGH_PRIORITY();
        }
        else{
        MSSP_BC_ENABLE_LOW_PRIORITY();
        }
        #else
        
        ENABLE_GLOBAL_INTERRUPT();
        ENABLE_PREFRAL_INTERRUPT();
        #endif
        MSSP_INRERRUPT_ENABLE();
        MSSP_BC_INRERRUPT_ENABLE();
        #endif
        
        I2C_ENABLE_CFG();
         returt_statuse=E_OK;
    }
    return returt_statuse;
}



Std_ReturnType i2c_deint(const i2c_t *ptr){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr){
        I2C_DISABLE_CFG();
        MSSP_INRERRUPT_DISABLE();
        MSSP_BC_INRERRUPT_DISABLE();
         returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType i2c_master_send_start(void){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
        // initiait srart 
        I2C_MASTER_START_ENABLE_CFG();
        // wait start 
        while(I2C_MASTER_START_READ_STATUSE_CFG());
        // clear flag 
        MSSP_Interrupt_CLEAR_Flag_bit();
        if(I2C_START_BIT_DETECTED==I2C_START_BIT_STATUSE_CFG()){
            returt_statuse=E_OK;
        }
        else{
            returt_statuse=E_NOT_OK;
        }
         
    
    return returt_statuse;
}

Std_ReturnType i2c_master_send_repet_start(void){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
        // initiait srart 
        I2C_MASTER_REAPTED_START_ENABLE_CFG();
        // wait start 
        while(I2C_MASTER_REAPTED_START_READ_STATUSE_CFG());
        // clear flag 
        MSSP_Interrupt_CLEAR_Flag_bit();
        if(I2C_REAPET_START_BIT_DETECTED==I2C_START_BIT_STATUSE_CFG()){
            returt_statuse=E_OK;
        }
        else{
            returt_statuse=E_NOT_OK;
        }
         
    
    return returt_statuse;
}

Std_ReturnType i2c_master_send_stop(void){
    Std_ReturnType returt_statuse=E_NOT_OK;
    
        // initiait stop
        I2C_MASTER_STOP_ENABLE_CFG();
        // wait start 
        while(I2C_MASTER_STOP_READ_STATUSE_CFG());
        // clear flag 
        MSSP_Interrupt_CLEAR_Flag_bit();
        if(I2C_STOP_BIT_DETECTED==I2C_STOP_BIT_STATUSE_CFG()){
            returt_statuse=E_OK;
        }
        else{
            returt_statuse=E_NOT_OK;
        }
         
    
    return returt_statuse;
}

Std_ReturnType i2c_master_write_block(const i2c_t *ptr,uint8 data,uint8 *_ack){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr && NULL!=_ack){
        SSPBUF=data;
        while(!MSSP_Interrupt_READ_Flag_bit());
        MSSP_Interrupt_CLEAR_Flag_bit();
        if(I2C_MASTER_RECEIVED_ACK==I2C_MASTER_RECEIVED_ACKNOWLEDGE_STATUS_CFG()){
            *_ack=I2C_MASTER_RECEIVED_ACK;
        }
        else{
            *_ack=I2C_MASTER_NOT_RECEIVED_ACK;
        }
         returt_statuse=E_OK;
    }
    return returt_statuse;
}
Std_ReturnType i2c_master_write(const i2c_t *ptr,uint8 data,uint8 *_ack){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr && NULL!=_ack){
        SSPBUF=data;
        while(I2C_BUFFER_STATUSE_CFG());
        if(I2C_MASTER_RECEIVED_ACK==I2C_MASTER_RECEIVED_ACKNOWLEDGE_STATUS_CFG()){
            *_ack=I2C_MASTER_RECEIVED_ACK;
        }
        else{
            *_ack=I2C_MASTER_NOT_RECEIVED_ACK;
        }
         returt_statuse=E_OK;
    }
    return returt_statuse;
}

Std_ReturnType i2c_master_read_block(const i2c_t *ptr,uint8 ack ,uint8 *data){
    Std_ReturnType returt_statuse=E_NOT_OK;
    if(NULL!=ptr && NULL!=data){
        I2C_MASTER_RECEIVE_ENABLE_CFG();
        while(!I2C_BUFFER_STATUSE_CFG());
        *data=SSPBUF;
        if(I2C_MASTER_SEND_ACK==ack){
            I2C_MASTER_SEND_ACK_CFG();
            I2C_MASTER_INITIATES_ACKNOWLEDGE_SEQUENCE_CFG();
        }
        else{
            I2C_MASTER_SEND_NACK_CFG();
            I2C_MASTER_INITIATES_ACKNOWLEDGE_SEQUENCE_CFG();
        }
         returt_statuse=E_OK;
    }
    return returt_statuse;
}

void MSSP_ISR(void){
    MSSP_Interrupt_CLEAR_Flag_bit();
    if(i2c_callback_ptr){
        i2c_callback_ptr();
    }
}

void MSSP_BC_ISR(void){
     MSSP_BC_Interrupt_CLEAR_Flag_bit();
    if(write_collision_callback_ptr){
        write_collision_callback_ptr();
    }
}