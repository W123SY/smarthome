#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include "device.h"

void light1Open(int Pin, int flag, int b){
	if(flag==0){
        digitalWrite(Pin,HIGH);
    }
}

void light1Close(int Pin, int flag){
    if(flag==0){
        digitalWrite(Pin,LOW);
    }
}

void light1Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

void light2Open(int Pin, int flag, int b){
    if(flag==0)
        digitalWrite(Pin,HIGH);
}

void light2Close(int Pin, int flag){
    if(flag==0)
        digitalWrite(Pin,LOW);
}

void light2Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

void light3Open(int Pin, int flag, int b){
    if(flag==0)
        digitalWrite(Pin,HIGH);
}

void light3Close(int Pin, int flag){
	if(flag==0)
        digitalWrite(Pin,LOW);
}

void light3Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

void light4Open(int Pin, int flag, int b){
	if(flag==0)
        digitalWrite(Pin,HIGH);
}

void light4Close(int Pin, int flag){
	if(flag==0)
        digitalWrite(Pin,LOW);
}

void light4Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

void light5Open(int Pin, int flag, int b){
    if(flag==0){
        digitalWrite(Pin,HIGH);
    }
}

void light5Close(int Pin, int flag){
    if(flag==0){
        digitalWrite(Pin,LOW);
    }
}

void light5Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

//创建结构体
struct Device light1 = {
    .name = "light1",
    .status = 0,
    .pin = 21,
    .flag = 0,
    .open = light1Open,
    .close = light1Close,
    .devInit = light1Init,
   // .changStatus = light1changStatus,
    .next = NULL
};

struct Device *light1ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &light1;
    }
    else
    {
        light1.next = phead;
        return &light1;
    }
};

struct Device light2 = {
    .name = "light2",
    .status = 0,
    .pin = 22,
    .flag = 0,
    .open = light2Open,
    .close = light2Close,
    .devInit = light2Init,
   // .changStatus = light1changStatus,
    .next = NULL
};

struct Device *light2ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &light2;
    }
    else
    {
        light2.next = phead;
        return &light2;
    }
};

struct Device light3 = {
    .name = "light3",
    .status = 0,
    .pin = 23,
    .flag = 0,
    .open = light3Open,
    .close = light3Close,
    .devInit = light3Init,
   // .changStatus = light1changStatus,
    .next = NULL
};

struct Device *light3ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &light3;
    }
    else
    {
        light3.next = phead;
        return &light3;
    }
};

struct Device light4 = {
    .name = "light4",
    .status = 0,
    .pin = 24,
    .temp = 0,
    .flag = 0,
    .open = light4Open,
    .close = light4Close,
    .devInit = light4Init,
   // .changStatus = light1changStatus,
    .next = NULL
};

struct Device *light4ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &light4;
    }
    else
    {
        light4.next = phead;
        return &light4;
    }
};

struct Device light5 = {
    .name = "light5",
    .status = 0,
    .pin = 25,
    .flag = 0,
    .open = light5Open,
    .close = light5Close,
    .devInit = light5Init,
   // .changStatus = light1changStatus,
    .next = NULL
};

struct Device *light5ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &light5;
    }
    else
    {
        light5.next = phead;
        return &light5;
    }
};

