#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char *word;
    int count;
    struct node *less;
    struct node *more;
    struct node *same_less;
    struct node *same_more;
};
int getword(int c);
struct node *wtree(struct node *p);
struct node *dtree(struct node *p, struct node *w);
struct node *dtreeadd(struct node *w);
struct node *dprint(struct node *p);
struct node *alloc();

int main() {                        /* Prints the words in the input, sorted into decreasing order of frequency*/
    struct node *wroot = NULL;
    struct node *croot = NULL;

    while(getword(getchar()))
        wroot = wtree(wroot);

    croot = dtreeadd(wroot);
    dprint(croot);
    return 0;
}

char word[100];
char *nword = word;                 /* pointer to next empty space */
char *pword = word;
int getword(int c){
    int letter = 0;
    for(; c!= EOF && isalpha(c) == 0 && isdigit(c) == 0; c=getchar());   /* skip empty space */
    for (pword = nword;c!= EOF && (isalpha(c) || isdigit(c)); letter=1, c=getchar()){      /* get word */
        *nword++ =c;
        *nword = '\0';
    }
    nword++;
    return letter;
}

struct node *wtree(struct node *p){
    int cond;

    if (p==NULL){
        p = alloc();
        p->word = pword;
        p->count = 1;
        p->less = p->more = p->same_less = p->same_more = NULL;
    }
    else if ((cond = strcasecmp (pword, p->word))<0)
        p->less = wtree(p->less);
    else if (cond > 0)
        p->more = wtree(p->more);
    else
        p->count++;

    return p;
}
struct node *c;
struct node *dtreeadd(struct node *w){
    if (w!=NULL) {
        dtreeadd( w->less);
        dtreeadd( w->same_less);
        c = dtree(c, w);
        dtreeadd( w->same_more);
        dtreeadd(w->more);
    }
    return c;
}

struct node *dtree(struct node *p, struct node *w){
    int cond;
    if (p == NULL){
        p = alloc();
        p->count = w->count;
        p->word = w->word;
        p->less = p->more = p->same_less = p->same_more = NULL;
    }
    else if (w->count < p->count)
        p->less = dtree(p->less, w);
    else if (w->count > p->count)
        p->more = dtree(p->more, w);
    else if ((cond = strcasecmp (w->word, p->word))<0)
        p->same_less = dtree(p->same_less, w);
    else if (cond > 0)
        p->same_more = dtree(p->same_more, w);
    else
        printf("Error in code");

    return p;
}

struct node *dprint(struct node *p){
    if (p!= NULL) {
        dprint(p->more);
        dprint( p->same_more);
        printf("%s %d\n", p->word, p->count);
        dprint( p->same_less);
        dprint(p->less);
    }
    return p;
}

struct node *alloc(){
    return ((struct node *) malloc(sizeof(struct node)));
}