#include "sdk_base.h"
#include <ADUC842.H>

uchar USER_CODE[3]; 
uchar CODE_NUM;

uchar SOT;
uchar DES;
uchar ED;

uchar createSymbol(void);
void delay(int len);
void sound(void);


uchar SIM;

uchar POS_ = 0x00;

void main(void)
{
	int i;
	
	while(1) 
	{
		SOT = 0;
		DES = 0;
		ED = 0;
		
		for(i = 0; i < 3; i++) 
		{
			while((CODE_NUM = getkey())== 0xFF); 
			while(getkey() != 0xFF);
			
			USER_CODE[i] = CODE_NUM; 
			svdisp(CODE_NUM); 
			delay(10000); 
			svdisp(0x00); 
		}
		
		while((CODE_NUM = getkey())== 0xFF); 
		while(getkey() != 0xFF);
		
		if (CODE_NUM == 0x0E) 
		{
		  SOT = USER_CODE[0];
		  ED = USER_CODE[1];
		  DES = USER_CODE[2];
			
		 
			SIM = createSymbol();
			
			if(SIM > 128)
			{
				SIM = 76;
			}
			
			lputchar(LCD_POS(POS_),0);
			while(((lgetchar()) & LCD_BF) != 0);
			delay(100);
			lputchar(SIM,1);
			while(((lgetchar()) & LCD_BF) != 0);	
			
			POS_++;
			
			if(POS_ == 0x10)
			{
				POS_ = 0x40;
			}
			else if(POS_ == 0x50)
			{
				POS_ = 0x00;
				sound();
				
				lputchar(LCD_CLR, 0);
				while(((lgetchar()) & LCD_BF) != 0);
			}
		}
	}
}

uchar createSymbol(void)
{
		uchar a;
		uchar b;
		uchar c;
	
		switch (SOT)
		{
			case 0x00:
				a = 1;
				break;
			case 0x01:
				a = 2;
				break;
			case 0x02:
				a = 3;
				break;
			case 0x04:
				a = 4;
				break;
			case 0x05:
				a = 5;
				break;
			case 0x06:
				a = 6;
				break;
			case 0x08:
				a = 7;
				break;
			case 0x09:
				a = 8;
				break;
			case 0x0A:
				a = 9;
				break;
			case 0x0D:
				a = 0;
				break;
		}
		
		switch (ED)
		{
			case 0x00:
				b = 1;
				break;
			case 0x01:
				b = 2;
				break;
			case 0x02:
				b = 3;
				break;
			case 0x04:
				b = 4;
				break;
			case 0x05:
				b = 5;
				break;
			case 0x06:
				b = 6;
				break;
			case 0x08:
				b = 7;
				break;
			case 0x09:
				b = 8;
				break;
			case 0x0A:
				b = 9;
				break;
			case 0x0D:
				b = 0;
				break;
		}
		
		switch (DES)
		{
			case 0x00:
				c = 1;
				break;
			case 0x01:
				c = 2;
				break;
			case 0x02:
				c = 3;
				break;
			case 0x04:
				c = 4;
				break;
			case 0x05:
				c = 5;
				break;
			case 0x06:
				c = 6;
				break;
			case 0x08:
				c = 7;
				break;
			case 0x09:
				c = 8;
				break;
			case 0x0A:
				c = 9;
				break;
			case 0x0D:
				c = 0;
				break;
		}
		
		return 100*a + 10*b + c;
}

void delay(int len)
{
	while(len > 0) len--;
}

void sound(void)
{
		int i;
	
		for(i = 0; i<10; i++) 
		{
			putbyte(0x10, ENA); 
			delay(1000);
			putbyte(0, ENA);
			delay(1000);
		}
}

