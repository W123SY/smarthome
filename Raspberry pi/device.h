#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

struct Device
{
    char name[128];//设备名
    int status;//模式
    int pin;//引脚
    int temp;
    int speed;
    int flag;
    unsigned long data;
    int (*open)(int pin, int a,int b);
    int (*close)(int pin, int flag);
    int (*read)(int pin);
    unsigned char (*readData)(int pin,unsigned long *data);
    //void change (char temp,char speed,char mode);
    int (*devInit)(int pin);
    //int (*changStatus)();
    struct Device *next;
};


struct Device *lockToDevlink(struct Device *phead);
struct Device *light1ToDevlink(struct Device *phead);
struct Device *light2ToDevlink(struct Device *phead);
struct Device *light3ToDevlink(struct Device *phead);
struct Device *light4ToDevlink(struct Device *phead);
struct Device *light5ToDevlink(struct Device *phead);
struct Device *air1ToDevlink(struct Device *phead);
struct Device *air2ToDevlink(struct Device *phead);
struct Device *air3ToDevlink(struct Device *phead);
struct Device *dh11ToDevlink(struct Device *phead);
struct Device *curtainToDevlink(struct Device *phead);
struct Device *beepToDevlink(struct Device *phead);
struct Device *fireToDevlink(struct Device *phead);




#endif // DEVICE_H_INCLUDED
