#ifndef EXERCISE_6_08_HEADER_H
#define EXERCISE_6_08_HEADER_H

#endif //EXERCISE_6_08_HEADER_H

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
int getword();
int defchecker(char c, struct element *pa);
struct nlist *install();
struct nlist *lookup(char *s);
int hash(char *name);
void ungetch(char c);
int getch();