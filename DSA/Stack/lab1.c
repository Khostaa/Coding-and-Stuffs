//LAB 1: implementation of Stack as ADT
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
int isFull(struct stack s)
{
    return (s.TOP == MAX - 1)? true : false;
}
int isEmpty(struct stack s)
{
    return (s.TOP == -1)? true : false;
}
void push(struct stack *s,int element)
{
    if(isFull(*s))   // sending value of s to the function as *s is pointer.
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        s->TOP +=1;
        s->data[s->TOP] = element;
        printf("Success.\n");
    }
}
int pop(struct stack *s)
{
    if(isEmpty(*s))
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else 
        return s->data[s->TOP--];

}
int main()
{
    int choice,element;
    struct stack any = {-1}; //or intialize any and any.TOP = -1;
    do
    {
        printf("1.PUSH\n2.POP\n3.EXIT\n");
        printf("Choice? ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element\n");
                scanf("%d",&element);
                push(&any,element);
                break;
            case 2:
                printf("%d was popped\n",pop(&any));
                break;
            case 3:
                printf("Bye Bye!\n");
                break;
        }
    } while (Ochoice != 3);
   return 0; 
}