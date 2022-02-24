#include <stdio.h>
#define print(s) printf("%s\n",s)

void reverse(char n[], char s[]);
int main() {                        /* reverses a string */
    char n[] = "gnirts a si sihT";  /* String to reverse */
    char s[1000];

    reverse(n,s);
    print(s);                /* print reversed string */
}

static i = 0;                       /* incrementor for n */
static j = 0;                       /* incrementor for s */
void reverse(n,s)
char register n[];
char register s[];
{
    if (n[i++] != '\0') {           /* get every character till end of string */
        reverse(n, s);
        s[j++] = n[i--];
    }
    else{                 /* then go one back, and start reversing from there, extra i-- to cancel the extra i++*/
        i--;
        i--;
    }
    s[j] = '\0';            /* set to '\0' everytime before replacing, this way the last recursion would be set to '\0'*/
}