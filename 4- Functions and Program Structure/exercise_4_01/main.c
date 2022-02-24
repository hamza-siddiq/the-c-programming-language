#include <stdio.h>

int get_line(char s[], int lim);
int r_index(char s[], char t[]);

int main() {
    /* calculates the rightmost occurrence of a word or character inside a line*/
    int MAXLINE = 1000; /* the max size a line can be */
    char line[MAXLINE]; /* the line */
    char t[] = "the";   /* the word or character we want to find */
    int last_position;

    while(get_line(line, MAXLINE) > 0)                  /* a line exists */
        if((last_position = r_index(line, t)) >= -1)    /* r_index calculates the rightmost occurrence in a line */
            printf("%d\n", last_position);              /* prints the position, -1 if not found*/
}
int get_line(s, lim)
char s[];                                               /* the string we want to test */
int lim;                                                /* the character limit in a line */
{
    int i = 0;
    int c;
    while(((c = getchar())!='\n') && c != EOF && --lim > 0)
        s[i++] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}

int r_index(s,t)
char s[];
char t[];
{
    int i, k, max = -1;
    for (i = 0; s[i] != '\0'; i++) {                            /* loop through s, the line */
        for (k = 0; s[i] == t[k] && t[k] != '\0'; i++, k++) {   /* loop through t, the word or char */
        }
        if (t[k] == '\0') {                                     /* if end of t*/
            max = i - k;                                        /* subtract k: total characters of t, */
        }                                                       /* from i: total count in line so far*/
    }
        return max;
}