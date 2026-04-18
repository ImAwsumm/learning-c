#include <stdio.h>

int main(int argc, char *argv[])
{
    int u_input;
    int u_divider;

    if (argc < 3)
    {
	printf("Type value\n");
    	scanf("%d", &u_input);

	printf("Type divider\n");
    	scanf("%d", &u_divider);
    }

    printf("You entered %d\n", u_input);

    printf("Divide by %d\n", u_divider);
    return 0;
}
