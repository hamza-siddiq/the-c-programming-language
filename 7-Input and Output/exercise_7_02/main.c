#include "include.h"

int main() {

    int scanval;
    char s[MAXVAL];
    int type;
    double op, digval;

    while((scanval = scanf("%s", &s))!= EOF){
        type = *s >= '0' && *s <= '9' || *s == '.'? NUMBER: *s;
        if (type == NUMBER) {
            digval = atof(s);
            type = digval > MAXDIG ? TOOBIG : type;
        }
        switch (type) {
            case NUMBER :
                push(digval);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case '/':
                op = pop();
                if (op!= 0)
                    push(pop()/op);
                else
                    printf("Divisor is 0");
                break;
            case '=':
                printf("\t%.2f\n", push(pop()));
                break;
            case 'c':
                clear();
                break;
            case TOOBIG:
                printf("Number %s too big\n", s);
                break;
            default:
                printf("Unknown command %c entered", type);
                break;
        }
    }
    return 0;
}

double val[MAXVAL];
double *vp = val;
double push(double f){
    return (vp-val < MAXVAL ?  *vp++ = f: printf("Unable to enter %f , stack is full", f));
}

double pop(){
    vp == val ? printf("Empty stack"): 0;
    return(vp > val? *--vp: 0);
}

void clear() {
    vp = val;
}