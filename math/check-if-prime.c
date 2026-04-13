#include <stdio.h>
#include <stdbool.h>

bool check_if_prime(int value);

int main(void)
{
    printf("Type a number\n");

    int u_input;
    scanf("%d", &u_input);

    bool is_prime = check_if_prime(u_input);

    if (is_prime)
    {
	printf("Number is prime\n");
    }
    else
    {
	printf("Number is a composite\n");
    }

    return 0;
}

bool check_if_prime(int value)
{
    int max_divider = value / 2;

    printf("max_divider is: %d \n", max_divider);

    for (int i = 2; i <= max_divider; i++)
    {
	printf("Mod %d \n", i);

	if (value % i == 0)
	{
	    return false;
	}
    }
    return true;
}
