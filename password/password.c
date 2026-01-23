#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n [1] Algorithm using the rand(); function \n");
    printf("\n [2] Algorithm using the srand(); function\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1 )
    {
	int first = rand();
    	printf("\nNot very \"random\" value is %d\n", first );
    	return 0;
    }
    else
    {
	printf("\nYou're stupid\n");
	return 0;
    }
    return 0;
}
