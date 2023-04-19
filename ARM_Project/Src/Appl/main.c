#include "IntCrtl.h"
#include "Mcu_Hw.h"

volatile uint32 CurrentState =0;
volatile uint32 OFFPeriod =1;  /* Half second as an initial off period */
volatile uint32 ONPeriod =1;   /* Half second as an initial on period */


void nano(void)
{
   if(CurrentState==1){
	   DigitalWrite(portF,LOW);
		 SYSTICK_SetPeriod(OFFPeriod);  /* Period in seconds */
		 CurrentState=0;
	 }else if(CurrentState==0){
	   DigitalWrite(portF,HIGH);
	   SYSTICK_SetPeriod(ONPeriod);  /* Period in seconds */
	   CurrentState=1;
	 }
	
	
	//GPIODATA_F.B.DATA0 ^=1; 
	
}


int main(void){

	uint32 Switch1=0; 
	uint32 Switch2=0; 
	uint32 previous_value1=0; 
	uint32 previous_value2= 0;
	
	
	
	GPIO_Init(INPUT,portD);
	GPIO_Init(INPUT,portE);
	
	GPIO_Init(OUTPUT,portF);
	SYSTICK_Init();
	SYSTICK_usrCallbackFn(nano);
	
	//DigitalWrite(portF,HIGH);
while(1){

	Switch1=DigitalRead(portE);
	Switch2=DigitalRead(portD);
  
  if(Switch1==1 && previous_value1 ==0){
	 
  		OFFPeriod=OFFPeriod+1;
		  if(ONPeriod > 1){
				
			ONPeriod=ONPeriod-1;
				
			}
	}

  if(Switch2==1 && previous_value2 ==0){
	 
  		ONPeriod=ONPeriod+1;
		  if(OFFPeriod > 1){
				
			OFFPeriod=OFFPeriod-1;
				
			}
	}	
	
/*////////////// Update the previous values //////////////////*/
previous_value1=	Switch1;
previous_value2=	Switch2;	
	

}
return 0;


	
}





