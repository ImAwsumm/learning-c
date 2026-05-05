#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_word_size 32

void invalid_cmd_message(void);

int main(int argc, char *argv[])
{
	int base_args_n = 1;
	bool valid_args = false;

	long x,y;

	while (1)
	{
		if (argc > 1)
		{
			if (argc > 2)
			{
				if (argc == 3)
				{
					char *endptr;
					int index = base_args_n;
					x = strtol(argv[index], &endptr, 10);
					if (!(*endptr == '\0'))
					{
						invalid_cmd_message();
						break;
					}
					index++;
					y = strtol(argv[index], &endptr, 10);
					if (!(*endptr == '\0'))
					{
						invalid_cmd_message();
						break;
					}
					else
					{
						/* all variables taken from the user are valid */
						valid_args = true;
						break;
					}
				}
				else
				{
					invalid_cmd_message();
					break;
				}
			}
			else
			{
				/* continue despite the lack of arguments */
				invalid_cmd_message();
				break;
			}
		}
	}

	char *word_to_print = "Hi";

	int buf_size_word = 1 + snprintf(NULL, 0, "%s", word_to_print);

	if (buf_size_word >= max_word_size)
	{
		printf("Word is too long\n");
		exit(1);
	}

	/* initialize the word buffer
	 * then write the word to it while making sure we aren't overflowing the buffer */
    char word[max_word_size];

    snprintf(word, (size_t)buf_size_word, "%s", word_to_print);

	/* get the user input for the x and y axis
	 * we are doing "if (!valid_args)" because valid args is only true if the input is valid 
	 * the input could have already been taken with the command line arguments */
	if (!valid_args)
	{
		printf("Type the X axis: ");
    	scanf("%ld", &x);

    	while (getchar() != '\n'); /* clear the stdin input buffer */

    	printf("Type the y axis: ");
    	scanf("%ld", &y);
	}

	/* errors out if the user is trying to print nothing */
    if (!(x > 0) || !(y > 0))
    {
		printf("No characters to print out\n");
		exit(1);
    }

    printf("\n"); /* print newline for clarity */

    for (int i = 0; i < y; i++)
    {
		for (int j = 0; j < x; j++)
		{
		    printf("%s ", word);
		}
		printf("\n"); /* print newline because we did a full line */
    }
	return 0;
}

void invalid_cmd_message(void)
{
	printf("You did not type correct arguments.\n");
	printf("The command should be structured as follows:\n");
	printf("./[binary_name] [x axis] [y axis]\n\n");
}
