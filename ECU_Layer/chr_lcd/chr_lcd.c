#include "chr_lcd.h"
static void lcd_send_4_bit(const chr_lcd_4_bit *lcd,uint8 _data_command);
static void lcd_send_4_bit_enable(const chr_lcd_4_bit *lcd);
static void lcd_send_8_bit_enable(const chr_lcd_8_bit *lcd);
static void lcd_4_bit_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 colmn);
static void lcd_8_bit_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 colmn);




Std_ReturnType chr_lcd_4_int(const chr_lcd_4_bit *lcd){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_int(&(lcd->chr_lcd_e_pin));
        gpio_pin_int(&(lcd->chr_lcd_rs_pin));
        for(uint8 i=0;i<4;i++){
            gpio_pin_int(&(lcd->data_pin[i]));
        }
        __delay_ms(20);
         chr_lcd_4_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
         __delay_ms(5);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
          __delay_us(150);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_CLEAR_DISPLAY);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_RETURN_HOME);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD__MODE_INCREAMENT_SHIFT_OFF);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_4_BIT_2_LINE_5_8_MODE);
          chr_lcd_4_send_cmd(lcd,_CHR_LCD_START_DDRAM_ADDRESS);
    }
    
    return return_statuse;
}


Std_ReturnType chr_lcd_4_send_cmd(const chr_lcd_4_bit *lcd,uint8 cmd){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_LOW);
        lcd_send_4_bit(lcd,cmd>>4);
        lcd_send_4_bit_enable(lcd);
        lcd_send_4_bit(lcd,cmd);
        lcd_send_4_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_4_send_char(const chr_lcd_4_bit *lcd,uint8 data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_HIGH);
        lcd_send_4_bit(lcd,data>>4);
        lcd_send_4_bit_enable(lcd);
        lcd_send_4_bit(lcd,data);
        lcd_send_4_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_4_send_char_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        lcd_4_bit_pos(lcd,row,col);
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_HIGH);
        lcd_send_4_bit(lcd,data>>4);
        lcd_send_4_bit_enable(lcd);
        lcd_send_4_bit(lcd,data);
        lcd_send_4_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_4_send_string(const chr_lcd_4_bit *lcd,uint8 *data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    uint8 i=0;
    if(NULL!=lcd){
        while(data[i]!='\0'){
            chr_lcd_4_send_char(lcd,data[i]);
            i++;
        }
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_4_send_string_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 *data){
    Std_ReturnType return_statuse=E_NOT_OK;
    uint8 i=0;
    if(NULL!=lcd){
        lcd_4_bit_pos(lcd,row,col);
        while(data[i]!='\0'){
            chr_lcd_4_send_char(lcd,data[i]);
            i++;
        }
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_4_send_custom_char(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 data[],uint8 mem){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        chr_lcd_4_send_cmd(lcd,(_CHR_LCD_START_CGRAM_ADDRESS)+(mem*8));
        for(uint8 i=0;i<8;i++){
            chr_lcd_4_send_char(lcd,data[i]);
        }
        chr_lcd_4_send_char_pos(lcd,row,col,mem);
    }
    
    return return_statuse;
}



Std_ReturnType chr_lcd_8_int(const chr_lcd_8_bit *lcd){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_int(&(lcd->chr_lcd_e_pin));
         gpio_pin_int(&(lcd->chr_lcd_rs_pin));
         for(uint8 i=0;i<8;i++){
            gpio_pin_int(&(lcd->data_pin[i]));
         }
         __delay_ms(20);
         chr_lcd_8_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
         __delay_ms(5);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
          __delay_us(150);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_CLEAR_DISPLAY);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_RETURN_HOME);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD__MODE_INCREAMENT_SHIFT_OFF);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_8_BIT_2_LINE_5_8_MODE);
          chr_lcd_8_send_cmd(lcd,_CHR_LCD_START_DDRAM_ADDRESS);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_cmd(const chr_lcd_8_bit *lcd,uint8 cmd){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_LOW);
        for(uint8 i=0;i<8;i++){
            gpio_pin_write_level(&(lcd->data_pin[i]),(cmd>>i)&0x01);
        }
        lcd_send_8_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_char(const chr_lcd_8_bit *lcd,uint8 data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_HIGH);
        for(uint8 i=0;i<8;i++){
            gpio_pin_write_level(&(lcd->data_pin[i]),(data>>i)&0x01);
        }
        lcd_send_8_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_char_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        lcd_8_bit_pos(lcd,row,col);
        gpio_pin_write_level(&(lcd->chr_lcd_rs_pin),GPIO_HIGH);
        for(uint8 i=0;i<8;i++){
            gpio_pin_write_level(&(lcd->data_pin[i]),(data>>i)&0x01);
        }
        lcd_send_8_bit_enable(lcd);
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_string(const chr_lcd_8_bit *lcd,uint8 *data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        while(*data){
            chr_lcd_8_send_char(lcd,*data++);
            
        }
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_string_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 *data){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
        lcd_8_bit_pos(lcd,row,col);
        while(*data){
            chr_lcd_8_send_char(lcd,*data++);
            
        }
    }
    
    return return_statuse;
}

Std_ReturnType chr_lcd_8_send_custom_char(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 data[],uint8 mem){
    Std_ReturnType return_statuse=E_NOT_OK;
    
    if(NULL!=lcd){
      
        chr_lcd_8_send_cmd(lcd,(_CHR_LCD_START_CGRAM_ADDRESS+(mem*8)));
        for(uint8 i=0;i<8;i++){
            chr_lcd_8_send_char(lcd,data[i]);
        }
        chr_lcd_8_send_char_pos(lcd,row,col,mem);
    }
    
    return return_statuse;
}




/*helper functions*/
static void lcd_send_4_bit(const chr_lcd_4_bit *lcd,uint8 _data_command){
    if(NULL!=lcd){
        for(uint8 i=0;i<4;i++){
            gpio_pin_write_level(&(lcd->data_pin[i]),(_data_command>>i)&0x01);
        }
    }
}




static void lcd_send_4_bit_enable(const chr_lcd_4_bit *lcd){
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_e_pin),GPIO_HIGH);
        __delay_us(5);
        gpio_pin_write_level(&(lcd->chr_lcd_e_pin),GPIO_LOW);
    }
}

static void lcd_send_8_bit_enable(const chr_lcd_8_bit *lcd){
    if(NULL!=lcd){
        gpio_pin_write_level(&(lcd->chr_lcd_e_pin),GPIO_HIGH);
        __delay_us(5);
        gpio_pin_write_level(&(lcd->chr_lcd_e_pin),GPIO_LOW);
    }
}


static void lcd_8_bit_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 colmn){
    colmn--;
    switch(row){
        case ROW1 : 
            chr_lcd_8_send_cmd(lcd,0x80+colmn);
            break;
        case ROW2:
            chr_lcd_8_send_cmd(lcd,0xc0+colmn);
            break;
        case ROW3:
            chr_lcd_8_send_cmd(lcd,0x94+colmn);
            break;
        case ROW4:
            chr_lcd_8_send_cmd(lcd,0xd4+colmn);
            break;
    }
}

static void lcd_4_bit_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 colmn){
    colmn--;
    switch(row){
        case ROW1 : 
            chr_lcd_4_send_cmd(lcd,0x80+colmn);
            break;
        case ROW2:
            chr_lcd_4_send_cmd(lcd,0xc0+colmn);
            break;
        case ROW3:
            chr_lcd_4_send_cmd(lcd,0x94+colmn);
            break;
        case ROW4:
            chr_lcd_4_send_cmd(lcd,0xd4+colmn);
            break;
    }
}


 void convert_byte_to_str(uint8 number,uint8 *str){
    uint8 Temp_str[4]={0};
     uint8 counter=0;
    memset(str,' ',3);
    str[3]='\0';
    if(NULL!=str){
        sprintf(Temp_str,"%u",number);
    }
    while(Temp_str[counter]!='\0'){
        str[counter]=Temp_str[counter];
        counter++;
    }
    
    
}
 void convert_short_to_str(uint16 number,uint8 *str){
     uint8 Temp_str[6]={0};
     uint8 counter=0;
    memset(str,' ',5);
     str[5]='\0';
    if(NULL!=str){
        sprintf(Temp_str,"%u",number);
    }
    while(Temp_str[counter]!='\0'){
        str[counter]=Temp_str[counter];
        counter++;
    }
    
}
 void convert_int_to_str(uint32 number,uint8 *str){
     
   uint8 Temp_str[11]={0};
     uint8 counter=0;
    memset(str,' ',10);
    str[10]='\0';
    if(NULL!=str){
        sprintf(Temp_str,"%u",number);
    }
    while(Temp_str[counter]!='\0'){
        str[counter]=Temp_str[counter];
        counter++;
    }
    
    
}
 
 
