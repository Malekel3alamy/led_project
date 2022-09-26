/* 
 * File:   mcal_std_types.h
 * Author: Mahmood_Adel
 *
 * Created on September 11, 2022, 8:11 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*   section : includes */
#include "compiler.h"
#include "std_libraries.h"

/*   section : macro  declarations */
#define STD_HIGH           0X01
#define STD_LOW            0X00


#define STD_ON           0X01
#define STD_OFF          0X00


#define STD_ACTIVE           0X01
#define STD_IDLE             0X00


#define E_OK  (STD_RETURN_TYPE)0x01 
#define E_NOT_OK  (STD_RETURN_TYPE)0x00 

/*   section : macro function  declarations */

/*   section : datatype  declarations */

typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned int uint32 ;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed int sint32 ;

typedef uint8 STD_RETURN_TYPE ; 

/*   section : function  declarations */



#endif	/* MCAL_STD_TYPES_H */

