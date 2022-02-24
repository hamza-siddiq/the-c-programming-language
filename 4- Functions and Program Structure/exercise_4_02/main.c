#include <stdio.h>

int get_line(char line[], int lim);
double a_to_f(char s[]);
double powerf(double base, double raise);
double scientificf(double value, char sf[]);

int main() {                /* adds the value enterd of each line, to the previous one, and prints the scientific value*/
    int MAXLINE = 1000;
    char line[MAXLINE];
    char sf[1000];

    double sum = 0;
    while(get_line(line, MAXLINE) > 0) {
        sum += a_to_f(line);
        printf("\t%.5f%s\n", scientificf(sum, sf), sf);
    }

}

int get_line(line, lim)
char line[];
int lim;
{
    int c;
    int i;
    for(i =0 ; (c=getchar()) != EOF && c != '\n' && --lim > 0; i++){
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}

double a_to_f(s)
char s[];
{
    int i;
    double value, power;
    for(i = 0; s[i] == ' ' ||  s[i] == '\n' || s[i] == '\t'; i++); /* skip white space */

    int sign = 1;
    if (s[i] == '+' || s[i] == '-')                                 /* skip sign */
        sign = s[i++] == '+' ? 1 : -1;

    for(value =0; s[i] >= '0' && s[i] <='9'; i++)                   /* calculate value till decimal */
        value = value * 10 + s[i] - '0';

    if (s[i] == '.')                                                /* ignore decimal */
        i++;

    for (power = 1; s[i] >= 0 && s[i] <= '9' && s[i] != '\0'; i++){ /* calculate value after decimal */
        value = value * 10 + s[i] - '0';
        power *= 10;
    }
    value = sign * (value / power);                                 /* add decimal by using power that was calculated */

    if (s[i] == 'e' || s[i] == 'E') {                               /* check if e exists */
        i++;                                                        /* ignore e */
        if (s[i] >='0' && s[i] <='9')
            value = value * powerf(10, (s[i] - '0'));   /* multiply value by power of e */
        else if (s[i] == '-') {
            i++;
            value = value / powerf(10, (s[i] - '0'));   /* divide value by power of e */
        }
    }

    return value;
}

double powerf(base, raise)
double base;
double raise;
{
    int i, value=1;
    if (raise == 0)
        return 1;
    for(i = 1; i <= raise; i++)
        value *= base;
    return value;
}

double scientificf(value, sf)      /* convert a number to scientific notation */
char sf[];
double value;
{
    double largest_number = 10; /* if a number is above this number, we would convert it */
    double smallest_number = 1; /* if a number is below this number, we would convert it */

    int power = 0;
    int sign =1;                 /* set sign to zero */
    if (value < 0){
        sign *= -1;              /* get the value of the sign */
        value *= -1;            /* if negative, convert value to positive */
    }

    while(value >= largest_number){ /* convert the value to a decimal, increase power, if more than largest value(10)*/
        value /= 10;
        power++;
    }

    while(value <= smallest_number){ /* convert the value to a decimal, decrease power, if less than smallest value(1)*/
        value *= 10;
        power--;
    }

    int i = 0, j = 0;               /*add everything after e to a string */
        sf[i++] = 'e';

    if (power<0) {                  /* if the power is negative*/
        sf[i++] = '-';              /*add a negative sign to the string*/
        power *= -1;                /* make power positive*/
    }
    else
        sf[i++] = '+';               /* if the power is positive, add positive sign to string*/

    char pf[1000];
    for (;power > 0; power /= 10){   /* add the powers values to a new string */
        pf[j++] = power % 10 +'0';
    }
    pf[j] = '\0';

    for(--j;j>=0;--j, i++){         /* add the power string to the scientific string */
        sf[i] = pf[j];
    }
    sf[i] = '\0';

    value *= sign;                  /* add the sign to the value */
    return value;
}