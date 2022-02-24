#include <stdio.h>
#include <stdlib.h>

int filecomp(int argc, char *argv[], int line, int character);
int errorchecker(FILE *f1p, FILE *f2p, char *file1, char *file2);
int compare(FILE *f1p, FILE *f2p, int line, int character);

int main(int argc, char *argv[]) {
    int line = 1;
    int character = 0;
    --argc;
    ++argv;

    filecomp(argc, argv, line, character);
    exit(0);
}

int filecomp(int argc, char *argv[], int line, int character){
    char file1[100];
    char file2[100];
    char *file1p = file1;
    char *file2p = file2;
    FILE *f1p;
    FILE *f2p;

    if(argc <=2){
        if (scanf("%s", file1) != EOF && scanf("%s", file2) != EOF) {
            f1p = fopen(file1, "r");
            f2p = fopen(file2, "r");
            errorchecker(f1p, f2p, file1, file2);
            compare(f1p, f2p, line, character);
        }
        else {
            fprintf(stderr, "Error: need more than two files as arguments or in stdin");
            exit(1);
        }
    }
    else if (argc > 2){
        f1p = fopen(file1p = *++argv, "r");
        f2p = fopen(file2p = *++argv, "r");
        errorchecker(f1p, f2p, file1p, file2p);
        compare(f1p, f2p, line, character);
    }
    exit(0);
}

int errorchecker(FILE *f1p, FILE *f2p, char *file1, char *file2){
    if (f1p  == NULL) {
        printf("Error: Can't open %s", file1);
        exit(1);
    }
    else if (f2p  == NULL) {
        printf("Error: Can't open %s", file2);
        exit(1);
    }
}

int compare(FILE *f1p, FILE *f2p, int line, int character){
    int c1;
    while((c1 = getc(f1p)) == getc(f2p)) {
        if(c1 == '\n')
            line++;
        character++;
    }
    printf("Different at line:%d and character:%d\n", line, character);
}