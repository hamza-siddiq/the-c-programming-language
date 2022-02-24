#include <stdio.h>
#define SIZE 100

int getfloat(double *pv);
int getch();
void ungetch(int c);
int main() {                                        /* performs free format input conversion */
    double v, array[SIZE];
    int n;

    for(n = 0; n < SIZE && getfloat(&v) != EOF ;n++)
        array[n] = v;
    if (v > 0)
        array[n++] = v;
    array[n] = '\0';
    for(n = 0; array[n]!= '\0'; n++)
        printf("%.3f\n", array[n]);
}

int getfloat(pv)
double *pv;
{
    int c, power;
    for(c = getch(); c == ' ' || c == '\n' || c == '\t'; c = getch())
        ;
    for(*pv = 0; c >= '0' && c <= '9'; c = getch())
        *pv = *pv * 10 + c -'0';
    if (c == '.')
        c = getch();
    for(power = 1; c >= '0' && c <= '9'; c = getch()) {
        *pv = *pv * 10 + c - '0';
        power *= 10;
    }
    *pv /= power;
    if (c != EOF)
        ungetch(c);
    return(c);
}

char stack[SIZE];
int i = 0;
int getch()
{
    return(i > 0 ? stack[--i] : getchar());
}

void ungetch(c){
    if(i < SIZE)
        stack[i++] = c;
    else
        printf("Stack is full");
}