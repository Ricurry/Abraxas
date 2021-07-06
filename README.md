# Abraxus.

#### Self Checksum and IP Header Library! Written in C/C++ for the Linux SubSystem.

*NOTE:* *this is in beta stage right now, so wait patiently for more functions!*

Before you continue this, I reccomend if you have not, brush up on C++ Sockets and Iphdr structure,

for starters, I'd reccomend Beej's Guide.

https://beej.us/guide/bgnet/

There are many versions, depending on where you live.

## Documentation:

- Functions
  - IP Headers.
    - `htonData()`
  - Checksums.
    - `tcp_checksum()`
  - Message Based.
    - `encode()`

## Include Path.

To include the iphdr directory, download as ZIP, extract the Resource Files folder, and put it in your directory.

In your main cplusplus file, write this:

``` c++
#include "Resource Files/iphdr"
```

- Save and close.

now you are ready.

## Functions.

Functions will be divided into 3 categories, for documentation purpose;

- IP Headers.
- Checksums.
- And Message Based.

These are all in order from greatest priority to least.

Let's start with IP Header Functions.

*NOTE: There are not many functions as this is in beta, but consider contributing to the repository, DM me on my Discord, you can check it out on my front page.*

## IP Headers.

  ``` c++
void HtonData(iphdr* h, char buffer[8]);
  ```



Convert Buffer Address to network short.

```C++
iphdr * h
```

#### The IP Header containing front packet information.

``` C++
char buffer[8]
```

#### the buffer pointing to the network short address.

### Checksums.

```c++
int tcp_checksum(iphdr * Iph, char * src, int sck);
```

Verifies message using Fletchers_32bit Checksum.



``` C++
iphdr * Iph
```

#### The IP Header containing front packet information.

```c++
char * src
```

#### The buffer containing packet message.

``` C++
int sck
```

#### The Socket tied to that message.



### Message Based.

```c++
char * encode (char * str);
```

Compresses a packet message.



`char * str`

#### String to encode.



With that, you should get a somewhat clear idea of what the functions are for.

Note the compression, and checksum functions are entirely multithreading.



## Liscense 

[GNU Public Liscense](https://github.com/poet5/Abraxas/blob/main/LICENSE)

## Contribution.

Contact me on Discord, those who want to contribute.

I'll need people fluent with C++, and basic knowledge with commands like `nmap` and `curl`.

You can check out my socials [here.](https://github.com/poet5)




