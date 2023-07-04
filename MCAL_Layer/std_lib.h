/* 
 * File:   std_lib.h
 * Author: Unlimited
 *
 * Created on April 22, 2023, 11:01 PM
 */

#ifndef STD_LIB_H
#define	STD_LIB_H




/*Section includes */
#include <stdio.h>
#include <stdlib.h>
#include "../Bit_Math.h"
#include <string.h>
/*Section macros */

/*Section macros function  */

/*Section Data type */
typedef unsigned char 		uint8;
typedef signed char 		sint8;
typedef  unsigned short int 	uint16;
typedef signed short int  	sint16;
typedef unsigned long int  	uint32;
typedef signed  long int	sint32;
typedef float 				f32;
typedef double 				f64;


		typedef enum
		{
	FALSE,
	TRUE
		}boolean;
/*Section function declaration  */


#endif	/* STD_LIB_H */


        
        /*%c        Character
%d                  Signed integer
%e or %E            Scientific notation of floats
%f                  Float values
%g or %G            Similar as %e or %E
%hi                 Signed integer (short)
%hu                 Unsigned Integer (short)
%i                  Unsigned integer
%l or %ld or %li	Long
%lf                 Double
%Lf                 Long double
%lu                 Unsigned int or unsigned long
%lli or %lld        Long long
%llu                Unsigned long long
%o                  Octal representation
%p                  Pointer
%s                  String
%u                  Unsigned int
%x or %X            Hexadecimal representation
%n                  Prints nothing
%%                  Prints % character*/