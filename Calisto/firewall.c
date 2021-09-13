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
#include <linux/ip_fw.h>

#include "resource/iphdr"


// PLEASE NOTE: THIS IS THE LAST DAY AND I HAVE NO IDEA WHAT IM DOING.
// I WILL PROBABLY MAKE ANOTHER TEST BUT IF NOT THEN I WILL GO CRY MYSELF TO SLEEP.
// FIREWALL Preprocessor definitive.

// setsockopt pointer.
char * opt;

struct handle {
    int signo;
}


#ifdef FIREWALL


char *fw_policy="DIVERT";
char *fw_chain="output";
struct ip_fw fw;
struct ip_fwuser ipfu;
struct ip_fwchange ipfc;
int fw_sock;
// OUTDATED COMMENT START:
// Copied and pasted from previous examples due to having no internet.
// gonna come up with a multithreaded solution later.

// function down below is signal handler.
// END:
// Reason this is outdated is because I already made a multithread solution ; )
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


int ret;

#define maxconn 5

int main ( int argc, char ** argv)  
{
    fw_sock = socket(AF_INET, SOCK_RAW, IPPROTO_DIVERT);

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