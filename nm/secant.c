#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) x*x - 4*x - 10

void main()
{
    float x1,x2,x3,f1,f2,f3,e;
    int step = 1,n;

    printf("Enter two initial guesses: \n");
    scanf("%f%f",&x1,&x2);
    printf("Enter Tolerable error: \n");
    scanf("%f",&e);
    printf("Enter maximum iteration: ");
    scanf("%d",&n);

    printf("Step\t\tx1\t\tx2\t\tx3\t\tf(x2)\n");
    do
    {
         f1 = f(x1);
         f2 = f(x2);
        if(f1 == f2)
        {
            printf("mathematical error.\n");
            exit(0);
        }
        x3 = x2 - (x2 - x1)*f2/(f2-f1);
        f3 = f(x3);
        printf("%d\t%f\t%f\t%f\t%f\n",step,x1,x2,x3,f2);
        x1 = x2;
        f1 = f2;
        x2 = x3;
        f2 = f3;
        step = step + 1; 
        if(step > n)
        {
            printf("Not convergent.");
            exit(0);
        }
    } while (fabs(f2)>e);
    printf("Root is %f.",x3);
    getch();

}