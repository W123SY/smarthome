#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include "device.h"

void setStep(int a, int b, int c, int d){
	digitalWrite(7, a);
	digitalWrite(0, b);
	digitalWrite(2, c);
	digitalWrite(3, d);
}

void stop(){
	setStep(0, 0, 0, 0);
}

void forward(int t, int steps){
	int i;
	for(i = 0; i < steps; i++){
		setStep(1, 0, 0, 0);
		delay(t);
		setStep(0, 1, 0, 0);
		delay(t);
		setStep(0, 0, 1, 0);
		delay(t);
		setStep(0, 0, 0, 1);
		delay(t);
	}
}

void backward(int t, int steps){
	int i;
	for(i = 0; i < steps; i++){
		setStep(0, 0, 0, 1);
		delay(t);
		setStep(0, 0, 1, 0);
		delay(t);
		setStep(0, 1, 0, 0);
		delay(t);
		setStep(1, 0, 0, 0);
		delay(t);
	}
}

void curtainInit(int Pin){
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
}

int curtainOpen(int Pin, int a, int b){
    forward(3,1066);
}

int curtainClose(int Pin){
	backward(3,1066);
}

struct Device curtain = {
    .name = "curtain",
    .status = 0,
    .pin = 7,//单片机引脚
    .open = curtainOpen,
    .close = curtainClose,
    .devInit = curtainInit,
};

struct Device *curtainToDevlink(struct Device *phead)
{
    if (phead == NULL)
    {
        return &curtain;
    }
    else
    {
        curtain.next = phead;
        return &curtain;
    }
};
