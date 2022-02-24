#include <stdio.h>

int total_characters(char s[], int n);
double hex_to_digits(char s[], int n);
double power(int hex_base, int hex_power);

int main() {
    /*
     * Program to convert Hex to decimal digits
     */
    char s[] = "0a8431AC2b";            /* the string that we want to convert */
    int n = 0;                          /* the total number of characters */
    double digits;                      /* the digits returned */

    n = total_characters(s, n);
    digits = hex_to_digits(s, n);
    printf("%0.0f", digits);           /* output in double to allow conversion of large strings*/
    return 0;
}

int total_characters(s, n)             /* Calculates total characters */
char s[];
int n;
{
    while (s[n] != '\0'){
        ++n;
    }
    --n;
    return n;
}

double hex_to_digits(s, n)               /* Converts hex to digits*/
char s[];
int n;
{
    int digit =0;
    double sum = 0;
    double oldsum = 0;
    int hex_base = 16;
    int hex_power = 0;

    while (n>=0){
        if(s[n] >= '0' && s[n] <= '9'){
            digit = s[n] - '0';
        }
        else if (s[n] == 'a' || s[n] == 'A')    /* Checks one by one, machine characters might not be continuous */
            digit = 10;
        else if (s[n] == 'b' || s[n] == 'B')
            digit = 11;
        else if (s[n] == 'c' || s[n] == 'C')
            digit = 12;
        else if (s[n] == 'd' || s[n] == 'D')
            digit = 13;
        else if (s[n] == 'e' || s[n] == 'E')
            digit = 14;
        else if (s[n] == 'f' || s[n] == 'F')
            digit = 15;

        sum = oldsum + digit * power(hex_base, hex_power);
        oldsum = sum;

        n -= 1;
        hex_power += 1;
    }
    return sum;
}

double power(hex_base, hex_power)                                  /* function to calculate power value */
int hex_base;
int hex_power;
{
    double powertotal = 1;
        for (int i = 0; i < hex_power; ++i)
            powertotal = powertotal * hex_base;
    return powertotal;
}