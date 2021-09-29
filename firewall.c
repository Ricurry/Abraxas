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

#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/if.h>
#include <sys/param.h>

#include <linux/types.h>
#include <linux/icmp.h>


#include "resource/iphdr"


// FIREWALL Preprocessor definitive.

// setsockopt pointer.
char * opt;

struct handle {
    int signo;
};

#ifdef FIREWALL

// firewall preprocessor definitives.
char *fw_policy="DIVERT";
char *fw_chain="output";
struct ip_fw fw;
struct ip_fwuser ipfu;
struct ip_fwchange ipfc;
int fw_sock;


// signal handler.
void intHandler (void * threadid) {
  handle * signal;
  long tid;
  tid = (long)threadid;
  int signo = signal->signo;
  if (setsockopt(fw_sock, IPPROTO_IP, IP_FW_DELETE, &ipfc, sizeof(ipfc))==-1) {
    fprintf(stderr, "%s: could not remove rule: %s\n", progname, strerror(errno));
    exit(2);
  }

  close(fw_sock);
  exit(0);
}
#endif

int ret;

#define maxconn 5

int main ( int argc, char ** argv)  
{
    int fw_sock = socket(AF_INET, SOCK_RAW, IPPROTO_RSVP);

    // set information for divert packet.

    struct sockaddr_in netstats;

    netstats.sin_port = htons(445);
    netstats.sin_family = AF_INET;
    netstats.sin_addr.s_addr = 0;
    socklen_t netsize;

}
// firewall preprocessor
#ifdef FIREWALL 
    bzero(&fw, sizeof(struct ip_fw));
    fw.fw_proto=1; // internet command management protocol. iow. cmd shell
    fw.fw_redirpt=htons()
#endif