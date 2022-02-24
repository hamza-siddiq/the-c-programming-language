#include <stdio.h>

int c3_finder(char s1[],char s2[]);
int squeeze (char s1[], char s2[], int c3);

int main() {
    /*
     * Delete each character in string s1, which matches any character in s2
     */

    char s1[] = "mJzB9rkKZD";                   /* String 1 */
    char s2[] = "9r4AOuCsz0";                   /* String 2 */

    int c3 = c3_finder(s1, s2);                 /* Find length of String 3*/
    squeeze(s1, s2, c3);
    return 0;
}

int squeeze(s1, s2, c3)  /* Delete each character in string s1, which matches any character in s2 */
char s1[];
char s2[];
int c3;
{
    int c1 = 0;
    int c2 = 0;
    char s3[c3];

    c3 = 0;                 /* c3 set to zero after using it for assignment to access string 3, from char 0*/
    while(s1[c1] != '\0'){
        while(s2[c2] != '\0' && s1[c1] != s2[c2]) /* check till end of string 2, or if both are equal, stop checking*/
            c2++;
        if (s2[c2] == '\0')                         /* if string is end, we know the character was not found */
            s3[c3++] = s1[c1];                      /* so we add it to string 3 */
            c2 = 0;                          /* we set character of string 2 to 0 again, since it is end of string*/
        c1++;                                /* check next character of string 1*/
    }
    s3[c3] ='\0';
    printf("%s", s3);
    return 0;
}

int c3_finder(s1,s2) /* finds the total characters of string 3, by checking length of string 1 and 2 */
char s1 [];
char s2 [];
{
    int c1 = 0;
    int c2 = 0;
    int c3;

    while(s1[c1++] != '\0')
        ;
    while(s2[c2++] != '\0')
        ;
    --c2;
    --c1;

    if (c1 > c2)
        c3 = c1;
    else
        c3 = c2;

    return c3;
}