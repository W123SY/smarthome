#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include "device.h"

void lockOpen(int Pin, int a, int b){
	digitalWrite(Pin,HIGH);
}

void lockClose(int Pin){
	digitalWrite(Pin,LOW);
}

void lockInit(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,LOW);
}

struct Device lock = {
    .name = "lock",
    .status = 1,
    .pin = 29,
    .open = lockOpen,
    .close = lockClose,
    .devInit = lockInit,
};

struct Device *lockToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &lock;
    }
    else
    {
        lock.next = phead;
        return &lock;
    }
};
