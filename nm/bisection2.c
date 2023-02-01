#include<stdio.h>
#include<math.h>
float function(float x)
{
    float fx;
    fx= sin(x)-1/x;
    return fx;
}
int main()
{
    int iteration=0;
    float x1,x2,xm,f1,f2,fm,e;
    Up:
      printf("\nEnter two intial guesses: "); //input intial guesses
      scanf("%f %f",&x1,&x2);

      printf("\nEnter error: ");//input tolerable error
      scanf("%f",&e);
      //assinging values of x1 and x2 into function
      f1 = function(x1);
      f2 = function(x2);
      //check if guesses are correct
      if (f1 *f2>0)
          { 
            printf("Incorrect Initial Guesses! Please try again!\n");
            goto Up;
          }
    printf("Iteration\tx1\t\tx2\t\txm\tf1\t\tf2\t\tfm\n");
    do{
        xm = (x1 + x2)/2;
        fm = function(xm); //assign xm into function
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n",iteration,x1,x2,xm,f1,f2,fm);
        
         if (f1*fm<0)
        {
            x2 = xm;
            f2 = fm;
        }
        else
        {
              x1 = xm;
              f1 = fm;
        }  
        ++iteration;
      }while(fabs(fm)>=e);  
      printf("Root is %f\n",xm);

 return 0;
}