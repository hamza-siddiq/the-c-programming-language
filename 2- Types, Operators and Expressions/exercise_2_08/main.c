#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);
int main() {
    /*
     * Inverts the n bits of x that begin at position p
     */
    unsigned x = 0157;  /* number we want to change */
    unsigned p = 5;     /* the position we want to shift from */
    unsigned n = 5;     /* the number of positions we want to shift */
    x = invert(x, p, n);

    printf("%d", x);
    return 0;
}

unsigned invert(x, p, n)
unsigned x;
unsigned p;
unsigned n;
{
    unsigned m = 001 << p;  /*a mask that is 1 at the first position */
    int i = 0;
    while (i<n) {
        if ((x & m) == 0) { /* if the number of x at a position of mask is zero (would give result as zero as well) */
            x = x | m;      /* make it one */
            m = m >> 1;     /* right adjust mask for the next position */
        }
        else if ((x & m ) != 0) {
            x = x & ~m;     /* make it zero */
            m = m >> 1;
        }
        i++;
    }
    return x;
}