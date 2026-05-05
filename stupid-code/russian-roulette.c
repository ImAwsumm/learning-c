#include <stdio.h>
#include <stdlib.h>

void kill_process(int input);

int main(void)
{
    printf("Press 1 to kill a process\n");

    int input;
    scanf("%d", &input);

    if (input == 1)
    {
		kill_process(input);
		printf("Do you want to kill another process ?\n");

		int p_kill_again;
		scanf("%d", &p_kill_again);
		if (p_kill_again > 0)
		{
			/* something */
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

void kill_process(int input)
{
	// allocate the exact amount of memory to the command
	int mem_needed = snprintf(NULL, 0, "sudo kill -9 $(ps -e -o pid= | shuf -n 1)") + 1;
	
	char *cmd = malloc((size_t)mem_needed);
	
	snprintf(cmd, (size_t)mem_needed,
			"sudo kill -9 $(ps -e -o pid= | shuf -n 1)");
	system(cmd);
	
	// free the memory previously allocated to the command
	free(cmd);
}
