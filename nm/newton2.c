#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x)
{
    float fx = 4*x*x - 5*x + 6;
    return fx;
}
float fd(float x)
{
    float fx=8*x - 5;
}
int main()
{
  float x0,x1;
  int i,step=0;
  printf("\nEnter intial guess: ");
  scanf("%f",&x0);
  printf("\nEnter maximum number of iteration: ");
  scanf("%d",i);
  do
  {
    if(fd(x0)==0)
    {
        printf("Mathematical Error");
        break;
    }
    else
    {
        x1 = x0 - (function(x0)/fd(x0));
        printf("Step=%d\tx0=%f\tx1=%f\n",step,x0,x1);
        x0 = x1;
    }
  } while (abs(function(x1))>pow(10,-5));
  
  return 0;
}