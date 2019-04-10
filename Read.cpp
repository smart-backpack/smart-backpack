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
#include <string.h>
int main()
{
	int rd1=0,rd2=0,rd3=0,rd4=0,rd5=0,rd6=0;
	char temp[2];
	char idstr[20]; 
 	MFRC522 mfrc;
  	mfrc.PCD_Init();
while(1){
    	// Look for a card 
	if(!mfrc.PICC_IsNewCardPresent())
	 continue;

	if( !mfrc.PICC_ReadCardSerial())
	continue;

	// Print UID

	idstr[0]=0;
    	for(byte i = 0; i <7 ; ++i)
	{
	sprintf(temp, "%X",mfrc.uid.uidByte[i]);
    	strcat(idstr,temp);
     	}
	     	 if(int(strcmp(idstr,"499637AB05780"))==0)
		{
			rd1++;
		}
	        else if(int(strcmp(idstr,"494637AB05780"))==0) // if(strcmp(idstr,"A1794D63")==0)
	        {
	        	rd2++;
	        }
		else if(int(strcmp(idstr,"48F637AB05780"))==0)
		{
			rd3++;
		}
		else if(int(strcmp(idstr,"48A637AB05780"))==0)
		{
			rd4++;
		}
		else if(int(strcmp(idstr,"485637AB05780"))==0)
		{
			rd5++;
		}
		else if(int(strcmp(idstr,"480637AB05780"))==0)
		{
			rd6++;
		}

	      //DISPLAYING THE ITEMS WHETHER IN BAG OR NOT BY EVEN AND ODD COUNT
			if(rd1>=0)
			{
			printf("LAPTOP: ");
	      			if(rd1%2!=0)
    				printf("PLACED \n");
   				else
   				printf("NOT PLACED \n");
			}

			if(rd2>=0)
			{
			printf("BOTTLE: ");
	      			if(rd2%2 !=0)
    				printf("PLACED \n");
    				else 
    				printf("NOT PLACED \n");
			}

			if(rd3>=0)
			{
			printf("DIARY : ");
				if(rd3%2!=0)
				printf("PLACED \n");
				else
				printf("NOT PLACED \n");
			}
			if(rd4>=0)
			{
			printf("KEYS: ");
				if(rd4%2!=0)
				printf("PLACED \n");
				else
				printf("NOT PLACED \n");
			}
			if(rd5>=0)
			{
			printf("CHARGER: ");
			if(rd5%2!=0)
			printf("PLACED \n");
			else
			printf("NOT PLACED \n\n\n");
}
    printf("\n");
    delay(1000);

  }

  return 0;

}
