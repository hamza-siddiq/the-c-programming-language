#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void cat(int argc, char *argv[]);
void error(char *s1, char *s2);

int main(int argc, char *argv[]) {
    --argc, ++argv;
    cat(argc,argv);

    return 0;
}

void cat(int argc, char *argv[]){
    int n, f;
    char *buf[BUFSIZ];

    if (argc == 1){
        while((n = read(0, buf, BUFSIZ)) > 0)
            if(write(1, buf, n) != n)
                error("Can't write stdin", NULL);
    }
    else
        while(--argc>0) {
            if ((f = open(*++argv, 0)) == -1)
                error("Can't open file %s", *argv);
            while((n = read(f, buf, BUFSIZ))>0) {
                if (write(1, buf, n) != n)
                    error("Can't write %s", *argv);
            }
            printf("\n");
            close(f);
        }
}

void error(char *s1, char *s2){
    printf(s1,s2);
    printf("\n");
    exit(1);
}