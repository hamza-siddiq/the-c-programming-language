#include <stdio.h>
int identical_line_remover(int c,char s1[],char s2[]);
int main() {
    int c;
    char s1[1000];
    char s2[1000];

    identical_line_remover(c, s1,s2);
    return 0;
}

int identical_line_remover(c, s1,s2)
int c;
char s1[];
char s2[];
{
    int k;
    int i = 0;
    int j = 0;
    while(c != EOF) {
        while ((c = getchar()) != '\n' && (c != EOF))           /* loop till new line or EOF */
            s2[i++] = c;                                        /* store it in array 2*/
        s2[i] = '\0';
        k = 0;
        while (s1[k] == s2[k])                                  /* compare array 2 to array 1*/
            k++;
        k--;
        if (k == i) {                                           /* if length of same characters is the same */
            i = 0;
            continue;                                           /* restart to get a new second array */
        }

        i =0;
        while((s1[i++] = s2[j++]) != '\0');                     /* if length is different, make array 2, equal to array 1*/
        s2[j] = '\0';
        i =0;
        j =0;
        printf("%s\n", s1);                                     /* and print array 1*/
    }
}