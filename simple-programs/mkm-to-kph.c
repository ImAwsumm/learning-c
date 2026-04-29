#include <stdio.h>
#include <stdlib.h>

#define min_args 2

int main(int argc, char *argv[])
{
    int args_before_values = 1;
    int num_values = argc - args_before_values;
    long double all_values[num_values];

    if (argc >= min_args)
    {
	int index = 0;
	/* convert string to long double with strlol */
	for (int i = args_before_values; i < argc; i++)
	{
	    long double u_value = strtold(argv[i], NULL);

	    /* write all values to the all_values array */
	    all_values[index] = u_value;

	    printf("%.19Lf\n", u_value);
	    index++;
	}
    }

    /* print values from the array */
    for (int i = 0; i < num_values; i++)
    {
	long double value = all_values[i];
	printf("%.19Lf\n", value);
    }
    return 0;
}
