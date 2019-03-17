








#include       "C:\dllBridge\Lego\WinMain.h"  
using namespace Lego;



#include   "resource\\Part_1.h"


	 

HPEN      pen =  CreatePen(PS_SOLID,  2, RGB(170, 170, 170));

int         T =  0,
         Help =  0,
	    PausE =  0,
	 TimerFor =  0,	 
 PressBtnOnOf =  2;

Button      btn[4]; 


















///////////////////////////////////////////////////  
void INIT()                                      //
{

	btn[0].Create("Turn on", 200, 490, 70, 25);	                                              // Эл. управления Button
}









///////////////////////////////////////////////////  
void START()                                     //
{  	
	
  if(Help)                                             //  Если включен Help, то отображаем в окне программы подсказку
  {
     if(btn[0].Press())	                              //  Если нажата кнопка "Back to work", возвращаемся к термометру.        
	 {
			
	    returnFromHelp();	
	 }		
  }
  else Base(); 
}

 



///////////////////////////////////////////////////
void  Base()                                     //
{
	
	if(PressBtnOnOf == 1) BurnerFire();	                                               //  Показывать пламя на горелке
		
    ON_OFF();

	if(T > 100)
	{
		
	   if(T == 101) { btn[0].Disable();
			          soundPlay(          "resource\\mus\\Crash.mp3"); 
	                  PictureShow(40, 20, "resource\\img\\Crash.png");  }	
	   
	   if(T  > 120) { T  =  0; 
	   
		  PictureShow(40, 20, "resource\\img\\Thermometer.png");	
		  Transit[0][1] = 2;
		  btn[0].Enable();		                                                                         // PausE = 0;

	   }		
	}
	
	if(PressBtnOnOf == 1)                                                                               //  Если горит
	{
	         	
	   if(PausE < 10) 
	   {  
		  hotStick(PausE);                   //  Текущее состояние датчика пламени (степень нагрева зависит от "Pause")
			       PausE ++;
	   }
	   else            T ++;
    }
    
	if(PressBtnOnOf == 2)                                                              //  Если погасили пламя горелки
	{	
		
	   if(PausE > 0) 
	   {  PausE --;
	      hotStick(PausE);
	   }
	   else if(T > 0) T--;
    }    

    Transit[1][1] = T;
	
    refresh_thermometer();	
}




















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
  if(Help == 0)
  {		
	SelectObject(hdc, pen);
			
	MoveToEx(hdc, 144, 505, NULL); 
	LineTo  (hdc, 198, 505);
	
	PictureShow(40,  20, "resource\\img\\Thermometer.png");
	PictureShow(20, 432, "resource\\img\\Burne1.png");
	
	for(int i = 0; i < 60; i++)  // Рисуем по пикселям датчик пламени. Его состояние соответствует "PausE" (от 0 до 9)
	{
	     
	    SetPixel(hdc, 100+i, 423, RGB( 70+(20*PausE)-i, 50+i*2, 50+i*2)); 
	}	
	
	
    SetTextColor(hdc, RGB( 66, 170, 255));                                               //  Устанавливаем цвет шрифта
	SetBkColor  (hdc, 0);                                                          //  Устанавливаем цвет заднего фона
	if(Transit[1][2]) TextOut(hdc, 174, 415, "Transit [ 1 ] [ 2 ] = 1", 23); 		
	else              TextOut(hdc, 174, 415, "Transit [ 1 ] [ 2 ] = 0", 23); 	
  }
}


//     Эта функция вызывается из оконной процедуры WndProc(), если пользователь выбрал:
// 1)  Какой-либо пункт меню.
// 2)  Нажал кнопку.	

////////////////////////////////////////////////////            
void ScanButtonsAndMenuItems(int item)            //                  
{
	
     if(item == 310)
     {
			
		if(Help) { returnFromHelp(); return; }	

		else 
		{                            //   btn[0].Create("Turn on", 200, 490, 70, 25);
		   Help = 1;
		   
		   
		   
		   btn[0].SetPos(220, 520, 90, 25);	
	       btn[0].Rename("Back to work");
		   InvalidateRect(hWnd, 0, 1);
		   
		   Print_Set_Color(color[4], color[0]);
	       Print_Set_Font (6);
		   
		   Print(120, 25, "Help !");
		   
		   Print_Set_Color(color[7], color[0]);
	       Print_Set_Font(2);		   
		   
		   Print(10,  80, "The number of this program is -949.");
		   Print(10, 100, "You will need it to transfer the parameters and read the");
		   Print(10, 120, "readings of the thermometer and flame sensor.");
		   Print(10, 140, "Control parameters go into variable Transit [ 0 ] [ 1 ]");
		   Print(10, 160, "If you use the function __SET(-949, 1, 1), then the number 1 is");
		   Print(10, 180, "written to the variable Transit[0][1] and the burner is turned on.");
		   Print(10, 200, "If you use the function __SET(-949, 1, 2), then the number 2 is");
		   Print(10, 220, "written to the variable Transit[0][1] and the burner is turned off.");		   
		   
		   Print(10, 240, "Use the function LDIR(-949, 100, 100, 10), to copy 10 array");
		   Print(10, 260, "variables (From element Transit[1][0] to element Transit[1][9])");
		   Print(10, 280, "into the control program.");
		   
		   Print(10, 300, "Thermometer reading in variable     Transit [ 1 ] [ 1 ] = ", Transit[1][1]);
		   Print(10, 320, "Flame sensor readings in variable   Transit [ 1 ] [ 2 ] = ", Transit[1][2]);	
		   
		   Print(10, 360, "You can independently do similar programs with the help of the"); 
		   Print(10, 380, "project \"WinLego\". And send letters with your ideas to the e-mail:");
		   Print(10, 400, "dllbridge@gmail.com");	  		
		}
     }
}
































