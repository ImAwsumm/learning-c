#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_word_size 32

int main(int argc, char *argv[])
{
	int base_args_n = 1;
	bool valid_args = false;

	long x,y;
	if (argc > 1)
	{
		if (argc > 2)
		{
			if (argc == 3)
			{
				char *endptr;
				int index = base_args_n;
				x = strtol(argv[index], &endptr, 10);
				index++;
				y = strtol(argv[index], &endptr, 10);
				valid_args = true;
			}
			else
			{
				printf("You did not type the correct amount of arguments\n");
				printf("The command should be structured as follows:\n");
				printf("./[binary_name] [x axis] [y axis]\n\n");
			}
		}
		else
		{
			/* continue despite the lack of arguments */
			printf("Missing arguments for the full command\n");

		}
	}

	char *word_to_print = "Hi";

	int buf_size_word = 1 + snprintf(NULL, 0, word_to_print);

	if (buf_size_word >= max_word_size)
	{
		printf("Word is too long\n");
		exit(1);
	}

    char word[max_word_size];

    snprintf(word, (size_t)buf_size_word, word_to_print);

	if (!valid_args)
	{
		printf("Type the X axis: ");
    	scanf("%ld", &x);

    	while (getchar() != '\n'); /* clear the stdin input buffer */

    	printf("Type the y axis: ");
    	scanf("%ld", &y);
	}

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
