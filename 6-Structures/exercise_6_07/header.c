#include <stdlib.h>
#include <string.h>
#include <printf.h>
struct nlist{
    char *name;
    char *def;
    struct nlist *next;
};
struct element{
    char *name;
    char *def;
};
int check(char c, struct element *pa);
struct nlist *install();
struct nlist *lookup(char *s);
int hash(char *name);
void erase(char *s);
void remov(struct nlist *p,struct nlist *np);