#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define true 1
#define false 0

struct stack
{
    int TOP;
    int data[MAX];
};

int isFull(struct stack *s)
{
    return s->TOP==MAX-1?true: false;
}
int isEmpty(struct stack *s)
{
    return s->TOP == -1?true:false;
}
void PUSH(struct stack *s, int element)
{
    //increases TOP by 1 and inserts element to the stack
    s->data[++s->TOP] = element;

}
int POP(struct stack *s)
{
    return s->data[s->TOP--];
}
int peek(struct stack *s)
{
    return s->data[s->TOP];
}
int main()
{
    struct stack s= {-1}; //initializes TOP of the STACK to -1
    int choice,value;
    

    do{
        printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
        printf(">");
        scanf("%d",&choice);
     switch (choice)
     {
      case 1:
        if(isFull(&s)) printf("STACK OVERFLOWN\n");
        else {
            printf("Enter element to insert: ");
            scanf("%d",&value);
            PUSH(&s,value);
            printf("\n%d was pushed.\n",value);
        }
        break;
      case 2:
        if(isEmpty(&s)) printf("Stack UNDERFLOWN.\n");
        else{
            printf("%d is popped.\n",POP(&s));
        }
        break;
      case 3:
        if(isEmpty(&s)) printf("Stack UNDERFLOW.\n");
        else{
            printf("%d is at TOP.\n",peek(&s));
        }
        break;
      case 4:
        printf("BYE BYE!\n");
        break;
     default:
        printf("Enter 1,2,3 or 4 only.\n");
        break;
     }
    }while(choice !=4);
 
  return 0;  
}