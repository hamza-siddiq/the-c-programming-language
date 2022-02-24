#include "header.c"
int main(){
    int c;
    int cond;
    struct element array[100];
    struct element *pa = array;

    for(;pa!= NULL && (c=getchar()) != EOF; pa++) {
        if ((cond = check(c, pa)) == 1)
            install(pa->name, pa->def);
        else if (cond == -1)
            erase(pa->name);
    }

    return 0;
}
char name[1000], def[1000];
char *n = name, *d = def;   /*next empty space */
char *sn = name, *sd = def; /* start of string */
int check(char c,  struct element *pa){
    char *add = "add";
    char *erase = "erase";
    char hash[100];
    char *ph = hash;

    for(;c!=EOF && c!='#';c=getchar());                               /* skip till you get to # */
    for(;(c=getchar())!=EOF && c!= ' '; *ph = '\0')                    /* add command to hash string */
        *ph++ = c;

    for (sn = n, pa->name = sn ;(c=getchar())!= EOF && c!= ' ';*n = '\0')           /* add name to array*/
        *n++ = c;
    n++;
    for(sd = d, pa->def= sd;(c=getchar())!= EOF && c!= ' ' && c!= '\n' && c!= '\t';*d = '\0')             /* add def to array */
        *d++ = c;
    d++;
    if (strcmp(hash, add) == 0)                             /* check if it is add or erase */
        return 1;
    if (strcmp(hash, erase) == 0)
        return -1;
}

#define HASHSIZE 100
struct nlist *hashtab[HASHSIZE];
struct nlist *install(){
    int hashval;
    struct nlist *np;
    if (lookup(sn) == NULL) {
        np = ((struct nlist *) malloc(sizeof (*np)));
        if (np == NULL)
            return NULL;
        if ((np->name = sn) == NULL)
            return NULL;
        hashval = hash(sn);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        np->def = NULL;
    if ((np->def = sd) == NULL)
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

void erase(char *s){
    struct nlist *np;

    if((np = lookup(s))!= NULL)
        remov(hashtab[hash(s)], np);
    else
        printf("Nothing to erase");
}

void remov(struct nlist *p,struct nlist *np){
    if (p != np && p->next != np){
        p = p->next;
        remov(p, np);
    }
    else if (p == np) {
        p->def = p->name = NULL, p->next = NULL;
    }
    else if (p->next == np)
        p->next = np->next;
}