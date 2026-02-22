#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char output[256];
    
    fp = popen("pwd", "r");
    if (fgets(output, sizeof(output), fp) != NULL) 
    {
        printf("Current directory: %s", output);
    }
    pclose(fp);
    
    printf("Current directory: %s", output);
    return 0;
}
