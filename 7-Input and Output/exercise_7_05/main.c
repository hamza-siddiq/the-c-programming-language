#include <stdio.h>
#include <stdlib.h>

void getfiles(char **files, char **argv, int *argc);
void printfiles(char **files);
int main(int argc, char *argv[]) {
    char *files[100];
    argc--, argv++;
    if (argc > 1){
        while(--argc > 0){
            getfiles(files, ++argv, &argc);
        }
        printfiles(files);
    }
    else
        printf("File name missing in arguments.");
    exit(0);
}

void getfiles(char **files, char **argv, int *argc){
    char *x;
    for(;*argv!= NULL;argv++, (*argc)--, files++) {
        x = *files = malloc(sizeof(char[100]));
        for (;(*x = **argv)!= '\0'; (*argv)++, x++);
    }
    *files= NULL;
}

#define MAXLINE 1000
void printfiles(char **files){
    int pagecount = 1;
    FILE * fp;
    char line[1000];

    for(;*files!=NULL; files++, pagecount++){
        printf("Page: %d\n", pagecount);
        fp = fopen(*files, "r");
        while(fgets(line, MAXLINE, fp) != NULL)
            fputs(line, stdout);
        printf("\n");
    }
}