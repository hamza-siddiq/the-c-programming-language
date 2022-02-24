#include <stdio.h>
double itoa(char s[], double n);

int main() {
    /* make an unsigned negative number */
    char s[1000];
    double n = -2147483648;

    itoa(s, n);
    printf("%s", s);
}

double itoa (s, n)
char s[];
double n;
{
    int sign, i=0;
    if (n < 0) {
        sign = -1;
        n *= -1;
    }
    unsigned n2 = n;

    do s[i++] = n2 % 10 + '0';
    while((n2 /= 10) > 0);

    if (sign<0)
        s[i++] = '-';

    s[i] = '\0';

    return 0;
}
