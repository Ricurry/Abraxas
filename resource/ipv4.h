
#include <arpa/inet.h>
#include <string.h>

#define mxthread 5
#define BUFSIZE 65535
//#define vn_bit 0x04
//#define maxthread 5

// function header params.

// function return value.
struct ihl_data 
{
    unsigned char buffer[32];
};

class h_data /* header data.*/
{

    public:

    h_data(iphdr* data);

    void HtonData(iphdr* h, char buffer[8]); // int socket, unsigned long length, char buffer[16]
    void HtonIHL(void * threadid); // socks4_header, int socket.
};

/** IP STRUCTURE TODO:
 *  IHL, took care of it, top header done.
 * TOS,
 *  Length,
 *  Identification,
 *  Flags, took care of it, only needed to create server socket with protocol.
 *  Fragment Offset, gonna take it off because im lazy as shit.
 *  TTL, inprogress
 *  Protocol, done.
 // TAKEDOWN LATER: Working on protocol currently, for client socket will use IP_DIVERT to redirect traffic from one computer to another.
 *  Checksum, check.
 *  src/dst address, inprogress.
 * */ 

/** IHL:
 * Convert low byte order of ihl_data buffer.
 * Htons to dstip using dstport.
 * NOTE: IHL Has been taken care of using the hton_data function.
 * to piss off my friends i sent a version of this program with a shit ton of packet space.
 * don't get me wrong i love them though.
 * NOTE: Original htons port should be set to 0 for randomization.
 * Set ID to be socks4_header->cd command reply code. To signify that it is from local machine.
 * Create function to randomize cd reply code. such as an iterator to see how many messages it has sent in response.
 * Get flags number from the socket, declare it as  an unsigned int.
 * For the checksum however, we need to make our own function.
 * CHECKSUM:
 * To create our checksum, we need to do these steps.
 * Add the source IP and shift it by 16 bytes, using >>, shift it to the default checksum value 0xFFFF,
 * */
 // EDITOR NOTE: Checksum has been created in checksum.h, using fletchers checksum as a template.
 // if you don't know what that means google it. it sounds like a bunch of buzz shit, thats what i thought too.

h_data::h_data(iphdr * data) // Constructor Class.
{
 /* TODO: 
 Find way to specify Iphdr data.*/
 // EDITOR NOTE: As of today I'll get to defining this, just got home from my flight.
 // but I've been procrastinating on this alot so I will probably get to it.
}






void h_data::HtonData(iphdr* h, char buffer[BUFSIZE]) 
{
    uint16_t u16;
    memcpy(buffer+0, &u16, 2);
    // Convert msg buffer of IP Header in to network short.
    u16 = htons(h->tot_len - h->ihl);
}