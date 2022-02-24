#include <stdio.h>
int length_finder(int n, int length);
int rightrot(int n, int b, int length);
int main() {
    /*
     * Rotates a number to the right by specified bit positions
     */
    int n = 29;         /* The number we want to rotate */
    int b = 2;          /* The bits positions we want to rotate by */
    int length=0;       /* The length of the total bits of n. If you want to rotate by specific
                        *  bit number, e.g 8, change this to 8. */

    length= length_finder(n,length);
    n = rightrot(n, b, length);
    printf("%d", n);
}

int length_finder(n, length)
int n;
int length;
{
    while (n>0){
        n = n>>1;
        length++;
    }
    return length;
}

int rightrot(n, b, length)
int n;
int b;
int length;
{
    while (b > 0){
        if ((n & 001) == 1){                /* if the bit at position 0, is 1*/
            n = n >> 1;                     /* right shift */
            n = n | (001 << (length - 1));  /* and add it to the start*/
            b -= 1;                         /* decrease bit positions needed to rotate */
        }
        else if ((n & 001) == 0){
            n = n >> 1;
            b -= 1;
        }
    }
    return n;
}