#include <stdio.h>
#include <stdlib.h>

#define EXP_ARGS 3
#define PRECISION 5

int main(int argc, char *argv[])
{
    long int u_input;
    long int u_second_val;

    if (argc == EXP_ARGS)
    {
	char *endptr;
	char *str_1 = argv[1];
	u_input = strtol(str_1, &endptr, 10);

	char *endptr_t;
	char *str_2 = argv[2];
	u_second_val = strtol(str_2, &endptr_t, 10);
    }
    else
    {
	printf("Type value 1\n");
    	scanf("%ld", &u_input);

	printf("Type value 2\n");
    	scanf("%ld", &u_second_val);
    }
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

