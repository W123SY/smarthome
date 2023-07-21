#include "command.h"
#include "device.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

struct Device *pdevHead = NULL;
struct InputCommand *pcmdHead = NULL;

pthread_t th_light;
pthread_t th_sensing;
pthread_t th_invade;
pthread_t th_fire;
pthread_t th_dh11;

void* start_HCSR(void* args);
void* start_sensing(void* args);
void *start_invade();
void *start_fire();
void *start_socket_read(void *psocket);
void *start_socket();
void *start_dh11();

void init()
{
    if (wiringPiSetup() == -1)
    {
        printf("wiring no work\n");
        exit(-1);
    }

    pcmdHead = socketToCmdlink(pcmdHead);
    pdevHead = light1ToDevlink(pdevHead);
    pdevHead = light2ToDevlink(pdevHead);
    pdevHead = light3ToDevlink(pdevHead);
    pdevHead = light4ToDevlink(pdevHead);
    pdevHead = light5ToDevlink(pdevHead);
    pdevHead = curtainToDevlink(pdevHead);
    pdevHead = fireToDevlink(pdevHead);
    pdevHead = beepToDevlink(pdevHead);
    pdevHead = air1ToDevlink(pdevHead);
    pdevHead = air2ToDevlink(pdevHead);
    pdevHead = air3ToDevlink(pdevHead);
    pdevHead = lockToDevlink(pdevHead);
    pdevHead = dh11ToDevlink(pdevHead);

    struct Device *p = pdevHead;
    while (p)
    {
        p->devInit(p->pin);
        p = p->next;
    }
}

struct Device *findDev(char *name)
{
    struct Device *p = pdevHead;
    if(p == NULL)
    {
        return NULL;
    }
    while(p)
    {
        if(!strcmp(p->name,name))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct InputCommand *findCmd(char *name)
{
    struct InputCommand *p = pcmdHead;
    if(p == NULL)
    {
        return NULL;
    }
    while(p)
    {
        if(!strcmp(p->cmdName,name))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void dev(char *cmd)
{
    struct Device *p;

    if(strstr(cmd, "light1"))
    {
        p = findDev("light1");
        if(p->status == 0)
        {
            p->open(p->pin,p->flag,0);
            p->status = 1;
        }
        else
        {
            p->close(p->pin, p->flag);
            p->status = 0;
        }
    }
    else if (strstr(cmd, "light2"))
    {
        p = findDev("light2");
        if(p->status == 0)
        {
            p->open(p->pin,p->flag,0);
            p->status = 1;
        }
        else
        {
            p->close(p->pin, p->flag);
            p->status = 0;
        }
    }
    else if (strstr(cmd, "light3"))
    {
        p = findDev("light3");
        if(p->status == 0)
        {
            p->open(p->pin,p->flag,0);
            p->status = 1;
        }
        else
        {
            p->close(p->pin, p->flag);
            p->status = 0;
        }
    }
    else if (strstr(cmd, "light4"))
    {
        p = findDev("light4");
        if(p->status == 0)
        {
            p->open(p->pin,p->flag,0);
            p->status = 1;
        }
        else
        {
            p->close(p->pin, p->flag);
            p->status = 0;
        }
    }
    else if (strstr(cmd, "light5"))
    {
        p = findDev("light5");
        if(p->status == 0)
        {
            p->open(p->pin,p->flag,0);
            p->status = 1;
        }
        else
        {
            p->close(p->pin,p->flag);
            p->status = 0;
        }
    }
    else if(strstr(cmd, "lightall"))
    {
        p = findDev("light1");
        p->open(p->pin,p->flag,0);
        p->status = 1;
        p = findDev("light2");
        p->open(p->pin,p->flag,0);
        p->status = 1;
        p = findDev("light3");
        p->open(p->pin,p->flag,0);
        p->status = 1;
        p = findDev("light4");
        p->open(p->pin,p->flag,0);
        p->status = 1;
        p = findDev("light5");
        p->open(p->pin,p->flag,0);
        p->status = 1;
    }
    else if (strstr(cmd, "lightnone"))
    {
        p = findDev("light1");
        p->close(p->pin,p->flag);
        p->status = 0;
        p = findDev("light2");
        p->close(p->pin,p->flag);
        p->status = 0;
        p = findDev("light3");
        p->close(p->pin,p->flag);
        p->status = 0;
        p = findDev("light4");
        p->close(p->pin,p->flag);
        p->status = 0;
        p = findDev("light5");
        p->close(p->pin,p->flag);
        p->status = 0;
    }
    else if(strstr(cmd,"light6")) //感应模式
    {
        p = findDev("light5");
        p->flag = 1- p->flag;
        p->status = 0;
        if(p->flag == 1)
            pthread_create(&th_light,NULL,start_HCSR,NULL);
        if(p->flag == 0){
            int res = pthread_cancel(th_light);
            p->close(p->pin,p->flag);
            printf("%d",res);
        }
    }
    else if(strstr(cmd,"lightLightSensing")) //智能模式
    {
        p = findDev("light1");
        p->flag = 1- p->flag;
        p->status = 1;
        p = findDev("light2");
        p->flag = 1- p->flag;
        p->status = 1;
        p = findDev("light3");
        p->flag = 1- p->flag;
        p->status = 1;
        if(p->flag == 1)
            pthread_create(&th_sensing,NULL,start_sensing,NULL);
        if(p->flag == 0){
            int res = pthread_cancel(th_sensing);
            p->open(p->pin,p->flag,0);
            p = findDev("light2");
            p->open(p->pin,p->flag,0);
            p = findDev("light1");
            p->open(p->pin,p->flag,0);
            printf("%d",res);
        }
    }
    else if (strstr(cmd, "lightinvade")){
      p = findDev("light4");
      if(p->temp==0){
          p->temp = 1;
          pthread_create(&th_invade,NULL,start_invade,NULL);
          pthread_detach(&th_invade);
      }
      else{
          p->temp = 0;
          pthread_cancel(&th_invade);
      }
    }
    else if (strstr(cmd, "curtain"))
    {
        p = findDev("curtain");
        if(p->status == 0){
            p->open(p->pin,0,0);
            p->status = 1;
        }
        else if(p->status == 1){
            p->close(0,0);
            p->status = 0;
        }
    }
    else if(strstr(cmd,"air1")){
        p = findDev("air1");
        strtok(cmd," ");
        p->temp=atoi(strtok(NULL," "));
        p->status=atoi(strtok(NULL," "));
        p->speed=atoi(strtok(NULL," "));
        p->flag=atoi(strtok(NULL," "));
        if(p->flag == 1){
            p->open(p->temp,p->speed,p->status);
        }
        else{
            p->close(p->pin,0);
        }
    }
    else if(strstr(cmd,"air2")){
        p = findDev("air2");
        strtok(cmd," ");
        p->temp=atoi(strtok(NULL," "));
        p->status=atoi(strtok(NULL," "));
        p->speed=atoi(strtok(NULL," "));
        p->flag=atoi(strtok(NULL," "));
        if(p->flag == 1){
            p->open(p->temp,p->speed,p->status);
        }
        else{
            p->close(p->pin,0);
        }
    }
    else if(strstr(cmd,"air3")){
        p = findDev("air3");
        strtok(cmd," ");
        p->temp=atoi(strtok(NULL," "));
        p->status=atoi(strtok(NULL," "));
        p->speed=atoi(strtok(NULL," "));
        p->flag=atoi(strtok(NULL," "));
        if(p->flag == 1){
            p->open(p->temp,p->speed,p->status);
        }
        else{
            p->close(p->pin,0);
        }
    }
    else if (strstr(cmd, "lock"))
    {
        p = findDev("lock");
        if(p->status == 1)
        {
            p->open(p->pin,0,0);
            p->status = 0;
        }
        else
        {
            p->close(p->pin,0);
            p->status = 1;
        }
    }
}

void *start_socket_read(void *psocket)
{
    int n_read;
    while (1)
    {
        n_read = ((struct InputCommand *)psocket)->getCmd((struct InputCommand *)psocket);
        if (n_read == -1)
        {
            perror("read error");
            exit(-1);
        }
        else if (n_read > 0)
        {

                printf("get cmd:%s\n", ((struct InputCommand *)psocket)->cmd);
                dev(((struct InputCommand *)psocket)->cmd);
        }
    }
}

void *start_fire()
{
    char buff[1024];
    char type[32];
    struct Device *p = NULL;
    struct Device *q = NULL;
    struct InputCommand *psocket = findCmd("socket");
    int ret;
    psocket->c_fd = psocket->init(NULL, psocket->ipAdress, psocket->port);
    sprintf(buff,"fire");
    sprintf(type,"fire");
    send(((struct InputCommand *)psocket)->c_fd,type,sizeof(buff),0);
    p = findDev("fire");
    q = findDev("beep");
    while (1)
    {
        p->devInit(p->pin);
        ret = p->read(p->pin);
        if (ret == 0)
        {   
            printf("fire!\n");
            q->open(q->pin,0,0);
            send(((struct InputCommand *)psocket)->c_fd,buff,sizeof(buff),0);
            delay(1000);	
        }
        if(ret == 1)
        {
            q->close(q->pin,0);
        }
    }
}

void* start_HCSR(void* args)
{
    while(1){
      if(digitalRead(1) == 1){
          digitalWrite(25,HIGH);
      }
      else
          digitalWrite(25,LOW);
      sleep(3);
    }
}

void* start_sensing(void* args)
{
    while(1){
      if(digitalRead(6) == 1){
          digitalWrite(21,HIGH);
          digitalWrite(22,HIGH);
          digitalWrite(23,HIGH);
      }
      else{
          digitalWrite(21,LOW);
          digitalWrite(22,LOW);
          digitalWrite(23,LOW);
      }
      sleep(3);
    }
}

void *start_invade()
{
    char buff[1024];
    char type[32];
    struct InputCommand *psocket = findCmd("socket");
    int ret;
    psocket->c_fd = psocket->init(NULL, psocket->ipAdress, psocket->port);
    sprintf(buff,"invader");
    sprintf(type,"invade");
    send(((struct InputCommand *)psocket)->c_fd,type,sizeof(type),0);
    while (1)
    {
        pinMode(30,INPUT);
        ret = digitalRead(30);
        if (ret == 0)
        {   
            printf("invader\n");
            send(((struct InputCommand *)psocket)->c_fd,buff,sizeof(buff),0);
            delay(1000);	
        }
    }
}

void *start_dh11()
{
    char type[32];
    sprintf(type,"dht11");
    struct Device *p = NULL;
    struct InputCommand *psocket = findCmd("socket");
    psocket->c_fd = psocket->init(NULL, psocket->ipAdress, psocket->port);
    p = findDev("dh11");
    send(((struct InputCommand *)psocket)->c_fd,type,sizeof(type),0);
    while(1){
        pinMode(p->pin,OUTPUT); // set mode to output
        digitalWrite(p->pin,HIGH); // output a high level */
        delay(3000);
        if (p->readData(p->pin, &(p->data)))
        {
           
            printf("RH:%d.%d%\n", (p->data >> 24) & 0xff, (p->data >> 16) & 0xff);
            printf("TMP:%d.%dC\n", (p->data >> 8) & 0xff, p->data & 0xff);
            send(((struct InputCommand *)psocket)->c_fd, (void *)&(p->data), sizeof(p->data),0);
            p->data = 0;
        }
        else
        {
            printf("Sensor dosent ans!\n");
            p->data = 0;
        }
        sleep(20);
    }
}

void *start_voice()
{
    int n_read;
    struct InputCommand *pvoice = findCmd("voice");
    if (pvoice == NULL)
    {
        printf("no found voice!\n");
        pthread_exit(NULL);
    }

    pvoice->fd = pvoice->init(pvoice->devName, NULL, NULL);

    while (1)
    {
        n_read = pvoice->getCmd(pvoice);
        if (n_read == 0)
        {
            printf("say cmd...\n");
        }
        else if (n_read > 0)
        {
            printf("cmd:%s\n", pvoice->cmd);
            dev(pvoice->cmd);
        }
        else if (n_read == -1)
        {
            perror("read error");
            exit(-1);
        }
    }
}

void *start_socket()
{
    int n_read;
    pthread_t th_socket_read;
    struct InputCommand *psocket = findCmd("socket");
    if (psocket == NULL)
    {
        printf("no found socketserver!\n");
        pthread_exit(NULL);
    }
    psocket->c_fd = psocket->init(NULL, psocket->ipAdress, psocket->port);
    while (1)
    {
        pthread_create(&th_socket_read, NULL, start_socket_read, (void *)psocket);
    }
}

int main()
{
   
    init();
    
    pthread_create(&th_dh11, NULL, start_dh11, NULL);
    pthread_create(&th_fire, NULL, start_fire, NULL);

    pthread_detach(th_dh11);
    pthread_detach(th_fire);
    
    
    int c_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(c_fd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(12345);
    inet_pton(AF_INET,"114.116.248.29", &saddr.sin_addr.s_addr);
    int ret = connect(c_fd,(struct sockaddr*)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("connect");
        return -1;
    }
    char type[32];
    sprintf(type,"control");
    send(c_fd, type, sizeof(type), 0);
    while(1)
    {
            char buff[1024];
            memset(buff,0,sizeof(buff));
            int len = recv(c_fd, buff, sizeof(buff), 0);
            if(len>0)
            {
                    printf("server say:%s\n", buff);
                    dev(buff);
            }
            else if(len<0)
            {
                    perror("recv");
                    break;
            }
    }
    close(c_fd);

    return 0;
}
