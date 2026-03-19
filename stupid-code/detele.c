#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *src = fopen("text.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!src || !temp) 
    {
        perror("File error");
        return 1;
    }

    char buffer[1024];
    int line = 1;

    while (fgets(buffer, sizeof(buffer), src)) 
    {
        if (line > 20)	// delete the first 20 lines
	{
            fputs(buffer, temp);
        }
        line++;
    }

    fclose(src);
    fclose(temp);

    remove("text.txt");
    rename("temp.txt", "text.txt");
    return 0;
}
