#include <stdio.h>
#include <stdlib.h>

void print_directory(char current_working_dir[256]);

int main(void)
{
    FILE *fp;
    char output[256];

    /* execute pwd and store the output in fp file */
    fp = popen("pwd", "r");
    
    if (fp == NULL) 
    {
        perror("popen failed");
        return 1;
    }
    /* read file fp using fgets and store all data in the output string */
    if (fgets(output, sizeof(output), fp) != NULL) 
    {
        print_directory(output);
    }
    pclose(fp); /* close unused file */

    print_directory(output);
    
    return 0;
}

void print_directory(char current_working_dir[256])
{
    printf("Current directory: %s\n", current_working_dir);
}
