#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100
#define MAXWORD 100
#define LINEEND -2

void getlines(char **line);
void printlines(char **line, char *word);
int getword(char *word);
int main() {
    char *line[MAXLINE];
    char word[MAXWORD];
    getlines(line);
    printlines(line, word);
}

void getlines(char **line){
    int c = 0;
    char *l = 0;
    for(;c!= EOF; line++) {
        for (*line = NULL; (l - *line) != MAXLINE && (c = getchar()) != EOF && c != '\n'; l++) {
            if (*line == NULL) {
                *line = calloc(100, sizeof(char));
                l = *line;
            }
            *l = c;
        }
        *l = '\0';
    }
    *line = NULL;
}

char *l;
void printlines(char **line, char *word){
    char *w = word;
    int cond;
    for(;*line!= NULL;line++) {
        l = *line;
        do{
            cond = getword(w);
            if (*w < '\21'){
                printf("%x", *word);
            }
            else
                printf("%s", word);
        }while(cond!= LINEEND);
            printf("\n");
    }
}

int getword(char *word){
    if (*l != ' ' && *l !='\t' && *l != '\0'){
        while(*l != ' ' && *l !='\t' && *l != '\0')
            *word++ = *l++;
        *word = '\0';
    }
    else{
        while((*l == ' ' || *l == '\t') && *l != '\0')
            *word++ = *l++;
        *word = '\0';
    }
    if (*l == '\0')
        return LINEEND;
    return 0;
}