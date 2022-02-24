#include <stdio.h>

int main() {
    /* prints the words in its input, one per line */
    int c;

    while((c=getchar())!=EOF){
        if(c >= 'A' && c<='Z' || c >= 'a' && c<='z') {
            putchar(c);
            for(c=getchar();c >= 'A' && c <= 'Z' || c >= 'a' && c<='z'
            || c >= '0' && c <= '9' || c == '\''; c=getchar())
                putchar(c);
            putchar('\n');
        }
    }
}