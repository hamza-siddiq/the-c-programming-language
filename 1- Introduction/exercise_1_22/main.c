#include <stdio.h>

int commentremover(char quote[], char forwardslash[]);
int main(){
    char quote[1];
    char forwardslash[1];
    commentremover(quote, forwardslash);
}

int commentremover(quote, forwardslash)
char quote[];
char forwardslash[];
{
    int c;
    while((c = getchar())!=EOF) {
        if (c == '\'' || c == '\"') {
            putchar(c);
            quote[0] = c;
            while ((c = getchar()) != (quote[0]))
                putchar(c);
        }
        else if (c == '/') {
                forwardslash[0]='c';
                c = getchar();
                if(c=='/') {
                    while (c != '\n')
                        c = getchar();
                }
                if(c =='*'){
                    c=getchar();
                    while(c != ('/'))
                        c= getchar();
                }
                else{
                    printf("%s", forwardslash);
                }
            }
        else {
            putchar(c);
            }
        }
    return 0;
    }