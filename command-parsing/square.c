#include <stdio.h>
#include <stdlib.h>

//int main(int argc, char *argv[])
int main(void)
{
    printf("Type the X axis: ");

    int x;
    scanf("%d", x);
    printf("\nType the y axis: ");

    int y;
    scanf("%d", y);

    if (!(x > 0 || y > 0))
    {
	exit(1);
    }

    for (int i = 0; i < y; i++)
    {
	for (int j = 0; j < x; j++)
	{
	}
    }
    return 0;
}
