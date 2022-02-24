#include <stdio.h>
unsigned wordlength(unsigned x, int n);
int main() {
    /* Calculates bits in an int of the host machine*/
    unsigned x = 001;               /* The first bit location */
    int n = 1;                      /*  Bit count */
    n = wordlength(x, n);
    printf("%d bits", n);
    return 0;
}

unsigned wordlength(x, n)
unsigned x;
int n;
{
    while (x!=EOF) {
        x = (x << 1) | 001;
        n += 1;
    }
    return n;
}