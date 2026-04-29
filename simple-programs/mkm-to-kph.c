#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define min_args 2
#define period_length 60

bool ignore_errors = false;

void parse_values(int arg_offset, int number_of_values, char *arguments[]);

int main(int argc, char *argv[])
{
    if (argc > min_args)
    {
		int args_before_values = 1;
    	int num_values = argc - args_before_values;

		parse_values(args_before_values, num_values, argv);
    }

    return 0;
}

void parse_values(int arg_offset, int number_of_values, char *arguments[])
{
    long double all_values[number_of_values];
	/* convert string to long double with strlol */

	//int n_all_values_index = number_of_values - 1;
	for (int i = 0; i < number_of_values; i++)
	{
		long double u_value = strtold(arguments[arg_offset + i], NULL);
		/* write all values to the all_values array */
		all_values[i] = u_value;
	}
	
	/* calculate the results */
	long double valid_results[number_of_values];
	int num_valid_results = 0;
	
	for (int i = 0; i < number_of_values; i++)
	{
	    long double input = all_values[i];
	    if (!(input > 0 || input < 0))
	    {
	        printf("Invalid value detected at index %d: %Lf \n", i, input);
			if(!ignore_errors)
			{
				exit(-1);
			}
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
