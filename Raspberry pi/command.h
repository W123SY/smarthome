#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

struct InputCommand
{
    char cmdName[128];//命令名
    char cmd[32];//命令
    char devName[128];//设备名
    int fd;//套接字，设备
    //int s_fd;//服务端套接字
    int c_fd;//客户端套接字
    char ipAdress[32];//服务器ip地址
    char port[16];//服务器端口号
    int (*init)(char *name, char *ipAdress, char *port);//初始化
    int (*getCmd)(struct InputCommand *cmd);//获取命令
    char log[1024];
    struct InputCommand *next;//指向下一个
};

struct InputCommand *voiceToCmdlink(struct InputCommand *phead);
struct InputCommand *socketToCmdlink(struct InputCommand *phead);//将套接字加入链表


#endif // COMMAND_H_INCLUDED
