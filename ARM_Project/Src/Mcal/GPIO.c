/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  General Purpose Input Output Driver
 *
 *      \details  Driver Configure of the GPIO.
 *               
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void GPIOInit(void)                                      
* \Description     : initialize GPIO                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : enum DataDir x , enum PORT port                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GPIO_Init( enum DataDir c , enum PORT port)
{
   
	////////////////PORT_Initialization//////////////////
	    switch (port) {
        case portA:
            RCGCGPIO.B.R0=0x01;
				    GPIODEN_A.B.PIN0=1;				
            break;
        case portB:
            RCGCGPIO.B.R1=0x01;
				    GPIODEN_B.B.PIN0=1;				
            break;
        case portC:
            RCGCGPIO.B.R2=0x01;
				    GPIODEN_C.B.PIN0=1;				
            break;
        case portD:
            RCGCGPIO.B.R3=0x01;
				    GPIODEN_D.B.PIN0=1;				
            break;
        case portE:
            RCGCGPIO.B.R4=0x01;
				    GPIODEN_E.B.PIN0=1;				
            break;
        case portF:
            RCGCGPIO.B.R5=0x01;
				    GPIODEN_F.B.PIN0=1;
            break;
			}
	////////////////////////////////////////////////////
	
	
	
	
	if(c == INPUT){
	   
		
		
		
		
			    switch (port) {
        case portA:
            GPIODIR_A.B.DIR0=0;				
            break;
        case portB:
            GPIODIR_B.B.DIR0=0;				
            break;
        case portC:
            GPIODIR_C.B.DIR0=0;				
            break;
        case portD:
            GPIODIR_D.B.DIR0=0;			
            break;
        case portE:
            GPIODIR_E.B.DIR0=0;				
            break;
        case portF:
            GPIODIR_F.B.DIR0=0;
            break;
			}
		

		
	  }
	else if(c == OUTPUT){
		
		
			    switch (port) {
        case portA:
            GPIODIR_A.B.DIR0=1;				
            break;
        case portB:
            GPIODIR_B.B.DIR0=1;				
            break;
        case portC:
            GPIODIR_C.B.DIR0=1;				
            break;
        case portD:
            GPIODIR_D.B.DIR0=1;			
            break;
        case portE:
            GPIODIR_E.B.DIR0=1;				
            break;
        case portF:
            GPIODIR_F.B.DIR0=1;
            break;
			}
		

		}
	
	

}

/******************************************************************************
* \Syntax          : unit32 DigitalRead(enum PORT)                                      
* \Description     : Read from GPIO port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : enum PORT port                      
* \Parameters (out): None                                                      
* \Return value:   : digital value
*******************************************************************************/

uint32 DigitalRead(enum PORT port){

		    switch (port) {
        case portA:
            return GPIODATA_A.B.DATA0;
            break;
        case portB:
            return GPIODATA_B.B.DATA0;				
            break;
        case portC:
            return GPIODATA_C.B.DATA0;				
            break;
        case portD:
            return GPIODATA_D.B.DATA0;				
            break;
        case portE:
            return GPIODATA_E.B.DATA0;				
            break;
        case portF:
            return GPIODATA_F.B.DATA0;
            break;
			}

}


/******************************************************************************
* \Syntax          : unit32 DigitalWrite(enum PORT , uint32 value)                                      
* \Description     : Write into GPIO port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : enum PORT port , uint32 value                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void DigitalWrite(enum PORT port , uint32 value){

			    switch (port) {
        case portA:
            GPIODATA_A.B.DATA0=value;				
            break;
        case portB:
            GPIODATA_B.B.DATA0=value;				
            break;
        case portC:
            GPIODATA_C.B.DATA0=value;				
            break;
        case portD:
            GPIODATA_D.B.DATA0=value;			
            break;
        case portE:
            GPIODATA_E.B.DATA0=value;				
            break;
        case portF:
            GPIODATA_F.B.DATA0=value;
            break;
			}


}


/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/