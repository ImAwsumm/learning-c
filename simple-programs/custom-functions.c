#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct timespec install_timer;

void clear()
{
    printf("\033[2J\033[H");
}

void delay()
{
    install_timer.tv_nsec = 250000000L;
    install_timer.tv_sec = 0;
    nanosleep(&install_timer, NULL);
}
void cool_countdown()
{
    int timer = 3;
    int d = timer; 
    printf("\nWait %d seconds!\n", timer);
    printf("\nDone in:\n");
    
    for (int i = 0; i < d; i++)
    {
        printf("%d ", timer);
    
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            fflush(stdout);
    	install_timer.tv_nsec = 250000000L;
    	install_timer.tv_sec = 0;
    	nanosleep(&install_timer, NULL);
        }
        for (int k = 0; k < 1; k++)
        {
    	printf("\n");
    	install_timer.tv_nsec = 250000000L;
    	install_timer.tv_sec = 0;
    	nanosleep(&install_timer, NULL);
        }
        timer--;
    }
}
