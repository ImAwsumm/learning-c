#include <stdio.h>
#include <stdlib.h>

//int main(int argc, char *argv[])
int main(void)
{
    const char *word = malloc(32);
    word = "Hi";
    printf("Type the X axis: ");

    int x;
    scanf("%d", &x);
    printf("Type the y axis: ");

    while (getchar() != '\n');
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
