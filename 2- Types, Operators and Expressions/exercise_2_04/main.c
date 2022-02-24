#include <stdio.h>
int any(char s1[], char s2[]);
int max_calculator(char s1[], int c1);

int main() {
    /*
     * Returns the first location in string s1, where any character from string s2 occurs
     */
    char s1[] = "zx4DX07RiL";
    char s2[] = "Jft2a5ylt5";

    int min = any(s1,s2);
    printf("%d", min);
}

int any(s1,s2)                                      /* finds first location */
char s1[];
char s2[];
{
    int c1 = 0;
    int c2 = 0;
    int min = max_calculator(s1, c1);
    int original_min = min;                     /* makes the min equal to the value of '\0' */

    while(s2[c2] != '\0'){
        while(s1[c1] != '\0'){
            if (s1[c1] == s2[c2] && c1<min)         /* if characters from both strings are equal, and */
                min =c1;                            /* character of first string is less than the min, make it min*/
            c1++;
        }
        c1 =0;
        c2++;
    }
    if (min == original_min)                        /* if minimum is the same as value at '\0' i.e s1 contains no char*/
        min = -1;                                   /* from s2, make min -1*/

    return min;
}

int max_calculator(s1, c1)                      /* calculates where s1 becomes '\0' */
char s1[];
int c1;
{
    while(s1[c1++] != '\0')
        ;
    return c1;
}