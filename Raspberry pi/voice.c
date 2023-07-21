#include "command.h"

int voiceInit(char *name, char *ipAdress, char *port)
{
    int fd = serialOpen(name, 9600);
    if (fd == -1)
    {
        printf("serial down\n");
        exit(-1);
    }
    return fd;
}

int voiceGetcmd(struct InputCommand *voice)
{
    memset(voice->cmd, 0, strlen(voice->cmd));
    return read(voice->fd, voice->cmd, sizeof(voice->cmd));
}

struct InputCommand voice =
    {
        .cmdName = "voice",
        .cmd = {'\0'},
        .devName = "/dev/ttyAMA0",
        .fd = -1,
        .init = voiceInit,
        .getCmd = voiceGetcmd,
        .log = {'\0'},
        .next = NULL};

struct InputCommand *voiceToCmdlink(struct InputCommand *phead)
{
    if (phead == NULL)
    {
        return &voice;
    }
    else
    {
        voice.next = phead;
        return &voice;
    }
};
