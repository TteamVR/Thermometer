



#include       "C:\dllBridge\Lego\WinMain.h"  
using namespace Lego;




extern	 int        T,
                 Help,
                PausE,
         PressBtnOnOf;     // 1 = включено
                           // 2 = ВЫКЛ.

extern   bool     End,
              ON, OFF;

extern  Button btn[4]; 




HPEN      pen_BLK = CreatePen(PS_SOLID, 20, RGB(  0,   0,   0)),
          pen_RED = CreatePen(PS_SOLID, 20, RGB(255,   1,   1));





///////////////////////////////////////////////////  -=-  РИСОВАНИЕ  -=-  ////////////////////////////////////////////

///////////////////////////////////////////////////                       Рисование языков пламени для газовой горелки
void BurnerFire()                                //
{	

     static int last = 0; 

	 int  v;
		
	 do { v = rand() % 7; } while(last == v);

	 switch(v)
	 {
 		case  0: PictureShow(70, 423, "resource\\img\\11.png"); break;
		case  1: PictureShow(70, 425, "resource\\img\\12.png"); break;
		case  2: PictureShow(70, 421, "resource\\img\\13.png"); break;
		case  3: PictureShow(70, 423, "resource\\img\\14.png"); break;	
		case  4: PictureShow(70, 423, "resource\\img\\15.png"); break;
		case  5: PictureShow(70, 423, "resource\\img\\16.png"); break;
		case  6: PictureShow(70, 425, "resource\\img\\17.png");		  		
	 }
	    
	 last = v;		
}







          
///////////////////////////////////////////////////                                Рисует столбик термометра (красным)
void refresh_thermometer()                       //   
{
		
	if(T < 101)
	{
		hdc = GetDC(hWnd);	
		SelectObject(hdc, pen_BLK);			                                        //   Сначала стирает чёрным цветом 
		MoveToEx(hdc, 84, 360, NULL); 
		LineTo(hdc, 84, 320 - T * 2.7);
		 
		SelectObject(hdc, pen_RED);			
		MoveToEx(hdc, 84, 360, NULL); 
		LineTo(hdc, 84, 320 - (T - 1) * 2.7); 
		ReleaseDC(hWnd, hdc);  
	}
}


/////////////////////////////////////////////////// 
void hotStick(int iu)                            //   int x, int y, 
{
	
	 hdc = GetDC(hWnd);
	 
	 for(int i = 0; i < 60; i++)
	 {
	     
	     SetPixel(hdc, 100+i, 423, RGB( 70+(20*iu)-i, 50+i*2, 50+i*2)); 
	 }
	 
	 ReleaseDC(hWnd, hdc);
}





///////////////////////////////////////////////////  -=-  УПРАВЛЕНИЕ -=-  ////////////////////////////////////////////

///////////////////////////////////////////////////                    Опрос сообщений о включении-выключении горелки.
void ON_OFF()                                    //
{
	 
	 if(btn[0].Press())	                            
	 {
			
		if(PressBtnOnOf == 1) Transit[0][1]	= 2;
		else                  Transit[0][1]	= 1;

	 }	 
	 switch(Transit[0][1])
     {
			
	     case  1: soundPlay("resource\\mus\\Click.mp3");	
		          PictureShow(70, 417, "resource\\img\\10.png");  	
		          PressBtnOnOf = 1;                                                                    // 1 = включено    
		          btn[0].Rename("OFF");					        			
			      break;
			      
		 case  2: if(T < 101) { PressBtnOnOf = 2;                                                                        // 2 = ВЫКЛ.
		                        btn[0].Rename("Turn on");	
				                PictureShow(70, 417, "resource\\img\\0.png"); }					
				  break;      
	 }	
 		
	 Transit[0][1] = 0;	 
	 
	 
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	 static int old_dat = 1;
	 
     if(PausE >  5) Transit[1][2] = 1;                                                                  //  Датчик огня
     else           Transit[1][2] = 0;
    
     if(old_dat !=  Transit[1][2])
     {
	    old_dat  =  Transit[1][2];
	   	
	    if(Transit[1][2]) xPrint(174, 415,  "Transit [ 1 ] [ 2 ] = 1");
	    else              xPrint(174, 415,  "Transit [ 1 ] [ 2 ] = 0");    
	 }	 
}











///////////////////////////////////////////////////             Переход от "Help" к основному режиму работы термометра
void returnFromHelp()                            //
{
	
	 Help = 0;
		
	 Print(124, 25, "  ");                                                                            //  Стираем Help
		
	 for(int i = 80; i < 420; i+=20) Print(10,  i, "  ");                                     //  Стереть строки "Help"

	 InvalidateRect(hWnd, 0, 1);	
	 btn[0].SetPos(200, 490, 70, 25);	
	 if(PressBtnOnOf == 1) { btn[0].Rename("OFF");  PausE = 8; }
	 if(PressBtnOnOf == 2)   btn[0].Rename("Turn on");		 	                                       
}












































	     
	    // SetPixel(hdc, x+i, y+120, RGB( 70-i, 50+i*2, 50+i*2)); 
	     
	     //SetPixel(hdc, x+i, y+140, RGB( 70+(20*9)-i, 50+i*2, 50+i*2)); 
	    
//	    if(Transit[1][2]) Print(200, 390,  "Transit [ 1 ] [ 2 ] = 1");
//	    else              Print(200, 390,  "Transit [ 1 ] [ 2 ] = 0");	




















//	static _int8 

		/*
		if(PressBtnOnOf == 1)
		{
			PressBtnOnOf = 2;                                                                             // 2 = ВЫКЛ.      
			btn[0].Rename("Turn on");
		}
		else 
		{			
			PressBtnOnOf = 1;                                                                         // 1 = включено
			soundPlay("mus\\Click.mp3");
			btn[0].Rename("OFF");
		}  */
/*	
	if(Transit[0][1] == 1)		
	{	
	//	if(PausE < 0) 
	//	{			
	//	PausE = 30;
		soundPlay("mus\\Click.mp3");
		PressBtnOnOf++;
		btn[0].Rename("OFF");
		ON = true;
	  //  }
		Transit[0][1] = 0;
	}
	
	if(Transit[0][1] == 2)		
	{	
		
	//	if(PausE < 0) 
	//	{	    
		
	//	PausE = 30;
		PressBtnOnOf++;
		btn[0].Rename("Turn on");
		OFF = true;
	  //  }
		
	}
}

*/






































