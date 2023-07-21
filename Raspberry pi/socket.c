#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int socketInit(char *name, char *ip, char *port)
{
    int c_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (c_fd == -1)
    {
        perror("socket error");
        exit(-1);
    }

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &s_addr.sin_addr);
    //bind(s_fd, (struct sockaddr *)&s_addr, sizeof(s_addr));//套接字地址绑定

    //listen(s_fd, 10);//监听
    int ret = connect(c_fd,(struct sockaddr*)&s_addr, sizeof(s_addr));
    if(ret == -1)
    {
            perror("connect");
            return -1;
    }
    return c_fd;
}

int socketGetcmd(struct InputCommand *socket)
{
    memset(socket->cmd, 0, strlen(socket->cmd));
    return recv(socket->c_fd, socket->cmd, sizeof(socket->cmd), 0);//套接字描述符，数据接收缓冲区，读取数据字节大小
}

struct InputCommand Socket =
    {
        .cmdName = "socket",//命令名
        .cmd = {'\0'},//命令字符串
        .ipAdress = "114.116.248.29",//服务器
        .port = "12345",//服务器
        //.s_fd = -1,//服务器套接字描述符
        .c_fd = -1,//客户端套接字描述符
        .init = socketInit,//初始化
        .getCmd = socketGetcmd,//命令获取
        .log = {'\0'},
        .next = NULL};

struct InputCommand *socketToCmdlink(struct InputCommand *phead)
{
    if (phead == NULL)
    {
        return &Socket;
    }
    else
    {
        Socket.next = phead;
        return &Socket;
    }
};
