#include <stdio.h>

int main() {
    /* Replace tab by \t, backspace by \b, and backslash by \ */
    int c;
    while((c=getchar())!= EOF){
        switch(c) {
            case ('\t'):
                printf("\\t");
                break;
            case ('\b'):
                printf("\\b");
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;
}