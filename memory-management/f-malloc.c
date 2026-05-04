#include <stdio.h>
#include <stdlib.h>

#define test_number 123

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		auto char *str = argv[1];
		auto char *endptr;
		auto long int number;

		number = strtol(str, &endptr, 10);
		if (!(*endptr != '\0'))
		{
			printf("number is: %ld\n", number);
		}
		auto int array_elements = argc - 1;
		auto int numbers[array_elements];
	}

	auto int y;
	auto int *x = malloc(4);

	x = &y;
	y = test_number;

	printf("%d\n", *x); /* dereference the x pointer to y */

    return 0;
}
