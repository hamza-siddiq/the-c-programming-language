#include <stdio.h>

int main() {
    /* replace each string of one or more blanks by a single blank */
    int c;

    while((c=getchar())!= EOF){
        if (c == ' '){
            putchar(c);
            while((c=getchar())==' ');
    }
            putchar(c);
    }
}