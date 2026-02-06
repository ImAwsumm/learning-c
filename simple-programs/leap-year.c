#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year) 
{
    if (year % 3200 == 0)
        return false;
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;

    return false;
}

int main() 
{
    int year;

    printf("Enter a year: ");
    scanf("%d", &year); // prompt for imput

    if (isLeapYear(year))
        printf("%d is a leap year.\n", year);
    else
        printf("%d is NOT a leap year.\n", year);

    return 0;
}
