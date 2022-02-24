#include <stdio.h>

int itoa(char s[], int n);
int main() {
    char s[100];
    int n = 182120;
    itoa(s, n);
    printf("%s", s);
}

int itoa(s, n)
char s[];
int n;
{
    int i =0, j;
    if (n > 0){
        j = n % 10;
        n /= 10;
        i = itoa(s,n);
        s[i++] = j+'0';
    }
    s[i] = '\0';
    return i;
}