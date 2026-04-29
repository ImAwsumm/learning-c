#include <stdio.h>
#include <stdlib.h>

#define min_args 2
#define period_length 60

int main(int argc, char *argv[])
{
    if (argc > min_args)
    {
		int args_before_values = 1;
    	int num_values = argc - args_before_values;
    	long double all_values[num_values];

		int index = 0;
		/* convert string to long double with strlol */
		for (int i = args_before_values; i < argc; i++)
		{
			long double u_value = strtold(argv[i], NULL);
			/* write all values to the all_values array */
			all_values[index] = u_value;
			index++;
		}

		/* calculate the results */
    	long double valid_results[num_values];
    	int num_valid_results = 0;

    	for (int i = 0; i < num_values; i++)
    	{
    	    long double input = all_values[i];
    	    if (!(input > 0 || input < 0))
    	    {
    	        printf("Invalid value %Lf\n", input);
    	        return -1;
    	    }

    	    long double result = period_length / input;
    	    valid_results[num_valid_results] = result;

    	    num_valid_results++;
    	}

    	/* print values from the array */
    	for (int i = 0; i < num_valid_results; i++)
    	{
    	    long double value = valid_results[i];
    	    printf("%.19Lf\n", value);
    	}
    }

    return 0;
}
