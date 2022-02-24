#include <stdio.h>

int bitcount(int n, int b);

int main() {
    int n = 037;    /* number that we want to find bits from */
    int b = 0;      /* number of bits in n */

    b = bitcount(n, b);
    printf("Total 1 bits: %d", b);
}

int bitcount(n, b) /* counts 1 bits in n*/
int n;
int b;
{
    while(n != 0){
        n &= n-1;   /* deletes right most 1 bit in n */
        b++;
    }
    return b;
}