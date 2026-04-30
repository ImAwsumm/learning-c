#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int y;
	int *x = malloc(4);
	x = &y;
	y = 123;
    return 0;
}
