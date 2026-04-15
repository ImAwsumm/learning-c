#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>

int main(void)
{
    float u_input;
    float u_input_tax_rate;

    printf("Type your expense: ");
    scanf("%f", &u_input);

    while(getchar() != '\n');

    printf("Type your tax rate in %%: ");
    scanf("%f", &u_input_tax_rate);

    if (!(u_input >= 0))
    {
	printf("Invalid input\n");
	return 1;
    }

    float tax_rate = u_input_tax_rate / 100 + 1;
    float total = tax_rate * (float)u_input;

    printf("%f\n", u_input);

    printf("%f\n", total);

    // logic goes here
    return 0;
}
