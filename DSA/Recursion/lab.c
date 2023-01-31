// Factorial using recursion
#include <stdio.h>
long int fact(int n)
{
    if (n==0)
        return 1;
    else 
        return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("\nThe factorial is %ld\n",fact(n));
    return 0;

}