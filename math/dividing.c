#include <stdio.h>
#include <stdlib.h>

#define EXP_ARGS 3

void get_input(int array_size);


int main(int argc, char *argv[])
{
    long int u_input;
    long int u_second_val;

    int array_size;

    if (argc == EXP_ARGS)
    {
	array_size = 3; /* hard coded (it shouldn't be for a long time) */
	char *endptr;
	char *str_1 = argv[1];
	u_input = strtol(str_1, &endptr, 10);

	char *endptr_t;
	char *str_2 = argv[2];
	u_second_val = strtol(str_2, &endptr_t, 10);
    }
    else
    {
	printf("How many values are you inputting?\n");
    	scanf("%d", &array_size);
    }

    double int values[array_size];

    int i;
    //long int arr[PRECISION];
    for (i = u_input / 2 + 1; i > 1; i--)
    {
	if (u_input % i == 0)
	{
	    break;
	}
    }

    printf("%d", i);
    
    printf("You entered %ld\n", u_input);

    printf("Divide by %ld\n", u_second_val);
    return 0;
}

void get_input(int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
	long int value;
    	printf("Type value 1\n");
    	scanf("%ld", &value);

    }
}
