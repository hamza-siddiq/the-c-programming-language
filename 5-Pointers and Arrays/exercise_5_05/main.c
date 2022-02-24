#include <stdio.h>
#include <string.h>
#define LINES 100
#define MAXLEN 1000
#define notarrayend(line, lineptr, l, p) (line - l < MAXLEN && lineptr - p < LINES)
int readlines(char line[], char *lineptr[]);
void writelines(char *lineptr[], int nlines);
void sort(char *v[], int n);

int main() {            /* create lines in an array supplied by main, rather than alloc for storage */
    char line[MAXLEN];
    char *lineptr[LINES];
    int nlines;

    if((nlines = readlines(line,lineptr))>=0){
        sort(lineptr, nlines);
        writelines(lineptr, nlines);
    }
    else
        printf("Input too big to sort\n");
    return 0;
}

int readlines(line, lineptr)
char line[];
char *lineptr[];
{
    char *l = line, c;
    char **p = lineptr;


    while((c = getchar())!= EOF && notarrayend(line, lineptr, l, p) ) {
        for (*lineptr++ = line, *line++ = c;
             (c = getchar()) != EOF && notarrayend(line, lineptr, l, p) && c != '\n';)
            *line++ = c;
        if (c == '\n' || c == EOF){
            *line++ = '\0';
            }
    }
    if (c == EOF)
        return (lineptr - p);
    else
        return - 1;
}

void sort(v, n)
char *v[];
int n;
{
    int gap, i, j;
    char *temp;

    for(gap = n/2; gap >0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i-gap; j >= 0; j-= gap)
                if(strcmp(v[j], v[j+gap])>0)
                    break;
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
}

void writelines(lineptr, nlines)
char *lineptr[];
int nlines;
{
    while(--nlines >= 0)
        printf("%s\n", *lineptr++);
}