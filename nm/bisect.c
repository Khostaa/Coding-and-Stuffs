#include <stdio.h>
#include <math.h>

#define fn(x) sin(x) -1/x
// float fn(float x)
// {
//     float fx = x*x*x - 6*x*x +11*x-6;
//     return fx;
// }
int main()
{
    int step=0;
    float x1,x2,m,f1,f2,fm,e;
    up: 
      printf("\nEnter two intial guesses: ");
      scanf("%f%f",&x1,&x2);
      printf("\nEnter tolerable error: ");
      scanf("%f",&e);
      f1 = fn(x1);
      f2 = fn(x2);
      if (f1*f2 > 0)
      {
        printf("Incorrect guesses. Please try again!\n");
        goto up;
      }
    printf("Step\t\tx1\t\tx2\t\tm\t\tfm\n");
    do
    {
        m = (x1+x2)/2;
        fm = fn(m);
        printf("%d\t%f\t%f\t%f\t%f\n",step,x1,x2,m,fm);
        if(f1*fm < 0)
        {
            x2 = m;
        }
        else{
            x1 = m;
        }
        step = step + 1;

    } while (fabs(fm) > e);
    printf("Root is %f\n",m);
    return 0;
}