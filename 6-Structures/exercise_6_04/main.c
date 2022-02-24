#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define erase(a,b) a = temp_v; *a = NULL; b = temp_a; *b = '\0'
struct tnode {
        char *var;
        int print;
        struct tnode *less;
        struct tnode *more;
        struct tnode *idn_less;
        struct tnode *idn_more;
};

void getvars(char **v, char *a);
int skipspace(int c);
int gettype(char *w, int c, char *word);
int reservecheck(char *w, char *word);
int addvar(int c, char **v, char **a);

struct tnode *tree(struct tnode *p, int parameter, char **v, int print);
struct tnode *talloc(void);
int idncmp(char *v, char *var, int parameter);

void non_idn_remover(struct tnode *p);
void treeprint(struct tnode *p);



int main(int argc,char *argv[]) {
    char array[1000];            /* array with all the variables */
    char *a = array;
    char *var[100];              /* pointer to each variable */
    char **v = var;
    int parameter;
    int print =0;
    struct tnode *p = NULL;

    argc--;argv++;
    if (argc >= 2)
        parameter = **++argv -'0';
    else
        parameter = 7;

    getvars(v,a);
    for(;*v!=NULL;v++){
        p= tree(p, parameter, v, print);
    }
    non_idn_remover(p);
    treeprint(p);

    return 0;
}

void getvars(char **v, char *a)
{
    int c;                       /* a character*/
    char word[100];             /* an array with a word */
    char *w;           /* a variable, word, and a reserved word character*/
    char **temp_v;
    char *temp_a;

    while((c = getchar())!= EOF) {
        c = skipspace(c);
        c = gettype(w, c, word);
        if (reservecheck(w, word)) {
            c = skipspace(c);
            temp_v = v;
            temp_a = a;
            c = addvar(c, v, &a);
            while (c == ',') {
                v++;
                c = skipspace(c);
                c = addvar(c, v, &a);
            }
            if (c != ';' && c != '[' && c != ' ') {
                erase(v,a);
            } else if (c == ' ' && getchar() != '='){
                erase(v,a);
            }
            else
                v++;
        }
    }
}

struct tnode *tree(struct tnode *p, int parameter, char **v, int print)
{
    int idn_cmp, str_cmp;

    if (p == NULL){
        p = talloc();
        p->var = *v;
        p->print =1;
        p->less= p->more = p->idn_less = p->idn_more = NULL;
    }
    else if ((idn_cmp = idncmp(*v, p->var, parameter))<0) {
        p->idn_less = tree(p->idn_less, parameter, v, print);
    }
    else if (idn_cmp>0){
        p->idn_more = tree(p->idn_more, parameter, v, print);
        }
    else if ((str_cmp = strcmp(*v, p->var))<0) {
        p->less = tree(p->less, parameter, v, print);
    }
    else if (str_cmp>0){
        p->more = tree(p->more, parameter, v, print);
    }
    return p;
}

int addvar(int c, char **v, char **a)
{
    *v = *a;
    for (; c != EOF && (isalpha(c) || isdigit(c) || c == '_') ;  **a = '\0', c = getchar()) {
        (**a) = c; /* add the variable to the variable array */
        (*a)++;
    }
    (*a)++;
    return c;
}

int idncmp(char *v, char *var, int parameter)
{
    char *pvar = var;
    char *pv = v;
    for(;*pv++ == *pvar++;)
        ;
    pv--;
    if (pv-v >= parameter){
        return strcmp(v, var);
    }
    return 0;
}

int gettype(char *w, int c, char *word)
{
    for(w = word; c != ' ' && c!='\n' && c!='\t' && c != EOF; c=getchar(), *w = '\0')
        *w++ = c;                                           /* Add  name to word array */
    return c;
}

int reservecheck(char *w, char *word){
    char **r;
    char *reserved[] = {"char", "double", "float", "int", "long", "register", "short", "signed", NULL};

    for(w = word, r = reserved; *r!= NULL; w=word, r++)     /* Go to the next reserved word*/
        if(strcmp(w, *r) ==0)
        {
            return 1;
        }
    return 0;
}

int skipspace(int c){
    for(;c != EOF && (isalpha(c) == 0) ;c = getchar());  /* skip till you get to a name */
    return c;
}

struct tnode *talloc(){
    return((struct tnode *) malloc(sizeof(struct tnode)));
}
int number = 0;
void treeprint(struct tnode *p){
    if(p != NULL) {
        treeprint(p->less);
        if ((p->print) != 0){
            treeprint(p->idn_less);
            printf("%s\n", p->var);
            treeprint(p->idn_more);
        }
        treeprint(p->more);
    }
}

void non_idn_remover(struct tnode *p){
    if(p != NULL) {
        non_idn_remover(p->less);
        if((p->idn_more == NULL) && (p->idn_less == NULL))
            p->print = 0;
        non_idn_remover(p->more);
    }
}

