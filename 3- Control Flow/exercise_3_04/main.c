#include <stdio.h>

int itob(unsigned n, char b[]);
int max_power_value(int digit, int power);
int left_shift(char b[], char c[]);
int itoh(unsigned n, char h[]); /* converts integer to binary */

int main() {
    char b[1000];
    char c[1000];
    char h[1000];
    char h2[1000];

    unsigned n = 112;

    itob(n, b);
    left_shift(b, c);

    itoh(n, h);
    left_shift(h, h2);

    printf("%s\n", c);
    printf("%s\n", h);

    return 0;
}

int itob(n, b) /* converts integer to binary */
unsigned n;
char b[];
{
    int power = 30;
    int a, i = 0;
    int digit = 2;
    do{
        a = n / max_power_value(digit, power);
        b[i++]= a ? '1':'0';
        n = n % max_power_value(digit, power) ;
    } while((power -= 1) >= 0);

    return 0;
}

int itoh(n, h) /* converts integer to hexadecimal */
unsigned n;
char h[];
{
    int power = 7;
    int a, i = 0;
    int digit = 16;
    do{
        a = n / max_power_value(digit, power);
        switch (a) {
            case 0 :
                h[i++] = '0';
                break;
            case 1 :
                h[i++] = '1';
                break;
            case 2 :
                h[i++] = '2';
                break;
            case 3 :
                h[i++] = '3';
                break;
            case 4 :
                h[i++] = '4';
                break;
            case 5 :
                h[i++] = '5';
                break;
            case 6 :
                h[i++] = '6';
                break;
            case 7 :
                h[i++] = '7';
                break;
            case 8 :
                h[i++] = '8';
                break;
            case 9 :
                h[i++] = '9';
                break;
            case 10:
                h[i++] = 'A';
                break;
            case 11:
                h[i++] = 'B';
                break;
            case 12:
                h[i++] = 'C';
                break;
            case 13:
                h[i++] = 'D';
                break;
            case 14:
                h[i++] = 'E';
                break;
            case 15:
                h[i++] = 'F';
                break;
        }
        n = n % max_power_value(digit, power) ;
    } while((power -= 1) >= 0);

    return 0;
}

int max_power_value(digit, power) /* the max power value that a binary or hexadecimal has */
int digit;
int power;
{
    int v = 1;

    if (power){
        for(int  i = 1; i<=power; i++)
            v = v*digit;
    }
    return v;
}



int left_shift(b, c)            /* remove unwanted 0's at the beginning of a string*/
char b[];
char c[];
{
    int i =0;
    int j = 0;
    while(b[i] != '1' ){
        i++;
    }
    while (c[j++]= b[i++])
        ;
    c[j] = '\0';
    return 0;
}