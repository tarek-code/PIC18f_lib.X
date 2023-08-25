/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"


#define SLAV1   0x60
#define SLAV2   0x61
uint8 ack=0;



 i2c_t i2c={
     .i2c_clock=100000,
   .default_ptr=NULL,
     .recive_overflow_ptr=NULL,
     .write_collision_ptr=NULL,
   .i2c_cfg.i2c_mode=I2C_MASTER,
   .i2c_cfg.i2c_sub_mode=I2C_MASTER_MODE,
   .i2c_cfg.i2c_smbus_mode=I2C_SMBus_DISABLE,
   .i2c_cfg.i2c_speed_mode=I2C_SLEW_RATE_DISABLE,
  
 };
 
 void MSSP_I2C_MASTER_SEND_1_BYTE(uint8 address,uint8 data){
     i2c_master_send_start();
i2c_master_write(&i2c,address,&ack);
i2c_master_write(&i2c,data,&ack);
i2c_master_send_stop();
}
int main() {

i2c_int(&i2c);




    while (1) {
     
MSSP_I2C_MASTER_SEND_1_BYTE(SLAV1,'a');
__delay_ms(1000);
MSSP_I2C_MASTER_SEND_1_BYTE(SLAV2,'b');
__delay_ms(1000);
MSSP_I2C_MASTER_SEND_1_BYTE(SLAV1,'c');
__delay_ms(1000);
MSSP_I2C_MASTER_SEND_1_BYTE(SLAV2,'d');
__delay_ms(1000);
     
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}

