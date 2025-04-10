#include <stdio.h>
int main() {  
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);  
  
  // %d will display the ascii value of the character
    printf("The ASCII value of %c is %d", c, c);
    
    return 0;
}
