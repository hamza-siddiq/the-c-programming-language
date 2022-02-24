#include <stdio.h>

int main() {
    /* Prints the words in its input, one per line*/
    int c;

    while ((c = getchar()) != EOF) {
        for (;c!=EOF  && c != ' ' && c != '\t' && c != '\n'; c = getchar()) {   /* get word */
            putchar(c);
        }
        printf("\n");                                                          /* new line */
        for(;c == ' ' || c == '\t' || c == '\n';(c=getchar())!=EOF);           /*skip whitespace*/
        putchar(c);                                                          
    }
}