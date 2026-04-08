#include <stdio.h>

int main(void)
{
    printf("Press 1 to kill a process\n");

    int input;
    scanf("%d", input);

    if (input == 1)
    {
	//snprintf(cmd, sizeof(cmd),
	//	"sudo kill -9 $(ps -e -o pid= | shuf -n 1)"
    }

    return 0;
}
