/* 
 * File:   Application.c
 * Author: Unlimited
 *
 * Created on April 22, 2023, 10:23 PM
 */
#include "Application.h"



volatile uint8 slave2_data_rec=0;

void Default(void){
    // enable streatching 
    I2C_SLAVE_CLOCK_STRETCH_CFG();
    if((I2C_SLAVE_IN_WRITE==I2C_SLAVE_READ_WRITE_STATUSE_CFG())&&(I2C_SLAVE_RECEIVED_OR_TRANSMITTED_BYTE_WAS_ADDRESS==I2C_SLAVE_RECEIVED_OR_TRANSMITTED_BYTE_STATUSE_CFG())){
        uint8 dummydata=SSPBUF;
        while(!I2C_BUFFER_STATUSE_CFG());
        slave2_data_rec=SSPBUF;
    }
    else if(I2C_SLAVE_IN_READ==I2C_SLAVE_READ_WRITE_STATUSE_CFG()){
        
    }
    else{
        // do nothing 
    }
    // end stritching 
    I2C_SLAVE_CLOCK_RELEASES_CFG();
}
led_cfg_t led1={
  .led_status=LED_OFF,
.pin_number=GPIO_PIN0,
.port_name=PORTD_INDX,  
};
 i2c_t i2c={
     
   .default_ptr=Default,
     .recive_overflow_ptr=NULL,
     .write_collision_ptr=NULL,
   .i2c_cfg.i2c_mode=I2C_SLAVE,
   .i2c_cfg.i2c_general_call=I2C_SLAVE_GENERAL_CALL_DISABLE,
   .i2c_cfg.i2c_sub_mode=I2C_SLAVE_MODE_7_BIT_ADDRESS,
   .i2c_cfg.i2c_smbus_mode=I2C_SMBus_DISABLE,
   .i2c_cfg.i2c_speed_mode=I2C_SLEW_RATE_DISABLE,
  .i2c_cfg.i2c_slave_address=0x70,
 };
 

int main() {

i2c_int(&i2c);
led_int(&led1);



    while (1) {
     if(slave2_data_rec=='b'){
         led_on(&led1);
     }
     else if(slave2_data_rec=='d'){
         led_off(&led1);
     }
     else{
         // do nothing 
     }

     
    }
    return (EXIT_SUCCESS);
}

void application_Int() {

}