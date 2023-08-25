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
volatile uint8 slave1_counter=0;
void Default(void){
    slave1_counter++;
}

 i2c_t i2c={
     
   .default_ptr=Default,
     .recive_overflow_ptr=NULL,
     .write_collision_ptr=NULL,
   .i2c_cfg.i2c_mode=I2C_SLAVE,
   .i2c_cfg.i2c_general_call=I2C_SLAVE_GENERAL_CALL_DISABLE,
   .i2c_cfg.i2c_sub_mode=I2C_SLAVE_MODE_7_BIT_ADDRESS,
   .i2c_cfg.i2c_smbus_mode=I2C_SMBus_DISABLE,
   .i2c_cfg.i2c_speed_mode=I2C_SLEW_RATE_DISABLE,
  .i2c_cfg.i2c_slave_address=0x60,
 };
 

int main() {

i2c_int(&i2c);




    while (1) {
     

     
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}

