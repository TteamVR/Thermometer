



#include     <stdio.h>



                            
int  Transit[11][100];                 //   Этот массив копируется в dllBridge.dll и будет доступен из других программ.

#include    "C:\\dllBridge\\Bridge.h"                            //  Заголовочный файл, который поможет подключить dll  
int res = Init_dllBridge(3213, "PrOgRaMm");                                       //  Номер и название Вашей программы.




int main() 
{

   int  Temperature;

   if(res == 0) { printf("%s", "Could not connect library C:\\dllBridge\\dllBridge.dll"); Sleep(5000);}
   else 
   {
	   for(;;)                   //  Этот цикл демонстрирует, как изменить элемент Transit и отправить в dllBridge.dll 
	   {
			
	       Sleep(1000);                                                                              // Ждём 1 секунду
           Temperature = Transit[1][1];
           
              res = __SET(-949, 2, 3);                          //  Попытка передать 3 (любое число)  в -949 программу.
           if(res == -102)                                              // Проверим, включена программа -949 или нет ?  
		   {
			  printf("%s","\nTurn on the program \"Thermometer\"\n");     
			  printf("%s","C:\\dllBridge\\ForWinLego\\Demo\\Thermometer\\Thermometer.exe\n");
			  
		   }
 	       else 
 	       {                     //  Transit[1][2] -     это датчик огня             (0 - нет пламени, 1 - есть пламя)                    
			  if(Temperature < 30 && Transit[1][2] == 0)                                //  Включить  газовую горелку 
			  { 
				 res = __SET(-949, 1, 1);  
				 printf("\nTurn ON\n"  );                				  
			  }
			  
	          if(Temperature > 70 && Transit[1][2] == 1)                                                //  Выключить
			  { 
				 res = __SET(-949, 1, 2);  
				 printf("\nturned off the gas burner\n"); 
			  }
			  printf("%s%d", "\nTemperature = ", Transit[1][1]);
		   }
		   
 	       LDIR(-949, 100, 100, 10);            //   Копируем из -949 программы 10 переменных, начиная с Transit[1][0]

	      _Transit();                         //  Смотрите содержимое Transit[][] в программе C:\dllBridge\UniMons.exe 
	   }    
   } 
}






































/*

int main() 
{

   if(res == 0) printf("%s", "Could not connect library C:\\dllBridge\\dllBridge.dll"); 
   else 
   {
	   for(;;)                   //  Этот цикл демонстрирует, как изменить элемент Transit и отправить в dllBridge.dll 
	   {
			
	       Sleep(500);                                                                             // Ждём 0.5 секунды
	       
	       printf("%d ", Transit[7][15] ++);
	       
	      _Transit();                      //  Смотрите содержимое Transit[7][15] в программе C:\dllBridge\UniMons.exe 
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










