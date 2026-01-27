#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int entropy()
{
    unsigned int random_buffer[32];
    getentropy(random_buffer, sizeof(random_buffer)) == 0;
    return *random_buffer;
}

int main()
{
    // Lower bound
    int lb = 10; 
    // Upper bound
    int ub = 99;

    printf("\n[1] Algorithm using the rand(); function \n");
    printf("[2] Algorithm using the srand(); function\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1 )
    {
	int first = (rand() % (ub - lb + 1)) + lb;
    	printf("\nNot very \"random\" value is %d\n", first );
    	return 0;
    }
    else if (choice == 2 )
    {
        srand(time(NULL)); 
	int second = (rand() % (ub - lb + 1)) + lb;
	//int second = srand(rand(NULL));
    	printf("\nA \"more\" random value: %d\n", second );
    	return 0;
    }
    else if (choice == 3 )
    {
	// use system entropy in order to generate a random number
	int third = (entropy() % (ub - lb + 1)) + lb;
	printf("\nA pretty random number: %d\n", third);
    }
    else
    {
	printf("\nYou're stupid\n");
	return 0;
    }
    return 0;
}
