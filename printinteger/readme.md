# Simple C Program

This is a simple C program that takes an integer input from the user and displays it back.
This is not getting any further modifications.
## Code

```c
#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("You entered: %d", number);
    return 0;
} 