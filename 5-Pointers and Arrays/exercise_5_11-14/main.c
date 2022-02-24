#include <stdio.h>
#define LINES 10000
#define LINELEN 10000

int readlines(char **lineptr, int lines, char *line);
void sort(char *v[], int n, int reverse, int (*comp)(), void (*exch)());
int dictcmp(char *v1, char *v2);
int numcmp(char *s1, char *s2);
int fldcmp(char *v1, char *v2);
int strcmp(char *s1, char *s2);
void swap(char *px[], char *py[]);
void writelines(char **lineptr, int nlines);

int fold = 0;
int main(int argc, char *argv[])
{
    --argc,++argv;
    char *lineptr[LINES];
    char line[LINELEN];
    int nlines;
    int numeric = 0, reverse = 0, dictionary = 0;

    for(++argv;--argc>0; argv++)
        for((*argv)++;**argv != '\0'; (*argv)++) {
            if (**argv == 'n')
                numeric = 1;
            if (**argv == 'r')
                reverse = 1;
            if (**argv == 'f')
                fold = 1;
            if (**argv == 'd')
                dictionary =1;
        }

    if ((nlines = readlines(lineptr, LINES, line)) >= 0){
        if (dictionary){
            sort(lineptr, nlines, reverse, dictcmp, swap);
        }
        else if (numeric) {
            sort(lineptr, nlines, reverse, numcmp, swap);
        }
        else if (fold)
            sort(lineptr, nlines, reverse, fldcmp, swap);
        else
            sort(lineptr, nlines, reverse, strcmp, swap);
        writelines(lineptr, nlines);
    }
    else
        printf("Input too big to sort\n");
    return 0;
}
int readlines(char **lineptr, int lines, char *line)
{
    int c;
    char **ptrstrt = lineptr;   /* start of pointer array */
    char *linestrt = line;      /* start of line*/
    int blank;                  /* first character of line is blank */

    *lineptr++ = line;          /* line address stored in pointer array at position 0 */
    while((c= getchar()) != EOF && lineptr-ptrstrt < lines && line - linestrt < LINELEN){
        if (c != '\n' && c != ' ' && c != '\t') {
            *line++ = c;
            blank = 0;
        }
        else if (blank == 1 && (c == '\n' || c == ' ' || c == '\t'))
            continue;
        else{
            *line++ = '\0';
            *lineptr++= line;
            blank =1;
        }
    }
    *line = '\0';
    if (line - linestrt == LINELEN)
        return -1;
    else if (lineptr-ptrstrt == lines)
        return -1;
    else
        return (lineptr - ptrstrt);
}

void sort(char *v[], int n, int reverse, int (*comp)(), void (*exch)())
{
    int gap, i , j;
    for (gap = n/2; gap > 0; gap /=2)
        for (i = gap; i < n; i++)
            for (j = i-gap; j >= 0; j -=gap) {
                if (reverse) {
                    if ((*comp)(v[j+gap], v[j]) <= 0)
                        (*exch)(&v[j + gap], &v[j]);
                }
                else {
                    if ((*comp)(v[j], v[j + gap]) > 0)
                        (*exch)(&v[j], &v[j + gap]);
                }
            }
}

int dictcmp(char *v1, char *v2)
{
    while((*v1 < '0' || *v1 > '9') && *v1 != ' ' &&
       (*v1 < 'A' || *v1 > 'Z') && (*v1  < 'a' || *v1 > 'z'))
        v1++;
    while((*v2 < '0' || *v2 > '9') && *v2 != ' ' &&
          (*v2 < 'A' || *v2 > 'Z') && (*v2  < 'a' || *v2 > 'z'))
        v2++;
    if (*v1 >= '0' && *v1 <= '9'&&
        *v2 >= '0' && *v2 <= '9')
        return numcmp(v1, v2);
    else if (fold)
        return fldcmp(v1, v2);
    else
        return strcmp(v1, v2);
}

int numcmp(char *s1, char *s2)
{
    double atof(), v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int fldcmp(char *v1, char *v2)
{
    int c1, c2;
    if (*v1 >='A' && *v1 <= 'Z')
        c1 = *v1 + 32;
    else
        c1 = *v1;
    if (*v2 >= 'A' && *v2 <= 'Z')
        c2 = *v2 + 32;
    else
        c2 = *v2;

    if(c1 < c2 )
        return -1;
    else if(c1 > c2)
        return 1;
    else
        return 0;
}


int strcmp(char *s1, char *s2)
{
    if(*s1 < *s2)
        return -1;
    else if(*s1 > *s2)
        return 1;
    else
        return 0;
}

void swap(char *px[], char *py[])
{
    char *temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

void writelines(char **lineptr, int nlines)
{
    while(--nlines >= 0)
        printf("%s\n", *lineptr++);
}
