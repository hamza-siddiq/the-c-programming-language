#include <stdio.h>
#include <stdlib.h>

void nxadder(char *argv[], int *n, int *x);
void nameadder(char *argv[], char *name);
void filesadder(char *argv[], int *argc, char *files[]);
void printer(int n, int x, char *name, char *files[]);
void printfile(FILE *fp , int x, int n, char *name);
int index(char *name, char *line);

int main(int argc, char *argv[]) {
    int n = 0, x = 0;
    int name_collected = 0;
    char name[100];
    char *files[100], **fp = files; *fp= NULL;
    --argc, ++argv;

    if (argc > 1){
        while(--argc>0) {
            if (**++argv == '-')
                nxadder(argv, &n, &x);
            else if (name_collected == 0) {
                nameadder(argv, name);
                name_collected = 1;
            } else {
                filesadder(argv, &argc, files);
            }
        }
    }
    else {
        fprintf(stderr,"Very few arguments");
        exit(1);
    }

    printer(n, x, name, files);
    exit(0);
}

void nxadder(char *argv[], int *n, int *x){
    int c;
    for((*argv)++;(c = **argv)!= '\0'; (*argv)++) {
        switch (c) {
            case 'n':
                *n = 1;
                break;
            case 'x':
                *x = 1;
                break;
            default: {
                fprintf(stderr, "Invalid character");
                exit(1);
            }
        }
    }
}

void nameadder(char *argv[], char *name){
    for(;(*name++ = **argv) != '\0';(*argv)++);
}

void filesadder(char *argv[], int *argc, char *files[]){
    char *x;
    for (; *argv != NULL; argv++, (*argc)--,files++){
        x = *files = malloc(sizeof(char[100]));
        for(;(*x = **argv)!='\0';x++, (*argv)++);
    }
    *files = NULL;
}

void printer(int n, int x, char *name, char *files[]){
    FILE *fp;
    if (*files != NULL) {
        for(;*files != NULL; files++) {
            fp = fopen(*files, "r");
            printf("%s\n", *files);
            printfile(fp, x, n, name);
        }
    }
    else
        printfile(stdin, x, n, name);
}

void printfile(FILE *fp , int x, int n, char *name){

    char line[1000];
    int MAXLINE = 1000;
    int linenum =1;
    for(;fgets(line, MAXLINE, fp)!= NULL; linenum++)
        if (index(name, line) != x) {
            if(n == 1)
                printf("%d. ", linenum);
            printf("%s", line);
        }
    printf("\n\n");
}

int index(char *name, char *line){
    char *np = name;
    for(;*line !='\0'; np = name)
        for(;*np++ == *line++;)
            if (*np == '\0')
                return 1;
    return 0;
}