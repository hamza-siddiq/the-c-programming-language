#include <stdio.h>
#define EMPTY '\0'

int new_line_checker(int c,int n, char newlinechar[]);
int single_quote_checker( int c,int n);
int double_quote_checker(int c,int n);

int parentheses_checker( int c, int n, char charop[], char charcp[], int parenthesesno, char openparentheses[], char closeparentheses[]);
int brackets_checker(int c, int n, char charob[], char charcb[], int bracketsno, char openbrackets[], char closebrackets[]);
int braces_checker(int c, int n, char charobr[], char charcbr[], int bracesno, char openbraces[], char closebraces[]);

int parentheses_comparison(char charop[], char charcp[], char openparentheses[], char closeparentheses[]);
int brackets_comparison(char charob[], char charcb[], char openbrackets[], char closebrackets[]);
int braces_comparison(char charobr[], char charcbr[], char openbraces[], char closebraces[]);

int line_comment_checker(int c, int n, char newlinechar[]);
int comment_checker(int c,int n, char newlinechar[], char commentline[]);

int main() {
    /*
     * A program to debug a C program by displaying rudimentary syntax errors like
     * unbalanced parentheses, brackets and braces,
     * quotes: both single and double,
     * and comments.
     */
    int c;
    int n = 1;              /*The line number */
    char newlinechar[1];    /* The first character of a new line */
    char commentline[1];
    commentline[0]= EMPTY;

    int parenthesesno = 0;
    char charop[1];
    charop[0] = '0';
    char charcp[1];
    charcp[0] = '0';
    char openparentheses[400];
    char closeparentheses[400];
    
    int bracketsno = 0;
    char charob[1];
    charob[0] = '0';
    char charcb[1];
    charcb[0] = '0';
    char openbrackets[400];
    char closebrackets[400];

    int bracesno = 0;
    char charobr[1];
    charobr[0] = '0';
    char charcbr[1];
    charcbr[0] = '0';
    char openbraces[400];
    char closebraces[400];

    while ((c = getchar()) != EOF) {
        n = new_line_checker(c, n, newlinechar);
        n = single_quote_checker(c, n);
        n = double_quote_checker(c, n);

        parenthesesno = parentheses_checker(c, n, charop, charcp, parenthesesno, openparentheses, closeparentheses);
        bracketsno = brackets_checker(c, n, charob, charcb, bracketsno, openbrackets, closebrackets);
        bracesno = braces_checker(c, n, charobr, charcbr, bracesno, openbraces, closebraces);

        n = comment_checker(c, n, newlinechar, commentline);

    }
    parentheses_comparison(charop, charcp, openparentheses, closeparentheses);
    brackets_comparison(charob, charcb, openbrackets, closebrackets);
    braces_comparison(charobr, charcbr, openbraces, closebraces);

    return 0;
}

int new_line_checker(int c, int n, char newlinechar[])
{
    while (c == '\n') {
        ++n;
        c = getchar();
    }
    newlinechar[0] = c;
    return n;
}

int single_quote_checker(c, n)
        int c;
        int n;
{
    if (c == '\'') {
        c = getchar();
        if (c == '\\') {
            getchar();
            c = getchar();
            if (c != '\'') {
                printf("Closing single quote missing at line %d\n", n);
            }
        } else if (c == '\'') {
            printf("Single quotes are empty at line %d\n", n);
        } else if (c == '\n') {
            printf("Closing single quote missing at line %d\n", n);
            ++n;
        } else {
            c = getchar();
            if (c != '\'') {
                printf("Single quotes are greater than one character at line %d\n", n);
            }
        }
    }
    return n;
}


int double_quote_checker(c, n)
        int c;
        int n;
{
    if (c == '\"') {
        c = getchar();
        if (c == '\"') {
            printf("Double quotes are empty at line %d\n", n);
        }
        c = getchar();
        while (c != '\"' && c != '\n')
            c = getchar();
        if (c == '\n') {
            printf("Closing double quote missing at line %d\n", n);
            ++n;
        }
    }
    return n;
}

int parentheses_checker(int c,int n,char charop[],char charcp[],int parenthesesno,char openparentheses[],char closeparentheses[])
{
    if (parenthesesno < 800) {
        if (c == '('){
            openparentheses[charop[0]] = n;
            charop[0] += 1;
            ++parenthesesno;
        }
        if (c == ')'){
            closeparentheses[charcp[0]] = n;
            charcp[0] += 1;
            ++parenthesesno;
        }
}
    else{
        printf("Greater than 800 parentheses");
    }
    return parenthesesno;
    }

int parentheses_comparison(charop, charcp, openparentheses, closeparentheses)
    char charop[];
    char charcp[];
    char openparentheses[];
    char closeparentheses[];
{
    while (charop[0] < charcp[0]) {
        printf("Missing character ( at %d or earlier\n", closeparentheses[charop[0]]);
        charop[0] += 1;
    }
    while (charcp[0] < charop[0]) {
        printf("Missing character ) at line %d or later\n", openparentheses[charcp[0]]);
        charcp[0] += 1;
    }
    return 0;
}

int brackets_checker(c, n, charob, charcb, bracketsno, openbrackets, closebrackets)
        int c;
        int n;
        char charob[];
        char charcb[];
        int bracketsno;
        char openbrackets[];
        char closebrackets[];
{
    if (bracketsno < 800) {
        if (c == '['){
            openbrackets[charob[0]] = n;
            charob[0] += 1;
            ++bracketsno;
        }
        if (c == ']'){
            closebrackets[charcb[0]] = n;
            charcb[0] += 1;
            ++bracketsno;
        }
    }
    else{
        printf("Greater than 800 brackets");
    }
    return bracketsno;
}

int brackets_comparison(charob, charcb, openbrackets, closebrackets)
        char charob[];
        char charcb[];
        char openbrackets[];
        char closebrackets[];
{
    while (charob[0] < charcb[0]){
        printf("Missing character [ at %d or earlier\n", closebrackets[charob[0]]);
        charob[0] += 1;
    }
    while (charcb[0] < charob[0]){
        printf("Missing character ] at line %d or later\n", openbrackets[charcb[0]]);
        charcb[0] += 1;
    }
    return 0;
}

int braces_checker(c, n, charobr, charcbr, bracesno, openbraces, closebraces)
        int c;
        int n;
        char charobr[];
        char charcbr[];
        int bracesno;
        char openbraces[];
        char closebraces[];
{
    if (bracesno < 800) {
        if (c == '{'){
            openbraces[charobr[0]] = n;
            charobr[0] += 1;
            ++bracesno;
        }
        if (c == '}'){
            closebraces[charcbr[0]] = n;
            charcbr[0] += 1;
            ++bracesno;
        }
    }
    else{
        printf("Greater than 800 braces");
    }
    return bracesno;
}

int braces_comparison(charobr, charcbr, openbraces, closebraces)
        char charobr[];
        char charcbr[];
        char openbraces[];
        char closebraces[];
{
    while (charobr[0] < charcbr[0]){
        printf("Missing character { at %d or earlier\n", closebraces[charobr[0]]);
        charobr[0] += 1;
    }
    while (charcbr[0] < charobr[0]){
        printf("Missing character } at line %d or later\n", openbraces[charcbr[0]]);
        charcbr[0] += 1;
    }
    return 0;
}

int comment_checker(c, n, newlinechar, commentline)
        int c;
        int n;
        char newlinechar[];
        char commentline[];
{
    if (c =='/' || newlinechar[0]=='/'){
        c = getchar();
        n = new_line_checker(c, n, newlinechar);
        if (c == '*') {
            commentline[0] = n;
            c = getchar();
            n = new_line_checker(c, n, newlinechar);
            while ( c != EOF && commentline[0] != EMPTY) {
                c = getchar();
                n = new_line_checker(c, n, newlinechar);
                if (c == '*') {
                    c = getchar();
                    n = new_line_checker(c, n, newlinechar);
                    if (c == '/') {
                        commentline[0] = EMPTY;
                    }
                }
                if (c == EOF) {
                    printf("Comment at line number %d has not been closed \n", commentline[0]);
                }
            }
        }
        else
            n = line_comment_checker(c, n, newlinechar);
    }
    else if (c == "*" || newlinechar[0] == '*'){
        c = getchar();
        n = new_line_checker(c, n, newlinechar);
        if (c == '/'){
            printf("Comment at line number %d has not been opened \n", n);
        }
    }
    return n;
}

int line_comment_checker(c, n, newlinechar)
int c;
int n;
char newlinechar[];
{
        if (c == '/'){
            while (c != '\n' && c != EOF){
                c = getchar();
            }
            n = new_line_checker(c, n, newlinechar);
        }
        else if (c != '*'){
            if (c=='\n'){
                printf("Missed line character: / or multiple line comment character: * at line %d \n", n-1);
            }
            else {
                printf("Missed line character: / or multiple line comment character: * at line %d \n", n);
            }
        }
    return n;
    }

