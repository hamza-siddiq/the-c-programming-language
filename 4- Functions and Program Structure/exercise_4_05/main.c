#include <stdio.h>
#define MAXOP 20            /* max size of operand, operator*/
#define NUMBER '9'          /* signal that number found */
#define TOOBIG '0'          /* signal that string is too big */
void clear();
double atof(), pop(), push();
int getop(), getch(), length();
void ungetch(),ungets(),unary_minus_check(),unary_plus_check();

int main() {                /* reverse Polish desk calculator */
    int type;
    char st[MAXOP];
    double op2;
    extern int unary_minus, unary_plus;
    extern char buf[];
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
    while((type = getop(st, MAXOP))!= EOF){
        switch(type) {
            case NUMBER:
                if (unary_minus){
                    push(atof(st) * unary_minus);
                    unary_minus = 0;
                }
                else {
                    unary_plus = 0;
                    push(atof(st));
                }
                break;
            case '+':
                unary_plus_check();
                if (unary_plus){
                    continue;
                }
                push((double)pop() + (double)pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                unary_minus_check();
                if (unary_minus){
                    continue;
                }
                op2 = pop();
                push((double)pop() - (double)op2);
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '=':
                printf("\t%f\n",push(pop()));
                break;
            case 'c':                                   /* alphabets for variables names start */
                if (c>=0 || c<= 0){
                    push(atof(c));
                }
                else {
                    clear();
                }
                break;
            case 'a':
                push(atof(a));
                break;
            case 'b':
                push(atof(b));
                break;
            case 'd':
                push(atof(d));
                break;
            case 'e':
                push(atof(e));
                break;
            case 'f':
                push(atof(f));
                break;
            case 'g':
                push(atof(g));
                break;
            case 'h':
                push(atof(h));
                break;
            case 'i':
                push(atof(i));
                break;
            case 'j':
                push(atof(j));
                break;
            case 'k':
                push(atof(k));
                break;
            case 'l':
                push(atof(l));
                break;
            case 'm':
                push(atof(m));
                break;
            case 'n':
                push(atof(n));
                break;
            case 'o':
                push(atof(o));
                break;
            case 'p':
                push(atof(p));
                break;
            case 'q':
                push(atof(q));
                break;
            case 'r':
                push(atof(r));
                break;
            case 's':
                push(atof(s));
                break;
            case 't':
                push(atof(t));
                break;
            case 'u':
                push(atof(u));
                break;
            case 'v':
                push(atof(v));
                break;
            case 'w':
                push(atof(w));
                break;
            case 'x':
                push(atof(x));
                break;
            case 'y':
                push(atof(y));
                break;
            case 'z':
                push(atof(z));
                break;
            case TOOBIG:
                printf("%.20s ... is too long\n", s);
                break;
            default:
                printf("Unknown command %c\n", type);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* stack pointer */
double val[MAXVAL];   /* value stack */

double push(f)      /* push f onto value stack */
        double f;
{
    if (sp < MAXVAL) {
        return (val[sp++]=f);
    }
    else{
        printf("error: stack full\n");
        clear();
    }
}

double pop()        /* pop top value from stack */
{
    if (sp > 0)
        return (val[--sp]);
    else{
        printf("error: stack empty\n");
        clear();
        return(0);
    }
}

void clear(){         /* clear stack */
    sp = 0;
}

int unary_minus = 0;        /* signal that the operator is unary minus and not substraction */
void unary_minus_check(){
    int c;
    if ((c = getch()) >= '0' && c <= '9')
        unary_minus = -1;
    ungetch(c);
}

int unary_plus = 0;        /* signal that the operator is unary minus and not substraction */
void unary_plus_check(){
    int c;
    if ((c = getch()) >= '0' && c <= '9')
        unary_plus = 1;
    ungetch(c);
}

void erase(){
    val[sp--] = '\0';
}

int getop(st,lim)
        char st[];
        int lim;
{
    int i, c;

    while ((c = getch()) == ' ' || c == '\t' || c == '\n')   /* skip white space */
        ;
    if (c != '.' && (c < '0' || c > '9'))                   /* return if it is an operator */
        return c;
    st[0] = c;                                               /* if not operator, add to array */
    for (i = 1; ((c = getchar()) >= '0' && c <= '9'); i++)                  /* find if number is more than one digit, keep adding till decimal*/
        if (i < lim)
            st[i] = c;
    if (c == '.') {                                         /* collect fraction*/
        if (i < lim)
            st[i] = c;                                 /* collect decimal */
        for (i++; (c = getchar()) >= '0' && c <= '9'; i++) {    /* add everything after decimal */
            if (i < lim)
                st[i] = c;
        }
    }
    if (i < lim) {                                          /* number is ok */
        ungetch(c);                                         /* unget the last character */
        st[i] = '\0';                                        /* end string at last character*/
        return(NUMBER);
    }
    else {                                                  /* it's too big; skip rest of line */
        while(c != '\n' && c != EOF)
            c = getchar();
        st[lim-1] = '\0';
        return(TOOBIG);
    }
}

#define BUFSIZE 1

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch()         /* get a (possibly pushed back) character */
{
    return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(c)    /* push character back on input */
        int c;
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

double atof(st)
        char st[];
{
    int i = 0, v = 0, power = 1;
    while(st[i] == ' ' || st[i] == '\t' || st[i] == '\n')
        i++;
    while(st[i] >= '0' && st[i] <= '9')
        v = v * 10 + st[i++] - '0';
    if(st[i] == '.') {
        st[i++];
    }
    while(st[i++] != '\0') {
        v = v * 10 + st[i] - '0';
        power = power * 10;
    }
    v /= power;
    return v;
}

void ungets(st)
        char st[];
{
    int i=0;
    bufp =0;
    if(bufp + (i = length(st)-1) < BUFSIZE) {
        while (i >= 0) {
            buf[bufp++] = st[i--];
        }
    }
    else
        printf("bufp + length > BUFSIZE");
}

int length(st)
        char st[];
{
    int i;
    for(i=0; st[i] != '\0'; i++)
        ;
    return i;
}