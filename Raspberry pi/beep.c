#include "device.h"

int beepOpen(int pin)
{
    digitalWrite(pin,LOW);
}

int beepClose(int pin)
{
    digitalWrite(pin,HIGH);
}

int beepInit(int pin)
{
    pinMode(pin,OUTPUT); 
    digitalWrite(pin,HIGH);
}



struct Device beep = {
    .name = "beep",
    .pin = 4,
    .open = beepOpen,
    .close = beepClose,
    .devInit = beepInit,
};

struct Device *beepToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &beep;
    }
    else
    {
        beep.next = phead;
        return &beep;
    }
};
