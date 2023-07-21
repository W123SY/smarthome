#ifndef __OLED_H
#define __OLED_H

#define u8 unsigned char
#define u32 unsigned int
 
#define SlaveAddress 0x3C  //OLED地址
#define OLED_CMD  0x00  //OLED写命令
#define OLED_DATA 0x40  //OLED写数据
#define SIZE 		16		//字符大小
#define Max_Column	128		//最大列数

void OLED_Set_Pos(u8 x, u8 y);
void OLED_Clear(void);
void OLED_Display_On(void);
void OLED_Display_Off(void);
int oled_init(void);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowAir(u8 x,u8 y,int chr);
void OLED_ShowNumber(u8 x,u8 y,int no);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1);
void OLED_ShowString(u8 x,u8 y,const u8 *chr);
int OLED_Open1(int mode, int speed, int temp);
int OLED_Open2(int mode, int speed, int temp);
int OLED_Open3(int mode, int speed, int temp);
int OLED_Open_Init(void);
void OLED_Clear1(void);
void OLED_Clear2(void);
void OLED_Clear3(void);
#endif
