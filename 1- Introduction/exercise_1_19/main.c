#include <stdio.h>

int arraymaker(char array[], char extraspace[], int lim, char runit[]);

int main()
{   
    int lim = 1000;             /* the limit of the array */
    char array[lim];            /* the array */
    char extraspace[1];         /* a placeholder for an extra space that we might encounter if tab is at lim-1 */
    extraspace[0]='0';          /* in the case that lim-1 is tab, we would add it to a placeholder */
    char runit[1];              /* we will run it while runit till the end of file,
                                    at which point runit will become 0 */
    runit[0]='1';


    while (runit[0] != '0'){
        arraymaker(array, extraspace, lim, runit);  /* Array maker function gets characters upto the lim
                                                       and assigns them to an array  */
        printf("%s", array);
        if (extraspace[0] == ' ')
            printf("%c", extraspace[0]);
        }
        return 0;
}

int arraymaker(array, extraspace, lim, runit)   /* Array maker function gets characters upto the lim
                                                   and assigns them to an array  */
char array[];
char extraspace[];
int lim;
char runit[];
{
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && i != lim; ++i) {   /* loop and get character till character
                                                                    is end of file or limit. */
        extraspace[0] = '\0';
        if (c != '\t')
            array[i] = c;
        else if (i < (lim - 1)) {
            array[i] = ' ';
            ++i;
            array[i] = ' ';
        }
        else if (i == lim - 1) {
            array[i] = ' ';
            extraspace[0] = ' ';
        }
    }
        array[i] = '\0';
        if (i < lim){
            runit[0]='0';
        }
    return 0;
}