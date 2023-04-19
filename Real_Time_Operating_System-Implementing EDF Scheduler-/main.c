
#include <stdlib.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "queue.h"
#include "serial.h"
#include "GPIO.h"



#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )


#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )

static void prvSetupHardware( void );


TaskHandle_t Button1_handler = NULL;
TaskHandle_t toggle_handler = NULL;
TaskHandle_t Button2_handler = NULL;
TaskHandle_t Periodic_Transmitter_handler = NULL;
TaskHandle_t Uart_Receiver_handler = NULL;
TaskHandle_t Load1Simulation_handler = NULL;
TaskHandle_t Load2Simulation_handler = NULL;
QueueHandle_t xQueueUart ;




struct AMessage
{
    char ucMessageID;
    char ucData[ 20 ];
};



void vApplicationTickHook( void ){

 
}


void vApplicationIdleHook( void )
	{
	 GPIO_write(PORT_0,PIN0 ,PIN_IS_HIGH ) ; 
	 GPIO_write(PORT_0,PIN0 ,PIN_IS_LOW ) ; 
	}



 
 

void Button_1( void * pvParameters )
{
	
	  while(1)
    {
      GPIO_write(PORT_0,PIN2 ,PIN_IS_HIGH ) ;  
			
			GPIO_read(PORT_0,PIN1);
 			GPIO_write(PORT_0,PIN2 ,PIN_IS_LOW ) ; 				
			vTaskDelay(50) ; 
		}	

}








void Button_2( void * pvParameters )
{ 
	
   while(1)
    {
      GPIO_write(PORT_0,PIN4 ,PIN_IS_HIGH ) ;  
			
			GPIO_read(PORT_0,PIN3);

			GPIO_write(PORT_0,PIN4 ,PIN_IS_LOW ) ; 			
			
			vTaskDelay(50) ; 
		}


}


void Periodic_Transmitter( void * pvParameters )
{

	
    while(1)
    {
			GPIO_write(PORT_0,PIN5 ,PIN_IS_HIGH ) ;
      			
			GPIO_write(PORT_0,PIN5 ,PIN_IS_LOW ) ; 	
	    
			vTaskDelay(100) ;

    }
		
		
}


void Uart_Receiver( void * pvParameters )
{

    while(1)
    {
			GPIO_write(PORT_0,PIN6 ,PIN_IS_HIGH ) ;
      
      vSerialPutString("adham\n",190) ; 
	
			GPIO_write(PORT_0,PIN6 ,PIN_IS_LOW ) ; 	
	    
			vTaskDelay(100) ;			
	
		}
		
}




void Load1Simulation( void * pvParameters )
{
int i ; 
	//37292
    while(1)
    {
			   
    	 GPIO_write(PORT_0,PIN7 ,PIN_IS_HIGH ) ;
			
			for(i = 0 ; i <200 ; i++)
	    {
		   
			}
      
			GPIO_write(PORT_0,PIN7 ,PIN_IS_LOW ) ;		
      
			vTaskDelay(10);
		}
}




void Load2Simulation( void * pvParameters )
{
  int i ;
 
	
    while(1)
    {
			   
			 GPIO_write(PORT_0,PIN8 ,PIN_IS_HIGH ) ;
			
			for(i = 0 ; i <500 ; i++)
	    {
		   
			}
      
			GPIO_write(PORT_0,PIN8 ,PIN_IS_LOW ) ;		
      
			vTaskDelay(100);
		 }
}



int main( void )
{
	
  
	   InitiateSystem();
      
	   xQueueUart = xQueueCreate( 15, sizeof( "Ahmed_Ossairy") );
 
     
     xTaskCreatePeriodic(Button_1
                         ,"Button1"
	                       ,50
	                       ,( void * ) 0
												 ,1
												 ,&Button1_handler
												 ,50 );
	   
     
	   xTaskCreatePeriodic(Button_2
												 ,"Button2"
												 ,50
												 ,( void * ) 0
												 ,1
												 ,&Button2_handler
												 ,50 );
 	   
     
	   xTaskCreatePeriodic(Periodic_Transmitter
												 ,"Periodic_Transmitter"
												 ,100,( void * ) 0
												 ,1,&Periodic_Transmitter_handler
												 ,100 );
	   
     
   	 xTaskCreatePeriodic(Uart_Receiver
												 ,"Uart_Receiver"
												 ,20
												 ,( void * ) 0
												 ,1
												 ,&Uart_Receiver_handler
												 ,20 );
	   
     
     xTaskCreatePeriodic(Load1Simulation
												 ,"Load1Simulation"
												 ,10
												 ,( void * ) 0
												 ,1,&Load1Simulation_handler
												 ,10);
	   
     
     xTaskCreatePeriodic(Load2Simulation
												 ,"Load2Simulation"
												 ,100
												 ,( void * ) 0
												 ,1
												 ,&Load2Simulation_handler
												 ,100 );

	vTaskStartScheduler();


	while(1){


	}
}



void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}


static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void InitiateSystem( void )
{
	GPIO_init();
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);
    VPBDIV = mainBUS_CLK_FULL;
   configTimer1();
	
}




