#include <stdio.h>
int main() {  
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);  
  
  // %d will display the ascii value of the character
    printf("ASCII value of %c = %d", c, c);
    
    return 0;
}
