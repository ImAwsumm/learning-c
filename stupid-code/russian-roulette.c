#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Press 1 to kill a process\n");

    int input;
    scanf("%d", &input);

    if (input == 1)
    {
	// allocate the exact amount of memory to the command
	int mem_needed = snprintf(NULL, 0, "sudo kill -9 $(ps -e -o pid= | shuf -n 1)") + 1;

	char *cmd = malloc(mem_needed);

	snprintf(cmd, mem_needed,
		"sudo kill -9 $(ps -e -o pid= | shuf -n 1)");
	system(cmd);

	// free the memory previously allocated to the command
	free(cmd);
    }
    else
    {
	printf("Exiting..\n");
    }

    return 0;
}
