#include <stdio.h>

int main() {
    /* program to count blanks, tabs and newlines */
    int c, blanks = 0, tabs =0, newlines=0;

    while((c= getchar())!= EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }
        printf("Blanks = %d,\nTabs = %d,\nNewlines = %d", blanks,tabs,newlines );
}