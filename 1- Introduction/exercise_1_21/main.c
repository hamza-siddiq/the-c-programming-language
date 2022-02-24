#include <stdio.h>

int foldline(char array[]);

int main() {
    /* Program to fold long input lines after the last non-blank character that occurs before the n-th column
     * of input, where n is a parameter. Make sure your program does something intelligent with very long
     * lines, and if there are no blank or tabs before the specified column.
     */

    char array[50]; /* Array to hold blanks */
    foldline(array);
    return 0;
}

//int forloop
//char array[];
//these are comments to be used in exercise_22

int foldline(char array[])
/* Program that folds a line after it is blank */
{
    int c=0,wordcount = 0,arraycount;
    while(c!=EOF){                                                          /* get every character till the last character*/
        while((c=getchar())!= '\t' && c!= ' ' && wordcount<50 && c!= EOF) { /* loop checks if character is not blank */
            printf("%c", c);                                                /* and then prints the character*/
            wordcount++;
        }
        wordcount++;
        for (arraycount=0;c== ' ' || c == '\t' && wordcount <50; arraycount++){/* loops and checks if character is blank */
            array[arraycount] = c;                                             /* adds it to an array */
            c = getchar();
            wordcount++;
        }
        if (wordcount >= 50){                                                   /* if words are more than 50 */
            printf("%c", '\n');                                                 /* make a new line */
            wordcount = 0;                                                      /* start counting words for new line*/
        }
        if (arraycount >0) {                                                    /* if array has blank characters */
            printf("%s", array);                                                /* print them */
            if (c != EOF)
                putchar(c);
        }
    }
        return 0;
    }