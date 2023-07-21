#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include "device.h"
#include "oled.h"

void fan1Open(int Pin){
	digitalWrite(Pin,LOW);
}

void fan1Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void fan1Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void heater1Open(int Pin){
	digitalWrite(Pin,LOW);
}

void heater1Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void heater1Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void heater2Open(int Pin){
	digitalWrite(Pin,LOW);
}

void heater2Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void heater2Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void heater3Open(int Pin){
	digitalWrite(Pin,LOW);
}

void heater3Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void heater3Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void fan2Open(int Pin){
	digitalWrite(Pin,LOW);
}

void fan2Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void fan2Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void fan3Open(int Pin){
	digitalWrite(Pin,LOW);
}

void fan3Close(int Pin){
	digitalWrite(Pin,HIGH);
}

void fan3Init(int Pin){
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,HIGH);
}

void air1Open(int d, int e, int f){
    if(f == 1||3)
	fan1Open(28);
	heater1Close(12);
    if(f == 2)
	fan1Close(28);
	heater1Open(12);
    OLED_Open1(d, e, f);
}

void air1Init(int Pin){
    oled_init();
    OLED_Clear();
    OLED_Open_Init();
    fan1Init(Pin);
    heater1Init(12);
}

void air1Close(int Pin,int heater){
    fan1Close(Pin);
    heater1Close(12);
    OLED_Clear1();
}

void air2Open(int a, int b, int c){
    if(c == 1||3)
	fan2Open(27);
	heater2Close(13);
    if(c == 2)
	fan2Close(27);
	heater2Open(13);
    OLED_Open2(a, b, c);
}

void air2Init(int pin){
    fan2Init(pin);
    heater2Init(13);
}

void air2Close(int pin, int heater){
    fan2Close(pin);
    heater2Close(13);
    OLED_Clear2();
}

void air3Open(int a, int b, int c){
    if(c == 1||3)
	fan3Open(26);
	heater3Close(14);
    if(c == 2)
	fan3Close(26);
	heater3Open(14);
    OLED_Open3(a, b, c);
}

void air3Init(int pin){
    fan3Init(pin);
    heater3Init(14);
}

void air3Close(int pin,int heater){
    fan3Close(pin);
    heater3Close(14);
    OLED_Clear3();
}

struct Device air1 = {
    .name = "air1",
    .status = 1,
    .pin = 28,
    .temp = 25,
    .speed = 2,
    .flag = 1,
    .open = air1Open,
    .close = air1Close,
    .devInit = air1Init,
    .next = NULL};

struct Device *air1ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &air1;
    }
    else
    {
        air1.next = phead;
        return &air1;
    }
};

struct Device air2 = {
    .name = "air2",
    .status = 1,
    .pin = 27,
    .temp = 25,
    .speed = 2,
    .flag = 1,
    .open = air2Open,
    .close = air2Close,
    //.change = air2Change,
    .devInit = air2Init,
    .next = NULL};

struct Device *air2ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &air2;
    }
    else
    {
        air2.next = phead;
        return &air2;
    }
};

struct Device air3 = {
    .name = "air3",
    .status = 1,
    .pin = 26,
    .temp = 25,
    .speed = 2,
    .flag = 1,
    .open = air3Open,
    .close = air3Close,
    //.change = air1Change,
    .devInit = air3Init,
    .next = NULL};

struct Device *air3ToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &air3;
    }
    else
    {
        air3.next = phead;
        return &air3;
    }
};
