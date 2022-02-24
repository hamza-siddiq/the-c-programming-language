#include <stdio.h>

int main() {
    /* celcius to fahrenheit converter */
    double celsius;
    double fahrenheit;

    printf("Celsius to Fahrenheit:\n");
    for(celsius = 0;celsius!= 320; celsius+=20) {
       fahrenheit = 32 + (celsius * 9 / 5);
        printf("%4.0f %4.0f\n",celsius,fahrenheit);
    }
}
