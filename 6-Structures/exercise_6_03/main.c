#include <ctype.h>
#include <stdio.h>
struct key{
    char *keyword;
    int keycount;
} keytab[]={
        "auto", 0, "break", 0, "case", 0, "char", 0, "const", 0, "continue", 0, "default", 0,
        "do", 0, "double", 0, "else", 0, "enum", 0, "extern", 0, "float", 0, "for", 0,
        "goto", 0, "if", 0, "inline", 0, "int", 0, "long", 0, "register", 0, "restrict", 0,
        "return", 0, "short", 0, "signed", 0, "sizeof", 0, "static", 0, "struct", 0, "switch", 0,
        "typedef", 0, "union", 0, "unsigned", 0, "void", 0, "volatile", 0, "while", 0
};
#define NKEYS (sizeof(keytab) / sizeof(struct key))
#define MAXWORD 20
#define LETTER 'a'
int getword(char *w, int lim);
int binary(char *word,struct key *tab, int n);
int getch();
void ungetch(int c);
int strcmp(char *word, char *keyword);
int type(int c);
int main()
{
    int n, t;
    char word[MAXWORD];

    while((t = getword(word, MAXWORD))!= EOF) {
        if(t == '\"')
            do{
                t = getword(word, MAXWORD);
            } while(t != '\"' && t != EOF);
        if (isalpha(t))
            if ((n = binary(word, keytab, NKEYS)) >= 0)
                keytab[n].keycount++;
    }
    for(n=0; n<NKEYS; n++){
        if (keytab[n].keycount > 0)
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);
    }
}

int getword(char *w, int lim)
{
    int c, t;

    if (type( c = *w++ = getch()) <= 0){
        *w ='\0';
        return(c);
    }
    while(--lim > 0){
        if(type(c = *w++ = getch()) < 0){
            ungetch(c);
            break;
        }
    }
    *(w-1) = '\0';
    return (LETTER);
}

int binary(char *word,struct key *tab, int n)
{
    int low, high, mid, cond;

    low = 0;
    high = n-1;
    while(low <= high){
        mid = (low + high) /2;
        if ((cond = strcmp(word, tab[mid].keyword))<0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return (mid);
    }
    return -1;
}

#define MAXARRAY 100
char array[MAXARRAY];
int pa = 0;

int getch()
{
    return(pa >0 ? array[--pa]: getchar());
}

void ungetch(int c)
{
    if (pa < MAXARRAY){
        array[pa++] = c;
    }
    else
        printf("array is full so can't ungetch");
}

int strcmp(char *word, char *keyword){
    while(*word == *keyword && *word++ != '\0' && *keyword++ != '\0'){
        if(*word == '\0' && *keyword == '\0')
            return 0;
    }
    if(*word < *keyword)
        return -1;
    else
        return 1;
}


int type(int c)
{
    if(isalpha(c))
        return 1;
    else if (isdigit(c))
        return 0;
    else
        return -1;
}