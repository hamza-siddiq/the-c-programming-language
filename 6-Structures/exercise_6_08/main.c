#include <stdio.h>
#include "header.h"
char *words[1000];
char **pws = words;
char word[100000];
char *pw = word;
int main(){
    int c;
    struct element defarray[100];
    struct element *pa = defarray;
    struct nlist *np;
    int condition;


    while((condition = getword()) && condition != EOF){                  /* get a word */
        if ((np = lookup(*pws) )!= NULL)                 /* check if it is in hashtab */
            *pws = np ->def;              /* if it is, make the word, the definition */
        if ((defchecker(c, pa))) {                   /* check if the word is define */
            install(pa->name, pa->def);             /* if it is, add it to hashtab */
            pa++;
        }
    }
    char **pwords = words;
    while(*pwords!= NULL)
         printf("%s", *pwords++);
    return 0;
}


char chararray[100];
char *pcastart = chararray;
char *pca = chararray;
void ungetch(char c){
    *pca++ = c;
}
int getch(){
    return((pca-pcastart)>0? *(--pca): getchar());
}


int getword(){
    int c;
    if ((c=getch()) != EOF && c!='#' && isalpha(c) == 0 && isdigit(c) ==0) {
        for (*pws = pw; c != EOF && c!='#' && isdigit(c) == 0 && isalpha(c)==0; *pw = '\0', c = getch())                     /* empty space*/
            *pw++ = c;
        pw++;
        pws++;
    }
    for(*pws = pw; c !=  EOF && (c=='#' ||isalpha(c) || isdigit(c)); c=getch(), *pw = '\0') /* word */
        *pw++ = c;
    pw++;
    if (c==EOF)
        return EOF;
    ungetch(c);
    return pw-*pws;
}

char name[1000], def[1000];
char *n = name, *d = def;   /*next empty space */
int defchecker(char c,  struct element *pa){
    char *define = "#define";

    if(strcmp(*pws, define) != 0) { /* defchecker if it is # */
        pws++;
        return 0;
    }

    pws++;                                                            /* increment words array */
    getword();                                                        /* get name */
    n = *pws;
    pa->name = n;

    pws++;
    getword();
    d = *pws;
    pa->def = *pws;
    pws++;
    return 1;
}

#define HASHSIZE 100
struct nlist *hashtab[HASHSIZE];
struct nlist *install(){
    int hashval;
    struct nlist *np;
    if (lookup(n) == NULL) {
        np = ((struct nlist *) malloc(sizeof (*np)));
        if (np == NULL)
            return NULL;
        if ((np->name = n) == NULL)
            return NULL;
        hashval = hash(n);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        np->def = NULL;
    if ((np->def = d) == NULL)
        return (NULL);
    return np;
}

struct nlist *lookup(char *s){

    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np ->next)
        if (strcmp(np->name, s) == 0)
            return np;
    return NULL;
}
int hash(char *s){
    int hashval = 0;

    for(hashval = 0; *s != '\0';)
        hashval += *s++;
    return (hashval % HASHSIZE);
}
