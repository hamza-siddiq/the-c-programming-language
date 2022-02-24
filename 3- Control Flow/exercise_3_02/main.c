#include <stdio.h>
int length_calculator(char s1[]);
int expand(char s1[],char s2[]);

int main() {
    /* expands short-hand notations like a-z into complete lists like abc...xyz */
    char s1[] = "Lorem ipsum dolor sit amet, -A-Z consectetur A-Z adipiscing a-z elit. "
                "Phasellus -a-z non purus -a-z- id urna 2-4 egestas 0-9- viverra.";
    int length = length_calculator(s1);
    char s2[length*5];

    expand(s1,s2);
    printf("%s", s2);
}

int length_calculator(s1)
char s1[];
{
    int i =0;
    while(s1[i] != EOF)
        i++;
    return i;
}
int expand(s1,s2)
char s1[];
char s2[];
{
    int i = 0;          /* incrementor of s1 */
    int c1, c2, c3;     /* first, second, and third character */
    int j = 0;          /* incrementor of s2 */
    while((c2 = s1[i]) != EOF){
        switch(c2) {
            case '-':
                if ((c1 = s1[i - 1]) != ' ' && c1 != '\n' && c1 != '\t' && /* checks to see that c1 and c3 are not empty */
                    (c3 = s1[i + 1]) != ' ' && c3 != '\n' && c3 != '\t') {
                    for (++c1; c1 <= c3; c1++)                             /* loops from ++c1 (had already got c1) to c3 */
                        s2[j++] = c1;
                    i++;i++;                                        /* increment twice since we already got c3, so skip c3 */
                    break;
            }
            default:
                s2[j++] = s1[i++];
        }
    }
    return j;
}