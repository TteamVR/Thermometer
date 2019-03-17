

#include       "C:\dllBridge\Lego\WinMain.h"  
using namespace Lego;



int         res, 
    Temperature;

bool Burner;
bool OldS;

void ConnectionAndControl()
{
	Temperature = Transit[1][1];
		
	if(Burner != OldS)
	{
		if(Burner == true) 
			res = __SET(-949, 1, 1);
		if(Burner == false)      
			res = __SET(-949, 1, 2);
		
		OldS = Burner;
	}

	LDIR(-949, 100, 100, 10);
}

void INIT()
{

}

void START()
{ 		
	/////////////////////////////////////////////////////////////////////////////	
	//																		   //		
	// The "burner" variable is responsible for turning the burner on and off  //	
	// The variable "Timer_CLK" is a timer	                                   //
	// The variable "Temperature" contains the temperature of the thermometer  //
	//                                                                         // 
	/////////////////////////////////////////////////////////////////////////////

	//...............WORK.ZONE.................\\
	
	
	//...............WORK.ZONE.................\\

	ConnectionAndControl();
}





































/*



RECT         rc;

LPRECT   lpRect; 

SYSTEMTIME   st;


int       time;


 	 
 	 GetWindowRect
     (
          hWnd,		// дескриптор окна
          &rc//lpRect 		// адрес структуры для координат окна
     );
     
     Print( 20, 200, (int)rc.left);
     Print(100, 200, (int)rc.top);
     
     GetSystemTime(&st);
     
     time = (st.wHour * 3600) + st.wMinute * 60 + (int)st.wSecond;
     
     
	 Print( 20, 220, "Часы  "   , (int)st.wHour  );
	 Print(120, 220, "Минуты  " , (int)st.wMinute);
	 Print(220, 220, "Секунды  ", (int)st.wSecond);
	 
	 Print(20, 240, "time =  ", time);

*/









        //if(res < 0)  Print(20, 100, "error, res = ", res);
       // if(res < 0)  Print(20, 100, "error, res = ", res);


























/*

void START()
{  

  
     if(T == 100) 
	 { 
		res = __MIG(1111, 1, 1); 
		
        if(res < 0) { Print(20, 100, "error, res = ", res);
                      Print(20, 120, "T = ", T);
					}
	 } 
     
     if(T > 130) 
	 {
			
		res = __MIG(1111, 1, 2); 
		
        if(res < 0) { Print(20, 100, "error, res = ", res);
                      Print(20, 120, "T = ", T);		                      
					}					
		T = 70;			
     }
     
     
 	 T ++;   Print(20, 140, "T = ", T);
 	         Print(20, 160, "Temperature = ", Transit[1][2]);
 	 
 	 LDIR(1111, 100, 0, 10);
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
//					                                             E-mail:    dllbridge@gmail.com







//     В этой функции Вы можете рисовать. Контекст уже захвачен функцией BeginPaint() и будет освобождён автоматически.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////     void mainPAINT()    /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainPAINT()
{




}








//     Эта функция вызывается из оконной процедуры WndProc(), если пользователь выбрал:
// 1)  Какой-либо пункт меню.
// 2)  Нажал кнопку.	

////////////////////////////////////////////////////            
void ScanButtonsAndMenuItems(int item)            //                  
{
	


 
}






