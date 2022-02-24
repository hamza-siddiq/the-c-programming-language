#include <stdio.h>

int main(argc, argv)    /* reverse Polish Calculator */
int argc;
char *argv[];
{
    char **argp;
    char **command_address;       /* The first address e.g if the first argument is add, the address of add */
    int v;                      /* Total value calculated*/
    int toomany;                /* Too many arguments */

    ++argv;                     /* increase argv to ignore file place argument */
    --argc;                     /* decrease argc to ignore file place argument */
    command_address = argv;
    while(--argc > 0 && **++argv >='0' && **argv <= '9')    /* increase argv till an operator is reached */
        ;
    if (argc == 0) {                                        /* argc reached zero, so operators were not found*/
        printf("Missing operators");
        return 0;
    }
    else{
        argp = argv -1;                         /* Make argp one less than the operator, i.e the number before the operator*/
        v = **argp - '0';                                  /* Make total value equal to this number */

        while(argc-- > 0) {                                             /* decrease argc till it reaches 0 */
            toomany = (**--argp >= '0' && **argp <= '9')? 0: 1;         /* if argp is not a number */
            if (toomany) {                                              /* there were too many operators */
                printf("Too many operators\n");
                return 0;
            }
            int p = **argp - '0';                                       /* make p equal to argument p's value */
            switch(**argv++){
                case'+':
                    v += p;
                    break;
                case'-':
                    v -=p;
                    break;
                case'/':
                    v = p == 0 ? printf("Error: divisor equal to zero at character %d\n", (argp-command_address)) : v / p;
                    argc = p == 0 ? -1 : argc;      /* divisor is zero get out of loop */
                    break;
                case'*':
                    v *= p;
                    break;
                default:
                    printf("Invalid operator at character");
                    return 0;
            }
        }
    }
    if (argp-command_address != 1){
        printf("Too many numbers");
    }
    else if(argc == -1) {
        printf("v = %d", v);
    }
    return 0;
}