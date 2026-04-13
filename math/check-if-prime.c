#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_if_prime(long long value);

int main(int argc, char *argv[])
{
    long long u_input;	// initialize 64 bit integer

    if (argc == 2)
    {
	char *temp_u_input = argv[1];	// convert the string at index 1 of argv to a string
	char *endptr;
	u_input = strtoll(temp_u_input, &endptr, 10);	// st

	if (*endptr != '\0')
	{
	    printf("%s is not a valid integer.\n", temp_u_input);
	    return 2;
	}

    }
    else if (argc > 2)
    {
	printf("Too many arguments\n");
	return 1;
    }
    else
    {
	printf("Type a number\n");
    	scanf("%lld", &u_input);
    }

    // check if number is prime
    // store the output of the check_if_prime function in the is_prime boolean
    bool is_prime = check_if_prime(u_input);

    if (is_prime)
    {
	printf("Number is prime\n");
    }
    else
    {
	printf("Number is composite\n");
    }

    return 0;
}

bool check_if_prime(long long value)
{
    for (long long i = 2; i * i <= value; i++)
    {
	if (value % i == 0)
	{
	    // print the equation that proved this numeber was composite
	    printf("%lld %% %lld == 0 \n", value, i);
	    return false;
	}
    }
    return true;
}
