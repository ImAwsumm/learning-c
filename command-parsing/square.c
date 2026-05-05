#include <stdio.h>
#include <stdlib.h>

#define max_word_size 32

/*
int main(int argc, char *argv[])
*/
int main(void)
{
	char *word_to_print = "Hi";

	int buf_size_word = 1 + snprintf(NULL, 0, word_to_print);

	if (buf_size_word >= max_word_size)
	{
		printf("Word is too long\n");
		exit(1);
	}

    char word[max_word_size];

    snprintf(word, (size_t)buf_size_word, word_to_print);
    printf("Type the X axis: ");

    int x;
    scanf("%d", &x);
    printf("Type the y axis: ");

    while (getchar() != '\n'); /* clear the stdin input buffer */
    int y;
    scanf("%d", &y);
    printf("\n");

    if (!(x > 0) || !(y > 0))
    {
		printf("No characters to print out\n");
		exit(1);
    }

    for (int i = 0; i < y; i++)
    {
		for (int j = 0; j < x; j++)
		{
		    printf("%s ", word);
		}
		printf("\n");
    }
    return 0;
}
