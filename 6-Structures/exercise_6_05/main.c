#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct arrayelement{
    char *word;
    int ln;
};
struct lnnode{
    int ln;
    struct lnnode *less;
    struct lnnode *more;
};
struct wnode {
    char *word;
    int ln;
    struct wnode *less;
    struct wnode *more;
    struct lnnode *lnless;
    struct lnnode *lnmore;
};
void getwords(char *array, struct arrayelement *parray);
struct wnode *wtree(struct wnode *p, struct arrayelement *parray);
struct lnnode *lntree(struct lnnode *p, int ln);
struct wnode *wtreeprint(struct wnode *p);
struct lnnode *ntreeprint(struct lnnode *p);
struct wnode *walloc();
struct lnnode *lnalloc();

int main() {
    char array[10000];
    struct arrayelement parray[1000];
    struct wnode *root = NULL;
    struct arrayelement *a = parray;

    getwords(array, parray);
    for(;a->word != NULL; a++){
        root = wtree(root,a);
    }
    wtreeprint(root);
    return 0;
}

int line = 1;
void getwords(char *array, struct arrayelement *parray){
    int c = 0;

    while((c=getchar())!= EOF){
        for(;isalpha(c)==0 && isdigit(c) == 0; c=getchar());
        for(parray->ln = line, parray++->word = array; c != EOF && (isalpha(c) || isdigit(c));c=getchar()){
            *array++ = c;
        }
        *array++ = '\0';
        for(;c!= EOF && c!=' ' && c!= '\t' && c!= '\n'; c=getchar());
        if (c == '\n')
            line++;
    }
}

struct wnode *wtree(struct wnode *p, struct arrayelement *parray){
    int cond = 0;

    if (p == NULL){
        p = walloc();
        p->word = parray->word;
        p->ln = parray->ln;
        p->lnless = p->lnmore = NULL, p->less = p->more = NULL;
    }
    else if ((cond = strcasecmp(parray->word, p->word)) < 0)
        p->less = wtree(p->less, parray);
    else if (cond > 0)
        p->more = wtree(p->more, parray);
    else if (parray->ln < p->ln)
        p->lnless = lntree(p->lnless, parray->ln);
    else if (parray->ln > p->ln)
        p->lnmore = lntree(p->lnless, parray->ln);

    return p;
}

struct lnnode *lntree(struct lnnode *p, int ln){

    if (p == NULL) {
        p = lnalloc();
        p->ln = ln;
        p->less = p->more = NULL;
    }
    else if (ln < p->ln)
        p->less = lntree(p->less, ln);
    else if(ln > p->ln)
        p->more =  lntree(p->more, ln);

    return p;
}

int first_word =1;
struct wnode *wtreeprint(struct wnode *p){
    if (p!=NULL) {
        wtreeprint(p->less);
        first_word? printf("%s", p->word), first_word = 0: printf("\n%s", p->word);
        ntreeprint(p->lnless);
        printf(" %d", p->ln);
        ntreeprint(p->lnmore);
        wtreeprint(p->more);
    }
    return p;
}

struct lnnode *ntreeprint(struct lnnode *p){
    if (p!=NULL) {
        ntreeprint(p->less);
        printf(" %d", p->ln);
        ntreeprint(p->more);
    }
    return p;
}

struct lnnode *lnalloc() {
    return ((struct lnnode *) malloc(sizeof(struct lnnode)));
}
struct wnode *walloc() {
    return ((struct wnode *) malloc(sizeof(struct wnode)));
}