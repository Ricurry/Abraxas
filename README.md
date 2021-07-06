## Abraxas.

A free-to-use self-checksum library, written in C/C++.

This is for Linux systems, so Windows users, your out of luck, I'm not making a new one!

### Usage.

To use Abraxas, just download the Resource Files here, plop 'em into your repository.

From there you would include your code with something like:

`#include "Resource Files/iphdr"`

and that'll include all of the libraries you need.

### Features.

Abraxas includes things like multithreaded compression for messages, peer-to-peer verification,

self-checksums, all provided in the library.

For these we will split them into 3 categories,

- IP Header Functions, or functions dealing with the packet.
- Message Functions, or functions handling messages sent and received.
- And Filler Functions, that fill the information for your Ip-header to be used.



We will start with filler functions, and then IP header functions, and message functions last, ranking from most priority to least.



Before we begin though, I will consider you fluent with the basics of packet structure, and decent at creating socket applications in C++. So bear this in mind.

### Filler Functions.

`h_data::HtonData(iphdr* h, char buffer[8]);`

Where `h` is the header needed to retrieve information, and `buffer[8]` is the containing variable for the information you want to send.



This function is used for filling out the message data and formatting it into something the peer can understand, if you just send a message without any purpose or identification, the peer host will then drop the connection, since there is no proper way to verify it.

That's way although initial connections may work between socket-to-socket, nothing will actually happen unless there is a proper  way to verify the messages you are sending.

There isn't really much going on for filler functions, HtonData in particular just converts your message attached to your socket, into a network short, more suited for sending a message.

### IP Header Functions.

Here is one that'll do you a lot of justice, it's a self serving checksum. It's multithreading, and it is able to verify messages sent and received, depending on how you call loopbacks `send` and `recv()`.

The usage goes like this:

`tcp_checksum(iphdr* Iph, char * src, int sck)`

`Iph`

The primary Ip header.

`src`

The message being sent or received.

`sck`

The socket attaching the message.



