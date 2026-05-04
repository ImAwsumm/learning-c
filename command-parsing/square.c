#include <stdio.h>
#include <stdlib.h>

//int main(int argc, char *argv[])
int main(void)
{
    char word[32];
    snprintf(word, sizeof(word),
			"Hi");

    printf("Type the X axis: ");

    int x;
    scanf("%d", &x);
    printf("Type the y axis: ");

    while (getchar() != '\n'); /* clear the stdin input buffer */
    int y;
    scanf("%d", &y);
    printf("\n");

    if (!(x > 0 || y > 0))
    {
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
