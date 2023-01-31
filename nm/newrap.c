#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x)
{
    float fx= x*x - 3*x + 2;
    return fx;
}
float functionDerivative(float x)
{
    float fx = 2*x - 3;
    return fx;

}

int main()
{
    float x0,x1;
    int iteration,step=0;
    printf("\nEnter initial guess: ");
    scanf("%f",&x0);
    printf("\nEnter maximum number of iteration: \n");
    scanf("%d",&iteration);

    printf("Step\t  x0  \tx1\n");
    do
    {
        if(functionDerivative(x0)==0)
        {
            printf("Mathematical Error.\n");
            break;

        }
        else
        {
            x1 = x0 - (function(x0)/functionDerivative(x0));
            printf("%d\t%f\t%f\n",step,x0,x1);
            x0 = x1;
        }
        step = step + 1;
        if(step >= iteration)
              break;
    } while (abs(function(x1))==0);
    


    return 0;
}