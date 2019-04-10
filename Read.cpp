#ifdef WIN32

#include <windows.h>

#else

#include <unistd.h>

#endif



void delay(int ms){

#ifdef WIN32

  Sleep(ms);

#else

  usleep(ms*1000);

#endif

}

#include "MFRC522.h"

int main()
{
	int rd1=0,rd2=0;
	char temp[2];
	char idstr[20]= {0}; 
 	MFRC522 mfrc;
  	mfrc.PCD_Init();
while(1){
    	// Look for a card
   
	if(!mfrc.PICC_IsNewCardPresent())
	 continue;
	
	if( !mfrc.PICC_ReadCardSerial())
	continue;

	// Print UID
	
	printf("/0");
	
    	for(byte i = 0; i < mfrc.uid.size; ++i)
	{	
		sprintf(temp, "%x",mfrc.uid.uidbyte[i]);
		
	    	strcat(idstr[20],temp);

     		//if(mfrc.uid.uidByte[i] < 0x10){
			
			 
	     	 if(strcmp(idstr[20],"5EE7B163")==0)
		{
			rd1++;	
		}
	      else if(mfrc.uid.uidByte[i] =="A1 79 4D 63")
	      {
		      rd2++;	        
	      }	
	      //DISPLAYING THE ITEMS WHETHER IN BAG OR NOT BY EVEN AND ODD COUNT
	      		if(rd1%2!=0)
    			printf("PLACED LAPTOP ");
   			else
   			printf("FORGOT LAPTOP");
	      		if(rd2%2 !=0)
    			printf("PLACED BOTTLE");
    			else 
    			printf("FORGOT TO PLACE BOTTLE IN BAG");
      }
    }

    printf("\n");

    delay(1000);

  }

  return 0;

}
