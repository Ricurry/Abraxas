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

#define xprthread 5
#define IP_DIVERT 254
#define PACKETBUF 65535
// Declare classes.

struct netinfo {
    char * sum;
    iphdr* check;
    char * src;
    int socket;
};



class netlink  {
    //void auth (char * sum, iphdr* check, char * src);
    void auth(void * threadid);
};

void netlink::auth(void * threadid) 
{
    netinfo * netset;

    struct sockaddr_in srcinfo, sin;
    int sinlen;
    char packet[PACKETBUF];

    // set sum.
    iphdr* check = netset->check;
    char * sum = netset->sum;
    char * srcaddr = netset->src;
    int socket =netset->socket;
}