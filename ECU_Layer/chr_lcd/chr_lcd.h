/* 
 * File:   chr_lcd.h
 * Author: Unlimited
 *
 * Created on May 5, 2023, 12:58 PM
 */

#ifndef CHR_LCD_H
#define	CHR_LCD_H

/*Section includes */

#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "chr_lcd_cfg.h"

/*Section macros */

#define _CHR_LCD_CLEAR_DISPLAY  (0x01)


#define _CHR_LCD_RETURN_HOME    (0x02)


#define _CHR_LCD__MODE_INCREAMENT_SHIFT_OFF  (0x06)
#define _CHR_LCD_MODE_DECREMENT_SHIFT_OFF  (0x04)
#define _CHR_LCD_MODE_SHIFT_LEFT   (0x07)
#define _CHR_LCD_MODE_SHIFT_RIGHT  (0x05)




#define _CHR_LCD_DISPLAY_OFF  (0x08)
#define _CHR_LCD_DISPLAY_ON_CURSOR_OFF  (0x0C)
#define _CHR_LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF  (0x0E)
#define _CHR_LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON  (0x0F)


#define _CHR_LCD_SHIFT_CURSOR_LEFT  (0x10)
#define _CHR_LCD_SHIFT_CURSOR_RIGHT  (0x14)
#define _CHR_LCD_SHIFT_ALL_DISPLAY_LEFT  (0x18)
#define _CHR_LCD_SHIFT_ALL_DISPLAY_RIGHT  (0x1C)


#define _CHR_LCD_4_BIT_1_LINE_5_8_MODE  (0x20)
#define _CHR_LCD_4_BIT_1_LINE_5_11_MODE  (0x24)
#define _CHR_LCD_4_BIT_2_LINE_5_8_MODE  (0x28)
#define _CHR_LCD_4_BIT_2_LINE_5_11_MODE  (0x2C)
#define _CHR_LCD_8_BIT_1_LINE_5_8_MODE  (0x30)
#define _CHR_LCD_8_BIT_1_LINE_5_11_MODE  (0x34)
#define _CHR_LCD_8_BIT_2_LINE_5_8_MODE  (0x38)
#define _CHR_LCD_8_BIT_2_LINE_5_11_MODE  (0x3C)



#define _CHR_LCD_START_CGRAM_ADDRESS  (0x40)

#define _CHR_LCD_START_DDRAM_ADDRESS  (0x80)

#define _CHR_START_WRITE_DATA_TO_ADRESS  (0x200)




/*Section macros function  */

/*Section Data type */
typedef struct{
    pin_cfg_t chr_lcd_rs_pin;
    pin_cfg_t chr_lcd_e_pin;
    pin_cfg_t data_pin[4];
}chr_lcd_4_bit;

typedef struct{
    pin_cfg_t chr_lcd_rs_pin;
    pin_cfg_t chr_lcd_e_pin;
    pin_cfg_t data_pin[8];
}chr_lcd_8_bit;

typedef enum{
    ROW1=1,
            ROW2,
            ROW3,
            ROW4
}chr_lcd_rows_t;

/*Section function declaration  */
Std_ReturnType chr_lcd_4_int(const chr_lcd_4_bit *lcd);
Std_ReturnType chr_lcd_4_send_cmd(const chr_lcd_4_bit *lcd,uint8 cmd);
Std_ReturnType chr_lcd_4_send_char(const chr_lcd_4_bit *lcd,uint8 data);
Std_ReturnType chr_lcd_4_send_char_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 data);
Std_ReturnType chr_lcd_4_send_string(const chr_lcd_4_bit *lcd,uint8 *data);
Std_ReturnType chr_lcd_4_send_string_pos(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 *data);
Std_ReturnType chr_lcd_4_send_custom_char(const chr_lcd_4_bit *lcd,uint8 row,uint8 col,uint8 data[],uint8 mem);


Std_ReturnType chr_lcd_8_int(const chr_lcd_8_bit *lcd);
Std_ReturnType chr_lcd_8_send_cmd(const chr_lcd_8_bit *lcd,uint8 cmd);
Std_ReturnType chr_lcd_8_send_char(const chr_lcd_8_bit *lcd,uint8 data);
Std_ReturnType chr_lcd_8_send_char_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 data);
Std_ReturnType chr_lcd_8_send_string(const chr_lcd_8_bit *lcd,uint8 *data);
Std_ReturnType chr_lcd_8_send_string_pos(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 *data);
Std_ReturnType chr_lcd_8_send_custom_char(const chr_lcd_8_bit *lcd,uint8 row,uint8 col,uint8 data[],uint8 mem);



 
void convert_byte_to_str(uint8 number,uint8 *str);
void convert_short_to_str(uint16 number,uint8 *str);
void convert_int_to_str(uint32 number,uint8 *str);
#endif	/* CHR_LCD_H */

