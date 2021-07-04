#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
    void HtonData(void * threadid); // int socket, unsigned long length, char buffer[16]
    void HtonIHL(void * threadid); // socks4_header, int socket.

};

/** IP STRUCTURE TODO:
 *  IHL, 
 * TOS,
 *  Length,
 *  Identification,
 *  Flags,
 *  Fragment Offset,
 *  TTL,
 *  Protocol,
 *  Checksum, check.
 *  src/dst address, inprogress.
 * */ 


/** IHL:
 * Convert low byte order of ihl_data buffer.
 * Htons to dstip using dstport.
 * NOTE: Original htons port should be set to 0 for randomization.
 * Set ID to be socks4_header->cd command reply code. To signify that it is from local machine.
 * Create function to randomize cd reply code. such as an iterator to see how many messages it has sent in response.
 * Get flags number from the socket, declare it as  an unsigned int.
 * For the checksum however, we need to make our own function.
 * CHECKSUM:
 * To create our checksum, we need to do these steps.
 * Add the source IP and shift it by 16 bytes, using >>, shift it to the default checksum value 0xFFFF,
 * */
