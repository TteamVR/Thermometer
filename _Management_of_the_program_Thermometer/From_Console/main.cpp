



#include     <stdio.h>



                            
int  Transit[11][100];                 //   ���� ������ ���������� � dllBridge.dll � ����� �������� �� ������ ��������.

#include    "C:\\dllBridge\\Bridge.h"                            //  ������������ ����, ������� ������� ���������� dll  
int res = Init_dllBridge(3213, "PrOgRaMm");                                       //  ����� � �������� ����� ���������.




int main() 
{

   int  Temperature;

   if(res == 0) { printf("%s", "Could not connect library C:\\dllBridge\\dllBridge.dll"); Sleep(5000);}
   else 
   {
	   for(;;)                   //  ���� ���� �������������, ��� �������� ������� Transit � ��������� � dllBridge.dll 
	   {
			
	       Sleep(1000);                                                                              // ��� 1 �������
           Temperature = Transit[1][1];
           
              res = __SET(-949, 2, 3);                          //  ������� �������� 3 (����� �����)  � -949 ���������.
           if(res == -102)                                              // ��������, �������� ��������� -949 ��� ��� ?  
		   {
			  printf("%s","\nTurn on the program \"Thermometer\"\n");     
			  printf("%s","C:\\dllBridge\\ForWinLego\\Demo\\Thermometer\\Thermometer.exe\n");
			  
		   }
 	       else 
 	       {                     //  Transit[1][2] -     ��� ������ ����             (0 - ��� �������, 1 - ���� �����)                    
			  if(Temperature < 30 && Transit[1][2] == 0)                                //  ��������  ������� ������� 
			  { 
				 res = __SET(-949, 1, 1);  
				 printf("\nTurn ON\n"  );                				  
			  }
			  
	          if(Temperature > 70 && Transit[1][2] == 1)                                                //  ���������
			  { 
				 res = __SET(-949, 1, 2);  
				 printf("\nturned off the gas burner\n"); 
			  }
			  printf("%s%d", "\nTemperature = ", Transit[1][1]);
		   }
		   
 	       LDIR(-949, 100, 100, 10);            //   �������� �� -949 ��������� 10 ����������, ������� � Transit[1][0]

	      _Transit();                         //  �������� ���������� Transit[][] � ��������� C:\dllBridge\UniMons.exe 
	   }    
   } 
}






































/*

int main() 
{

   if(res == 0) printf("%s", "Could not connect library C:\\dllBridge\\dllBridge.dll"); 
   else 
   {
	   for(;;)                   //  ���� ���� �������������, ��� �������� ������� Transit � ��������� � dllBridge.dll 
	   {
			
	       Sleep(500);                                                                             // ��� 0.5 �������
	       
	       printf("%d ", Transit[7][15] ++);
	       
	      _Transit();                      //  �������� ���������� Transit[7][15] � ��������� C:\dllBridge\UniMons.exe 
	   }    
   } 
}



*/










//			                                                                   (   )       
//													                          (    )
//													                           (    )
//													                          (    )
//													                            )  )
//													                           (  (                  /\
//													                            (_)                 /  \  /\
//													                    ________[_]________      /\/    \/  \
//													           /\      /\        ______    \    /   /\/\  /\/\
//													          /  \    //_\       \    /\    \  /\/\/    \/    \
//													   /\    / /\/\  //___\       \__/  \    \/
//													  /  \  /\/    \//_____\       \ |[]|     \
//													 /\/\/\/       //_______\       \|__|      \
//													/      \      /XXXXXXXXXX\                  \
//													        \    /_I_II  I__I_\__________________\
//													               I_I|  I__I_____[]_|_[]_____I
//													               I_II  I__I_____[]_|_[]_____I
//													               I II__I  I     XXXXXXX     I
//				                                                 E-mail:	dllbridge@gmail.com   










