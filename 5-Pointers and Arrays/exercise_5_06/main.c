#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main() {                                    /* year and month, to day of year calculator, and vice versa */
    int year = 2021;
    int month = 2;
    int day = 21;
    int yearday = 122;

    day = day_of_year(year, month, day);
    printf("Day of year %d: %d\n", year, day);
    month_day(year, yearday, &month, &day);
    printf("Month:%d Day:%d", month, day);
    return 0;
}


int not_leap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int *day_tab[] = {
        not_leap,
        leap
};

int day_of_year(int year, int month, int day)
{
    int leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int *p = day_tab[leap];
    for(p++; p-day_tab[leap] < month; day += *p++)
        ;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int *q = day_tab[leap];
    for(q++; yearday > *q; yearday -=*q++)
        ;
    *pmonth = q - day_tab[leap] ;
    *pday = yearday;
}