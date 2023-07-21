#include "device.h"


unsigned char dh11Read(int pin,unsigned long *data)
{
    unsigned char crc; 
    unsigned char i;
 
    pinMode(pin,OUTPUT); // set mode to output
    digitalWrite(pin, 0); // output a high level 
    delay(25);
    digitalWrite(pin, 1); // output a low level 
    pinMode(pin, INPUT); // set mode to input
    pullUpDnControl(pin,PUD_UP);
 
    delayMicroseconds(27);
    if(digitalRead(pin)==0) //SENSOR ANS
    {
        while(!digitalRead(pin)); //wait to high
        for(i=0;i<32;i++)
        {
            while(digitalRead(pin)); //data clock start
            while(!digitalRead(pin)); //data start
                delayMicroseconds(32);
	        (*data) *= 2;
            if(digitalRead(pin)==1) //1
            {
                (*data)++;
            }
        }
 
        for(i=0;i<8;i++)
        {
            while(digitalRead(pin)); //data clock start
            while(!digitalRead(pin)); //data start
                delayMicroseconds(32);
            crc*=2;  
            if(digitalRead(pin)==1) //1
            {
                crc++;
            }
        }
        return 1;
    }
   else
    {
        return 0;
    }
}




int dh11Init(int pin)
{
    pinMode(pin, OUTPUT); //起始拉高电平
	digitalWrite(pin, 1); 
	delay(1000);			
	
	pinMode(pin, OUTPUT);  //拉低超过18ms
	digitalWrite(pin, 0);
	delay(21);
	
	digitalWrite(pin, 1); //拉高电平，等响应
	pinMode(pin,INPUT);
	delayMicroseconds(28);
}

struct Device dh11 = {
    .name = "dh11",
    .data = 0,
    .pin = 10,
    .readData = dh11Read,
    .devInit = dh11Init,
    .next = NULL};

struct Device *dh11ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &dh11;
    }
    else
    {
        dh11.next = phead;
        return &dh11;
    }
};
