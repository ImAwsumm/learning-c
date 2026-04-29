#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define min_args 1
#define period_length 60
#define miles_to_km 0.6213712
#define km_to_miles 1.609344

bool ignore_errors = false;
bool source_miles = true;
bool same_out_unit = false;

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

	for (int i = 0; i < number_of_values; i++)
	{
		long double u_value = strtold(arguments[arg_offset + i], NULL);
		/* write all values to the all_values array */
		all_values[i] = u_value;
	}
	
	/* calculate the results */
	long double valid_results[number_of_values];
	int num_valid_results = 0;

	if (!same_out_unit)
	{
		if (source_miles)
		{
			for (int i = 0; i < number_of_values; i++)
			{
				long double temp_value = all_values[i] * miles_to_km;
				all_values[i] = temp_value;
			}
		}
		else
		{
			for (int i = 0; i < number_of_values; i++)
			{
				long double temp_value = all_values[i] * km_to_miles;
				all_values[i] = temp_value;
			}
		}
	}
	
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
