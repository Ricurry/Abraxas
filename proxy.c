#include "resource/iphdr"

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <signal.h>

#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/if.h>
#include <sys/param.h>

#include <linux/types.h>
#include <linux/icmp.h>
#include <netinet/tcp.h>


#define msg_size 8096

int signal_handle (int client, struct sockaddr_in network) 
{
    int remote = socket(AF_INET, SOCK_STREAM, 0);

    int bind_local  = bind(client, (sockaddr*)&network, sizeof(network));

    if (bind_local < 0) 
    {
        exit(-1);
    }

}


int read_message (char *msg, int client, sockaddr_in remote) 
{
    char buffer[msg_size];

    int read_result = read(client, buffer, sizeof(buffer)-1);

    while (read_result > 0) 
    {
        buffer[read_result] = 0x00;
    }

    int bind_remote = bind(read_result, (sockaddr*)&remote, sizeof(remote));
    if (bind_remote < 0) 
    {
        exit(-1);
    }

    return bind_remote;
}

int read_remote(char * msg, int remote, sockaddr_in local) 
{
    char buffer[msg_size];

    int read_result = read(remote, buffer, sizeof(buffer)-1);

    while (read_result > 0) 
    {
        buffer[read_result] = 0x00;
    }

    int local_remote = bind(read_result, (sockaddr*)&remote, sizeof(remote));
    if (local_remote < 0) 
    {
        exit(-1);
    }

    return local_remote;
}

char  * sent[msg_size];
char * received[msg_size];

int acceptor(int reading, struct sockaddr_in remote)  
{
    socklen_t setsize = sizeof(remote);
     int fd = accept(reading, (sockaddr*)&remote, (socklen_t*)&setsize);
     if (fd < 0 ) 
     {
         exit(-1);
     }
}

int intitialize(int fd, sockaddr_in remote) 
{
    int conn = connect(fd, (sockaddr*)&remote, sizeof(remote));
} 