#include <stdio.h>

int main() {
    /*
     * Write a loop equivalent to the for loop above without using &&
     */
    int i =0;
    int lim = 1000;
    char s[lim];
    int c;

    while (i<lim-1){
        if((c=getchar()) != 0){
            if (c != EOF){
                s[i] = c;
            }
        }
        ++i;
    }
    printf("%s",s);
    return 0;
}
