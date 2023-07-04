/* 
 * File:   Bit_Math.h
 * Author: Unlimited
 *
 * Created on April 24, 2023, 1:41 PM
 */

#ifndef BIT_MATH_H
#define	BIT_MATH_H

#define SET_BIT(Register,Bit_no) 		(Register|=(1<<Bit_no))

#define CLEAR_BIT(Register,Bit_no) 		(Register&=~(1<<Bit_no))

#define TOGGLE_BIT(Register,Bit_no) 	(Register^=(1<<Bit_no))

#define READ_BIT(Register,Bit_no)  	((Register>>Bit_no)&0x01)


/*Section includes */

/*Section macros */

/*Section macros function  */

/*Section Data type */

/*Section function declaration  */


#endif	/* BIT_MATH_H */

