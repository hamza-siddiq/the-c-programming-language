#include <stdio.h>

void entab(long tabstops, int c);
void detab(long tabstops, long space, int c, char s_array[], char *s_start);
int strcmp (char *a, char *argv[]);
void program (long tabstops,  long tab, long space, int c, char *argv[]);
int a_to_i(char *s);
int m_n_calculator(int argc, char *argv[], char *s);

int main(int argc, char **argv)    /* entab and detab from command line */
{
    long tabstops, tab= 0, space=0;
    int c;
    char *s;
    argc--;
    argv++;
    int extern m, n;
    int extern sp;

    m_n_calculator(argc, argv, s);                                              /* calculate m and n */
    if (m>0) {                                                                  /* run m if present */
        tabstops = m;
        c = getchar();
        program(tabstops,  tab, space, c, argv);         /* run program once */
        if (n > 0) {                                                            /* run n only if m is present */
            tabstops = n;
            while ((c=getchar()) != EOF)
                program(tabstops,  tab, space, c, argv);     /* run program till EOF */
        }
        if (sp == 1)
            printf(" ");
    }
    else
        printf("M argument missing");
    return 0;
}

int m, n;
int m_n_calculator(int argc, char *argv[], char *s) {
    while (--argc > 0 && argv++) {
        for (s = *argv; *s != '\0'; s++) {
            switch (*s) {
                case 'm':
                    s = *++argv;
                    if(*s >= '0' && *s <= '9') {
                        argc--;
                        m = a_to_i(s);
                        break;
                    }
                    goto error;
                case '+':
                    s++;
                    if (*s == 'n') {
                        s = *++argv;
                        argc--;
                        n = a_to_i(s);
                        break;
                    }
                default: {
                    error: printf("Invalid argument of character \"%c\"\n", *s);
                    return 0;
                }
            }
        }
    }
    return 0;
}

void program (long tabstops, long tab, long space, int c, char *argv[])
{
    char s_array[100];
    char *s_start = s_array;

    if (tabstops <= 0)
        tabstops = 4;
    if (strcmp("entab", argv)){
        entab(tabstops, c);
    }
    else if (strcmp("detab", argv)) {
        detab(tabstops, space, c, s_array, s_start);
    }
}

int sp = 0;
void entab(long tabstops, int c)
{
    while (c != EOF){
        for(;c != ' ' && c != EOF; c = getchar())                                   /* get all non spaces */
            putchar(c);
        for(;c != EOF && c == ' ' && sp != tabstops; c =getchar())      /* get all spaces */
            ++sp;
        if (sp == tabstops) {                                           /* spaces is equal to tab stops, print tab */
            printf("\t");
            break;
        }
        else {
            for (;sp > 0; sp--)                                            /* otherwise print the spaces */
                printf(" ");
            continue;                                                   /* and continue loop till EOF or tabstops*/
        }
    }
    if(c!= ' ' && c != EOF) {
        putchar(c);
        sp =0;
    }
    else if(c == ' ')
        sp =1;
}


void detab(long tabstops, long space, int c, char s_array[], char *s_start)
{
        for (; c != '\t' && c != EOF; c = getchar())
            putchar(c);
        if (c == '\t')
            s_array += tabstops;
            space = s_array - s_start;
            for (; space > 0; space--) {
                printf(" ");
            }
        if (c !=EOF & c!='\t')
            putchar(c);
}

int strcmp (char *a, char *argv[])
{
    char *b = *argv;
    for(;*b == *a++ ; b++) {
        if (*a == '\0') {
            return 1;
        }
    }
    return 0;
}

int a_to_i(char *s)
{
    int v;
    for(v=0; *s!= '\0'; s++)
        v = v * 10 + (*s - '0');
    return v;
}