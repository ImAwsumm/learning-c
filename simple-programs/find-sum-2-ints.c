#include <stdio.h>
int main()
{
    int n, count, sum = 0;

    printf("Enter the value of n(positive integer): ");
    scanf("%d",&n);

    // When you use while loop, you have to initialize the
    // loop counter variable before the loop and increment
    // or decrement it inside the loop
    count=1;
    while(count <= n){
    	sum = sum + count;
    	count++;
    }

    printf("Sum of first %d natural numbers is: %d",n, sum);

    return 0;
}
