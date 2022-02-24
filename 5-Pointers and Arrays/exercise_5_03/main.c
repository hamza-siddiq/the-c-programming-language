#include <stdio.h>
#define copyit(s,p) while((*s++ = *p++)!= '\0')
void strcpy2(char *s,char *p);

int main() {                        /* copy a string, used a macro */
    char s[1000];
    char *p = "This is a string";
    strcpy2(s,p);
    printf("%s", s);
}

void strcpy2(s,p)
char *s, *p;
{
    copyit(s,p);
}