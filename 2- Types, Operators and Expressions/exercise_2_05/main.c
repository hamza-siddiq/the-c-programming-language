#include <stdio.h>
int shiftvalidity(unsigned p, unsigned n, int length);
int length_of_bits(unsigned x,int length);
unsigned left_to_right(unsigned x, int length);
unsigned getbits(unsigned x, unsigned p, unsigned n, unsigned num, unsigned length);
int bits_array_reverse(char reverse_array[], unsigned n, int c);
int bits_array(char reverse_array[], int c, char array[]);
int main() {
    unsigned x = 0301;              /* The octal number we want to shift */
    int length = 0;                 /* The total length of bits of the octal number */
    unsigned p = 0;                 /* The position we want to shift from */
    unsigned n = 8;                 /* The number of positions we want to shift */
    unsigned num = 0;               /* The number we would get back after the shift */
    char reverse_array[500];        /* Store in an array to print it, this would be in reverse */
    int c = 0;                      /* character number of reverse array */
    char array[500];                /* Straighten the array */



    length = length_of_bits(x, length);     /*checks the length of the octal number */
    if (shiftvalidity(p, n, length) == 0)   /* checks to see if the shift we want is valid */
        return 0;

    x = left_to_right(x, length);           /*Makes the octal number from left to right */

    num = getbits(x, p, n, num, length);
    c = bits_array_reverse(reverse_array, num, c);
    bits_array(reverse_array, c, array);

    printf("%s", array);
    return 0;
}

int length_of_bits(x, length)
/*Total length of the bits, one more than total bits positions
 * since bits position start at 0.
*/
unsigned x;
int length;
{
    while (x != 0){
        x = x >> 1;
        ++length;
    }
    return length;
}

int shiftvalidity(p, n, length)
        unsigned p;
        unsigned n;
{
    if (p + n > length) {
        printf("n is exceeding the total length. Adjust p and n.");
        return 0;
    } else if (n == 0) {
        printf("n is set to zero. Adjust p and n.");
        return 0;
    }
    return 1;
}


unsigned left_to_right(x, length)
unsigned x;
{
    int i = (length * 2);               /* sets length to twice as much, to add "left to right" to the extra space.*/
    x = x | 001 << i;                   /* add a one to the start incase the first digit is zero. This would be
                                        * removed later with a mask in the next function*/
    i--;
    while (i>0){
        if ((x & 001) == 001)
            x = x | 001 << i;
        if ((x & 001) == 000)
            x = x | 000 << i;
        x = x >> 1;
        i--;                            /* decrement twice, because of shift */
        i--;
    }

    return x;
}
unsigned getbits(x, p, n, num, length)                  /*Get the bits and then shift them to the right end*/
unsigned x, p, n, num, length;
{
    x = x | 001 << (length-p);                  /* add 1 to the left of position 0, incase it is 0, remove later*/
    num = ( x >> (length-(p+n)) & ~(~0 << n+1));/* n+1, to make sure we get the 1 we just added, masking would remove
                                                * the one we added earlier in function left_to_right as well. */
    return num;                                 /* we would get a number back */
}

int bits_array_reverse(reverse_array, num, c)   /* Create an array that is in reverse*/
char reverse_array[];
unsigned num;
int c;
{
    while (num>001){                            /* get every digit till we get the 1 that we added*/
        if ((num & 001) == 1){
            reverse_array[c] = '1';
        }
        else if ((num & 001) == 0){
            reverse_array[c] = '0';
        }
        num = num >> 1;
        ++c;
    }
    --c;
    return c;
}

int bits_array(reverse_array, c, array)     /* Function to straighten the array */
char reverse_array[];
int c;
char array[];
{
    int i =0;
    while(c >= 0){
        array[i++] = reverse_array[c--];
    }
    array[i] = '\0';
    return i;
}