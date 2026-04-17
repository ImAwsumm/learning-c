#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Lower bound
unsigned int lb = 10; 
// Upper bound
unsigned int ub = 99;

struct timespec install_timer;

int entropy(void)
{
    unsigned int random_buffer[32];
    if (getentropy(random_buffer, sizeof(random_buffer)) != 0) 
    {
	perror("getentropy failed");
    	exit(EXIT_FAILURE);
    }
    return *random_buffer;
}

int srandtwo(void)
{
    srand(time(NULL));
    int sec = (rand() % (ub - lb + 1)) + lb;
    return sec;
}

int main(void)
{

    printf("\n[1] Algorithm using the rand(); function \n");
    printf("[2] Algorithm using the srand(); function\n");
    printf("[3] Algorithm using system entropy as a seed for the srand(); function\n");

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
	for (int i = 1; i <= 5; i++)
	{
	    srand(time(NULL)); 
	    int second = (srandtwo() % (ub - lb +1)) + lb;
    	    printf("\nA \"more\" random value: %d\n", second );

	        install_timer.tv_sec = 0;
	        install_timer.tv_nsec = 500000000L;
	        nanosleep(&install_timer, NULL);
	}
	return 0;
    }
    else if (choice == 3 )
    {
	// use system entropy in order to generate a random number
	unsigned int third = (entropy() % (ub - lb + 1)) + lb;
	printf("\nA pretty random number: %u\n", third);
    }
    else if (choice == 0 )
    {
	return 0;
    }
    else
    {
	printf("\nYou're stupid\n");
	return 0;
    }

    return 0;
}
