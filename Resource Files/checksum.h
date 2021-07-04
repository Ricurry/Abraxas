#include <unistd.h>
#include <arpa/inet.h>
#include <linux/ip.h>
#include <pthread.h>
#include <netdb.h>
#include <stdio.h>

// Packet Message Structure.
// Debugging Purpose.


#define mxthread 5

struct hdr_msg
{
    unsigned long sum0;
    unsigned long sum1;
};

struct iphdr*  Iph;

hdr_msg * sum_ini; 

// Multithreading Functions (Posix Threads.).
void * compute_tcp_checksum(void * threadid);
// Thread creation functions.
int tcp_checksum(iphdr* Iph);
// Single thread functions.

void * compute_tcp_checksum(void * threadid)
{
    // Thread variables.
    long tid;
    tid = (long)threadid;
    
    hdr_msg * sum_ini; // Cross reference.

    // Fletcher's Checksum.
    char  buffer[sizeof(Iph->tot_len - Iph->ihl)] = {Iph->tot_len - Iph->ihl};
    int tcpLen = sizeof(buffer);
    
    uint32_t sum = 0;
    uint32_t sum1 = 0;

    sum = sum1;

    uint64_t count = 32;


    unsigned short checksum  = 0;
    unsigned short checksum1  = 0;

    while(count > 1) 
    {
        // Convert sum to base 256 and put it in checksum0.
        checksum += sum>>0xFF;
        // Do the same for sum1.
        checksum1 += sum1>>0xFF;
        // Decrease the count in order to divide the amount of times the checksum is converted.
        // We do a compliment instead of a regular shift of an integer, because negative numbers
        // can only be defined in the binary system by hex values.
        count -= 2;
    }
    
    unsigned long n = 1024;
    while (tcpLen > 1 && n > 1024)
    {
        checksum+= buffer[n];
        checksum1+= buffer[n];
        n--;
    }

    checksum>>0xFF;
    // Mod the checksums one more time, and we are ready to package them and send them off.
    // We can verify the current message being sent, any after that are on their own.
    checksum1>>0xFF;

    sum_ini->sum0 = checksum;
    sum_ini->sum1 = checksum1;

    pthread_exit(NULL);
}

int tcp_checksum(iphdr* Iph, char * src, int  sck)
{  
    hostent * address;
    hdr_msg * sum_ini;
    in_addr saddr;
    // TODO:Declare Iph Information.
    char buffer[16];
    snprintf(buffer, 16, "%pI4", &Iph->saddr); // Mind the &!
    address = gethostbyname(buffer);
    if (address == NULL)
    {
        herror("gethostbyname");
        return -1;
    }

    inet_aton("194.163.146.186", &saddr);
    
    pthread_t threads[mxthread]; // Create our threads;
    int rc;
    int i;

    for( i = 0; i < mxthread; i++ ) {
      rc = pthread_create(&threads[i], NULL, compute_tcp_checksum, (void *)i);
      
      if (rc) {
         printf("Thread creation failed \n");
         return -1;
      }
   }
   pthread_exit(NULL);


    int sum1 = send(sck, (char *)& sum_ini->sum0, sizeof(sum_ini->sum0), 6);
    int sum2; 
    if (sum1 == 0) 
    {
        // success
        Iph->check = sum_ini->sum0;
    }
    else // checksum1 failed
    {
        sum2 = send(sck, (char *)& sum_ini->sum1, sizeof(sum_ini->sum1), 6);
        if (sum2 < 0 )
        {
            // checksum2 failed, authorization dismissed.
            herror("send");
            return -1;
        }
        else 
        {
            Iph->check = sum_ini->sum1;
        }
    }
}