#include <stdio.h>
int main()
{
    int n, count, sum = 0;

    printf("Enter the value of n(positive integer): ");
    scanf("%d",&n);
    
    count=1;
    while(count <= n){
    	sum = sum + count;
    	count++;
    }

    printf("Sum of first %d natural numbers is: %d",n, sum);

    return 0;
}
