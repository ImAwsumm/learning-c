#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define min_args 1
#define period_length 60
#define miles_to_km 1.609344
#define km_to_miles 0.621371192

bool ignore_errors = false; /* globals */

void parse_values(bool no_convert, bool source_miles, int arg_offset, int number_of_values, char *arguments[]);

int main(int argc, char *argv[])
{
	bool in_miles = false;
	bool out_miles = false;
	bool same_out_unit = true;

	bool i_flag = false;
	bool o_flag = false;

	int args_before_values = 1;
    if (argc > min_args)
    {
		if (argc > min_args + 2)
		{
			int arg_read = 0;

			while (argc > arg_read)
			{
				if (strcmp(argv[arg_read], "-i") == 0)
				{
					i_flag = true;

					arg_read++;
					printf("-i flag found\n");
					if (strcmp(argv[arg_read], "miles") == 0 || strcmp(argv[arg_read], "mile") == 0)
					{
						printf("Miles\n");
						out_miles = true;
						arg_read++;
						args_before_values++;
					}
					else if (strcmp(argv[arg_read], "km") == 0 || strcmp(argv[arg_read], "kilometer") == 0)
					{
						printf("km\n");
						out_miles = false;
						arg_read++;
						args_before_values++;
					}
					else
					{
						printf("Unspecified or unknwon unit\n");
						if (!ignore_errors)
						{
							arg_read++;
							args_before_values++;
						}
						else
						{
							printf("Invalid use of %s was ignored\n", argv[arg_read]);
						}
					}
					args_before_values++;
				}
				else if (strcmp(argv[arg_read], "-o") == 0)
				{
					o_flag = true;

					arg_read++;
					printf("-o flag found\n");
					if (strcmp(argv[arg_read], "miles") == 0 || strcmp(argv[arg_read], "mile") == 0)
					{
						printf("Miles\n");
						in_miles = true;
						arg_read++;
						args_before_values++;
					}
					else if (strcmp(argv[arg_read], "km") == 0 || strcmp(argv[arg_read], "kilometer") == 0)
					{
						printf("km\n");
						in_miles = false;
						arg_read++;
						args_before_values++;
					}
					else
					{
						printf("Unspecified or unknwon unit\n");
						if (!ignore_errors)
						{
							arg_read++;
							args_before_values++;
						}
						else
						{
							printf("Invalid use of %s was ignored\n", argv[arg_read]);
						}
					}
					args_before_values++;
				}
				else
				{
					arg_read++;
				}
			}
		}
    	int num_values = argc - args_before_values;

		if (in_miles == out_miles)
		{
			same_out_unit = true;
		}
		else
		{
			same_out_unit = false;
		}

		if (!(i_flag || o_flag))
		{
			printf("No flags used\n");
		}

		parse_values(same_out_unit, out_miles, args_before_values, num_values, argv);
    }

    return 0;
}

void parse_values(bool no_convert, bool source_miles, int arg_offset, int number_of_values, char *arguments[])
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

	if (!no_convert)
	{
		if (source_miles)
		{
			for (int i = 0; i < number_of_values; i++)
			{
				long double temp_value = all_values[i] * km_to_miles;
				all_values[i] = temp_value;
			}
		}
		else
		{
			for (int i = 0; i < number_of_values; i++)
			{
				long double temp_value = all_values[i] * miles_to_km;
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
