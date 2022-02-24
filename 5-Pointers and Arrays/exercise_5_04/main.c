#include <stdio.h>

int get_line(char *s, int lim);
int a_to_i(char *s2);
char *i_to_a(char *s3, int j);
double a_to_f(char *s4);
char *f_to_a(char *s5, double l);
void reverse(char *s6);
char strlen(char *s6);
int index(char *s7, char *t);
#define NUMBER '0'
#define MAXOP 20
#define TOOBIG '9'
#define OPERAND_MIN 42
#define OPERAND_MAX 47
int getop(char *s, int lim);
int getch();
void ungetch(int c);

int main() {
    int lim = 1000;
    char s[lim];
    int length;

    length = get_line(s, lim);
    printf("Line: %s\nlength: %d\n",s, length);

    char *s2 = "  -129921";
    int i;
    i = a_to_i(s2);
    printf("alphabet to integer: %d\n", i);

    int j = -128092;
    char s3[lim];
    i_to_a(s3, j);
    printf("integer to alphabet: %s\n", s3);

    char *s4 = "  129.345  ";
    double k;
    k = a_to_f(s4);
    printf("alphabet to float: %0.3f\n", k);

    double l = -1280.92012;
    char s5[lim];
    f_to_a(s5, l);
    printf("Float to alphabet: %s\n", s5);

    char s6[] = "This is a reversed string";
    reverse(s6);
    printf("%s\n", s6);

    char *s7 = "Find that index";
    char *t = "ind";
    printf("Index of \"%s\" is: %d\n", t, index(s7, t));

    int op;
    char s8[1000];
    char *p8 = s8;
    char *p9 = s8;
    while((op = getop(s8, MAXOP)) != EOF) {
        if (op == NUMBER){
            printf("Number: ");
            while (*p9 != '\0') {
                printf("%c", *p9++);
            }
            printf("\n");
            p9 = p8;
        }
        if (op >= OPERAND_MIN && op <= OPERAND_MAX)
            printf("Type: %c\n",op);
    }

    return 0;
}

int get_line(s, lim)    /* getline pointer version */
char *s;
int lim;
{
    char *i = s;
    int c;
    while(s-i < lim-1 && (c = getchar())!= EOF && c != '\n')
        *s++ = c;
    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return (s-i);
}

int a_to_i(s2)
char *s2;
{
    int i=0, sign=1;
    for(;*s2 ==' ' || *s2 == '\t' || *s2 == '\n'; *s2++)
        ;
    if(*s2 == '-' || *s2 =='+')
        sign = *s2++ == '-'? -1 : 1;
    while(*s2 >= '0' && *s2 <= '9')
        i = i *10 + *s2++ -'0';
    return i*sign;
}

char *i_to_a(s3, j)
char *s3;
int j;
{
    int i ;
    if (j<0) {
        *s3++ = '-';
        j = j * -1;
    }
    if (j>0) {
        i = j % 10;
        j /= 10;
        s3 = i_to_a(s3, j);
        *s3++ = i +'0';
        *s3= '\0';
    }
    return s3;
}

double a_to_f(s4)
char *s4;
{
    int i =0, power = 1;
    double sign;

    for(;*s4 == ' ' || *s4 == '\n' || *s4 == 't'; s4++)
        ;
    sign = *s4 == '+' ? 1: -1;
    while(*s4 >= '0' && *s4 <= '9') {
        i = i * 10 + *s4++ - '0';
    }
    if (*s4 == '.')
        s4++;
    while(*s4 >= '0' && *s4 <= '9'){
        i = i *10 + *s4++ -'0';
        power *= 10;
    }
    return(sign * i /power);
}

int length = 1;
int z = 0;

char *f_to_a(s5, i)
char *s5;
double i;
{
    int j, k=0;
    if (i<0) {
        *s5++ = '-';
        i *= -1;
    }

    if(length == 1) {
        int l = i;
        while ((l /= 10) > 0)
            length++;
        while ((int) i < i) {
            i *= 10;
        }
    }
    if (k>0 || i > 0){
        int k = i;
        j = k % 10;
        k /= 10;
        s5 = f_to_a(s5, k);
        if (z == length)
            *s5++ = '.';
        *s5++ = j + '0';
        *s5 = '\0';
        z++;
    }
    return s5;
}

void reverse(s6)
char *s6;
{
    char x;
    char *p = &s6[strlen(s6)-2];
    while(p > s6){
        x = *s6;
        *s6++ = *p;
        *p-- = x;
    }
}

char strlen(s6)
char *s6;
{
    char *k = s6;
    while(*s6++ != '\0')
        ;
    return s6-k;
}

int index(s7, t)
char *s7;
char *t;
{
    char *i = s7;
    char *j;
    int k = 0;
    for(; *s7 != '\0';s7++){
        if (*s7 == *t)
            j = s7;
        for(;*s7 == *t && *s7 != '\0'; s7++, t++, k++)
            ;
        if (*t == '\0')
            return j -i;
        else {
            t -= k;
            k =0;
        }
    }

    return -1;
}

int getop(s8, lim)
char *s8;
int lim;
{
    int c;
    char *sp = s8;
    while((c = getch()) == ' ' || c == '\t' || c == '\n')
        ;
    if (c != '.' && (c < '0' || c > '9'))
        return c;
    *s8++ = c;
    while( (c= getchar()) >= '0' && c <= '9' && (s8-sp) < lim)
        *s8++ = c;
    if(c == '.' && (s8-sp) < lim){
        *s8++ = c;
        while( (c= getchar()) >= '0' && c <= '9' && s8-sp < lim)
            *s8++ = c;
        }
    if(s8-sp < lim) {
        ungetch(c);
        *s8 = '\0';
        return (NUMBER);
    }
    else{
        while(c != '\n')
            c = getchar();
        *--s8= '\0';
        return (TOOBIG);
    }
}
#define BUFSIZE 100
char buf[BUFSIZE];
char *pf= buf;
char *bf = buf;
int getch()
{
    return(bf - pf >0 ? *bf-- : getchar() );
}

void ungetch(c) /* push character back on input */
int c;
{
    if(bf-pf > BUFSIZE)
        printf("ungetch: too many characters");
    else
        *bf++ = c;
}