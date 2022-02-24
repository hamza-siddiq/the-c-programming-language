#include <stdio.h>

int main(argc,argv)
int argc;
char *argv[];
{
    long tabstops, tab = 0, space = 0;
    int c;
    char s_array[100];
    char *s_start = s_array;
    char *s = s_array;
    argc--;
    argv++;

    if (argc > 1)
        if (*(*++argv+1) >='0'& *(*argv+1) <= '9')
        tabstops = 10 * (**argv - '0') + (*(*argv + 1) - '0');
        else
            tabstops = **argv - '0';
    else
        tabstops = 4;

    while ((c = getchar()) != EOF) {
        if (c != '\t') {
            putchar(c);
            continue;
        }
        for (; c == '\t'; c = getchar())
            s += tabstops;
        if (s > s_start) {
            space = s - s_start;
            for (; space > 0; space--) {
                printf(" ");
            }
            s = s_start;
            putchar(c);
        }
    }
        return 0;
    }