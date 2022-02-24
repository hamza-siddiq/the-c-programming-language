#include <stdio.h>
int upper_to_lower();
int main() {
    /* upper to lower character converter using conditional expression*/
    upper_to_lower();
}

int upper_to_lower()
{
    int c;
    while(( c = getchar()) != EOF) {
        c = c >= 65 && c <= 90 ? c + 32 : c;
        printf("%c", c);
    }

}