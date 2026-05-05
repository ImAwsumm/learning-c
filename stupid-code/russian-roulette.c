#include <stdio.h>
#include <stdlib.h>

void kill_process(void);

int main(void)
{
    printf("Press 1 to kill a process\n");

    int input;
    scanf("%d", &input);

    if (input == 1)
    {
		//kill_process();
		printf("Now that you've kille a process, how many other processes do you want to kill?\n");

		int p_kill_again;
		printf("Number of processes:");
		scanf("%d", &p_kill_again);

		if (p_kill_again > 0)
		{
			for (int i = 0; i < p_kill_again; i++)
			{
				kill_process();
			}
		}
		else
		{
			exit(0);
		}
    }
    else
    {
		printf("Exiting..\n");
    }
	

    return 0;
}

void kill_process(void)
{
	/* allocate the exact amount of memory to the command 
	 * so that we can safely execute a dangerous command */
	int mem_needed = 1 + snprintf(NULL, 0, "sudo kill -9 $(ps -e -o pid= | shuf -n 1)");
	
	char *cmd = malloc((size_t)mem_needed);

	snprintf(cmd, (size_t)mem_needed,
			"sudo kill -9 $(ps -e -o pid= | shuf -n 1)");
	system(cmd);
	
	/* free the memory previously allocated to the command */
	free(cmd);
}
