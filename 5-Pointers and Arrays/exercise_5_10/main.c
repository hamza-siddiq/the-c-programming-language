#include <stdio.h>
#define MAXLEN 1000
#define MAXPOINTERS 100
int stringcmp(char *s, char *s2);
int arraymaker(char **parray, char *array);
int main(int argc, char **argv) {
    int length;
    char array[1000];
    char *parray[MAXPOINTERS];
    int n = 10;
    argc--;
    argv++;
    if (argc == 3){
        if (stringcmp("tail", *argv++)) {
            if (stringcmp("-n", *argv++)) {
                if (**argv >= '0' && **argv <= '9')
                    n = **argv - '0';
                else {
                    printf("n value missing");
                    return 0;
                }
            }
        }
        else
            printf("Tail command missing at argument 1");
    }
    else if (argc >3) {
        printf("Arguments more than 3");
        return 0;
    }
    else if(argc == 2){
        printf("n value missing");
        return 0;
    }

    length = arraymaker(parray, array);
    if(length>=n){
        char **p_start = parray;

        p_start += (length - n);
        while(*p_start != NULL){
            printf("%s\n", *p_start++);
        }
    }
    return 0;
}

int arraymaker(char **parray, char *array)
{
    *parray = array;
    char *a = array;
    char **p = parray++;

    int c;
    while((c = getchar()) != EOF && array-a < MAXLEN){
        if (c == '\n' && parray-p < MAXPOINTERS){
            *array = '\0';
            *parray++ = ++array;
        }
        else{
            *array++ =c;
        }
    }
    return parray - p;
}

int stringcmp(char *s, char *s2)
{
    while(*s++ == *s2++){
        if (*s == '\0' && *s2=='\0'){
            return 1;
        }
    }
    return 0;
}