#include <stdio.h>
#include <stdlib.h>

#define max_array_size (20)

void get_input(int array_size);

long int values[max_array_size];

int main(int argc, char *argv[])
{
    long int u_input = 0;
    long int u_second_val = 0;

    int array_size;

    if (argc > 1)
    {
	array_size = argc - 1;
	char *endptr;
	char *str_1 = argv[1];
	u_input = strtol(str_1, &endptr, 10);

	if (argc > 2)
	{
	    char *endptr_t;
	    char *str_2 = argv[2];
	    u_second_val = strtol(str_2, &endptr_t, 10);
	}
    }
    else
    {
	printf("How many values are you inputting?\n");
    	scanf("%d", &array_size);
	get_input(array_size);
    }

    for (int i = 0; i < array_size; i++)
    {
	printf("%ld\n", values[i]);
    }

    int i;

    for (i = u_input / 2 + 1; i > 1; i--)
    {
	if (u_input % i == 0)
	{
	    break;
	}
    }

    printf("%d\n", i);
    
    printf("You entered %ld\n", u_input);

    printf("Divide by %ld\n", u_second_val);
    return 0;
}

void get_input(int array_size)
{
    int i;
    for (i = 1; i <= array_size; i++)
    {
	long int temp_input;
    	printf("Type value %d: \n", i);
    	scanf("%ld", &temp_input);
	int index = i - 1;
	values[index] = temp_input;
    }
}
