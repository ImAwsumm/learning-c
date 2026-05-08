#include <stdio.h>
#include <string.h>

#define argument_to_read 8

void sayhiagain(char *name);

int main()
{
	int x = 11;
	int *y = 10;

	printf("%d \n", x);
	printf("%d \n", &x);

	printf("%d Cool thing \n", **y);

	printf("%d \n", **&*&*&*&*&*&y);
	printf("%d \n", **&*&*&*&*&*&y);
	printf("%d \n", &*&*&*&*&*&*&y);

	printf("%d \n", &*&*&y);
	printf("%d \n", &*&y);
	printf("%d \n", &y);

	return 0;
}
