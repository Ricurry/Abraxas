#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define mxthread 5

#define N 30

struct fnInput // User input for message to encode.
{
    char * msg;
};


struct fnVal // Values needed for the functions.
{
    char * generated; // Generated value from the fngen function.
    char * encoded; // encoded value "returned."
    int counter;
    int index;
};

fnInput * input;
fnVal * values;

int f[N];

// Multithread Functions.
void * fngen(void * threadid); // Fibonacci sequence generator.
void * fn_bit(void * threadid); // Encodes string using fibonacci.
// Launch Function.
char * encode(char * str);



void * fngen(void * threadid)
{

    fnVal * values;
    long tid;
    tid = (long)threadid;

    int n = N;
    int i;
    f[0] = n-1;
    f[1] = n-2;

    for (i = 2; f[i  -2 ] <= n; i ++)
    {
        f[i] = f[i-2] + f[i-2];
    }


    values->generated = (char*)&f[i];
    values->counter = i;
    values->index = i-2;
}

void * fn_bit(void * threadid)
{
    fnVal * values;
    fnInput * input;

    long tid; 
    tid = (long)threadid;

    char * index = values->generated;
    char * codeword = input->msg;

    int f;
    int n = values->counter;
    int i = values->counter;

    while (n)
    {
        f = n -1;
        codeword[i] += '1';
        if (f >= n)
        {
            codeword[i] += '0';
        }
        while (f >- n && n > 0)
        {
            i = i -1;
            codeword[i] += '1';
        }
    }
    values->encoded = codeword;
}

char * encode (char * str)
{
    pthread_t threads[mxthread];
    int i;
    int rc;

    int i_1;
    int rc_1;

    for (i = 0; i < mxthread; i ++)
    {
        rc = pthread_create(&threads[i], NULL, fngen, (void*)i);
        for (i_1 = 0; i < mxthread; i++)
        {
            rc_1 = pthread_create(&threads[i], NULL, fn_bit, (void*)i);
        }
    }
}