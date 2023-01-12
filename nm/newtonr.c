#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x)
{
    float fx= 2*x*x + 4*x - 5;
    return fx;
}
float functionDerivative(float x)
{
    float fx = 4*x + 4;
    return fx;

}

int main()
{
    float x0,x1;
    int iteration,step=0;
    printf("\nEnter initial guess: ");
    scanf("%f",&x0);
    printf("\nEnter maximum number of iteration: ");
    scanf("%d",&iteration);
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
            printf("Step=%d\tx0=%f\tx1=%f\n",step,x0,x1);
            x0 = x1;
        }
        step = step + 1;
        if(step >= iteration)
           break;
    } while (abs(function(x1))>pow(10,-5));
    


    return 0;
}