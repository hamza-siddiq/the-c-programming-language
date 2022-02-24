#include <stdio.h>

int main() {
    /* print Fahrenheit-Celcius table for f = 0, 20, ..., 300 */
    int lower, upper, step;
    float fahr, celcius;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit-Celcius table\n");
    while(fahr <= upper){
        celcius = (5.0 / 9.0) * (fahr-32.0);
        printf("%4.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}
