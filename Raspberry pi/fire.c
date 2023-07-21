#include "device.h"

int fireRead(int pin)
{
    return digitalRead(pin);
}

int fireInit(int pin)
{
    pinMode(pin, INPUT);
    digitalWrite(pin, HIGH);
}

struct Device fire = {
    .name = "fire",
    .pin = 5,
    .read = fireRead,
    .devInit = fireInit,
    .next = NULL
    };

struct Device *fireToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &fire;
    }
    else
    {
        fire.next = phead;
        return &fire;
    }
};
