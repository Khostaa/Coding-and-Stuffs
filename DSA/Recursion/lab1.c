// factorial using tail Recursion
//if tailfact/function is called at last, it's tail recursion.
// gcc filename.c -S filename.c : to generate source code

#include <stdio.h>
long int tailfact(int n,long int a)
{
    if (n==0)
        return a;
    else 
        return tailfact(n-1,n*a);
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("\nThe factorial is %ld\n",tailfact(n,1));
    return 0;

}