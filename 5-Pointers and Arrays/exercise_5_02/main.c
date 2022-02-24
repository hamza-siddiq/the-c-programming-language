#include <stdio.h>

void strcat(char *s,char *t);
int main() {                                /* concatenate a string using pointers */
    char s[1000] = "This is a ";
    char *t = "concatenated string";

    strcat(s,t);
    printf("%s", s);
}

void strcat(s,t)
char *s;
char *t;
{
    while(*s++ != '\0');
    s--;                        /* to bring position back to '\0', and replace it next */
    while((*s++ = *t++)!= '\0');
}