#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int y;
	int *x = malloc(4);
	x = &y;
	y = 123;

	printf("%d\n", *x); /* dereference the x pointer to y */

    return 0;
}
