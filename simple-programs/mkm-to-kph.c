#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc >= 3)
    {
	/* convert string to long double with strlol */
	for (int i = 0; i < argc; i++)
	{
	    long double speed = strtold(argv[i], NULL);
	    printf("%.19Lf\n", speed);
	}
    }
    return 0;
}
