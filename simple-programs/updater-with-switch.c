#include <stdio.h>


float pver;


int main()
{
    printf("\n Type the current version:");
    scanf(" %f", &pver);

    int y = (int)(pver * 100);
    switch (y) 
    {
    case 141:
        printf("Case 1 is Matched.\n");

    case 200:
        printf("Case 2 is Matched.\n");

    case 300:
        printf("Case 3 is Matched.\n");

	goto end;
    default:
        printf("Default case is Matched.\n");

    end:
	printf("Update completed!\n");

    }
    return 0;
}
