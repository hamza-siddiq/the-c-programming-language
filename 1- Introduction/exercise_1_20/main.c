#include <stdio.h>

int entab(int tabsandspaces, int totaltabs, int totalspaces);
int main(){
    int tabsandspaces = 0;
    int totaltabs =  tabsandspaces / 4 ;
    int totalspaces = tabsandspaces % 4;
    entab(tabsandspaces, totaltabs, totalspaces);
}

int entab(tabsandspaces, totaltabs, totalspaces)
int tabsandspaces;
int totaltabs;
int totalspaces;
{
    int i, j, c;
    while((c=getchar())!=EOF) {
        if ((c != ' ') && (c != '\t')) {
            putchar(c);
        } else {
            while ((c == ' ') || (c == '\t')) {
                ++tabsandspaces;
                c = getchar();
            }
            totaltabs = tabsandspaces / 4;
            totalspaces = tabsandspaces % 4;
            for (i = 1; i <= totaltabs; i++)
                printf("%c", '\t');
            for (j = 1; j <= totalspaces; j++)
                printf("%c", ' ');
            if ((c != EOF))
                putchar(c);
        }
        tabsandspaces =0;
    }
    return 0;
}