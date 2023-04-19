/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  GPIO
 *
 *  Description:  header file for General_Purpose_Input_Output-GPIO- Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define PORTA                                 0x40058000
#define GPIODATA_A                            (*((volatile GPIODATA_Tag*)(PORTA+0x3FC)))
#define GPIODIR_A                             (*((volatile GPIODIR_Tag*)(PORTA+0x400))) 
#define GPIODEN_A                              (*((volatile GPIODEN_Tag*)(PORTA+ 0x51C))) 


#define PORTB                                 0x40059000
#define GPIODATA_B                            (*((volatile GPIODATA_Tag*)(PORTB+0x3FC)))
#define GPIODIR_B                             (*((volatile GPIODIR_Tag*)(PORTB+0x400))) 
#define GPIODEN_B                              (*((volatile GPIODEN_Tag*)(PORTB+ 0x51C))) 


#define PORTC                                 0x4005A000
#define GPIODATA_C                            (*((volatile GPIODATA_Tag*)(PORTC+0x3FC)))
#define GPIODIR_C                             (*((volatile GPIODIR_Tag*)(PORTC+0x400))) 
#define GPIODEN_C                              (*((volatile GPIODEN_Tag*)(PORTC+ 0x51C))) 


#define PORTD                                 0x40007000
#define GPIODATA_D                            (*((volatile GPIODATA_Tag*)(PORTD+0x3FC)))
#define GPIODIR_D                             (*((volatile GPIODIR_Tag*)(PORTD+0x400))) 
#define GPIODEN_D                              (*((volatile GPIODEN_Tag*)(PORTD+ 0x51C))) 


#define PORTE                                  0x40024000
#define GPIODATA_E                            (*((volatile GPIODATA_Tag*)(PORTE+0x3FC)))
#define GPIODIR_E                             (*((volatile GPIODIR_Tag*)(PORTE+0x400)))
#define GPIODEN_E                              (*((volatile GPIODEN_Tag*)(PORTE+ 0x51C))) 


#define PORTF                                 0x40025000
#define GPIODATA_F                            (*((volatile GPIODATA_Tag*)(PORTF+0x3FC)))
#define GPIODIR_F                             (*((volatile GPIODIR_Tag*)(PORTF+0x400)))
#define GPIODEN_F                              (*((volatile GPIODEN_Tag*)(0x40025000+ 0x51C))) 


#define RCGCGPIO                              (*((volatile RCGCGPIO_Tag*)(0x400FE000+ 0x608)))
	
 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



typedef struct 
{
   uint32 PIN0 :1;
   uint32 PIN1 :1;
   uint32 PIN2 :1;
   uint32 PIN3 :1;
   uint32 PIN4 :1;
   uint32 PIN5 :1;
   uint32 PIN6 :1;
   uint32 PIN7 :1;
   uint32        :24;

}GPIODEN_BF;

typedef union 
{
    uint32 R;
    GPIODEN_BF B;

}GPIODEN_Tag;


typedef struct 
{
   uint32 DATA0 :1;
   uint32 DATA1 :1;
   uint32 DATA2 :1;
   uint32 DATA3 :1;
   uint32 DATA4 :1;
   uint32 DATA5 :1;
   uint32 DATA6 :1;
   uint32 DATA7 :1;
   uint32       :24;

}GPIODATA_F_BF;

typedef union 
{
    uint32 R;
    GPIODATA_F_BF B;

}GPIODATA_Tag;


typedef struct 
{
   uint32 DIR0 :1;
   uint32 DIR1 :1;
   uint32 DIR2 :1;
   uint32 DIR3 :1;
   uint32 DIR4 :1;
   uint32 DIR5 :1;
   uint32 DIR6 :1;
   uint32 DIR7 :1;
   uint32      :24;

}GPIODIRF_BF;

typedef union 
{
    uint32 R;
    GPIODIRF_BF B;

}GPIODIR_Tag;


typedef struct 
{
   uint32 R0   :1;
   uint32 R1   :1;
   uint32 R2   :1;
   uint32 R3   :1;
   uint32 R4   :1;
   uint32 R5   :1;
   uint32      :26;

}RCGCGPIO_BF;

typedef union 
{
    uint32 R;
    RCGCGPIO_BF B;

}RCGCGPIO_Tag;






enum DataDir { INPUT, OUTPUT};
enum PORT { portA, portB,portC,portD,portE,portF};


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void GPIO_Init(void)                                      
* \Description     : initialize GPIO ports 
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIO_Init( enum DataDir c , enum PORT port);


/******************************************************************************
* \Syntax          : unit32 DigitalRead(enum PORT )                                      
* \Description     : Read from GPIO port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : enum PORT port                      
* \Parameters (out): None                                                      
* \Return value:   : digital value
*******************************************************************************/

uint32 DigitalRead(enum PORT port);

/******************************************************************************
* \Syntax          : unit32 DigitalWrite(enum PORT , uint32 value)                                      
* \Description     : Write into GPIO port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : enum PORT port  , uint32 value                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void DigitalWrite(enum PORT port , uint32 value);

#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
