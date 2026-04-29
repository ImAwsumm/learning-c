#include <stdio.h>

float pver;

void func_one(void);
void func_two(void);
void func_the(void);

int main(void)
{
    printf("\n Type the current version:");
    scanf(" %f", &pver);

    int y = (int)(pver * 100);
    switch (y) 
    {
	case 141:
    	    printf("Case 1 is Matched.\n");
    	    func_one();
    	    __attribute__ ((fallthrough));

    	case 200:
    	    printf("Case 2 is Matched.\n");
    	    func_two();
    	    __attribute__ ((fallthrough));

    	case 300:
    	    printf("Case 3 is Matched.\n");
    	    func_the();

    	    goto end;
    	default:
    	    printf("Default case is Matched.\n");

    	end:
	    printf("Update completed!\n");

    }
    return 0;
}

void func_one(void)
{
    printf("Hey\n");
}
void func_two(void)
{
    printf("How\n");
}
void func_the(void)
{
    printf("Are you?\n");
}
