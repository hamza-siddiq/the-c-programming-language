#include <stdio.h>
#define swap(x,y) z=x; x=y; y=z
int main() {    /* swap any two int arguments */
    int x = 5;
    int y = 3;
    int z;
    swap(x,y);
    printf("y = %d\nx = %d\n", y, x);
    return 0;
}
