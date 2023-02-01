//Actual ORG
#include <stdio.h>
#define size 10
int arr[size];
int rear=0,front=0;
int swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify (int arr[],int i,int n)
{
    int largest = i; //declaring node at index i as largest 
    int left = 2*i + 1; //node at index 2*i+1 is left node
    int right = 2*i + 2; //node at index 2*i + 2 is right node

    if (left <= n && arr[left]>arr[largest])
        {
            largest = left;
        }
    if (right <= n && arr[right]>arr[largest])
        {
            largest = right;
        }
    if (largest != i ) //if largest is not same as previous one
    {    
      swap(&arr[i],&arr[largest]);
      heapify(arr,largest,n);
    }
}

void enqueue(int e)
{
    if (rear == size ) printf("Queue is Full!\n");
    arr[rear]= e; //add element from rear end
    rear = rear + 1; //increase rear after insertion
    for (int i= size/2-1;i>=0;i--)
    {
        heapify(arr,i,size); //for max heap
    }
}
int dequeue()
{
    int temp;
    if(front == rear)
    {
        return 0;
    }
    else
    {
        int s = sizeof(arr);
        for(int i=0;i<s;i++)
        {
            if(i==0) temp = arr[i];
            arr[i]= arr[i+1];
        }
        s--;
        for (int i= s/2-1;i>=0;i--)
        {
            heapify(arr,i,s); //for max heap after removal of ROOT/highest priority element
        }   
        return temp;
}
    }
  
void display(int arr[],int s)
{
    s = rear; //for displaying only available elements
    for(int i=0;i<s;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n\n");
}
int main()
{
    int choice,element;
    
    do
    {
        printf("\nChoice?\n1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT\n");
        printf(">");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d",&element);
            enqueue(element);
            break;
        case 2:
            printf("%d is dequeued.\n",dequeue());
            break;
        case 3:
            display(arr,size);
            break;
        case 4:
            printf("Bye Bye!\n");
            break;
        
        default:
            printf("Enter 1,2,3 or 4 only.\n");
            break;
        }
     
    } while (choice!=4);
    return 0;
}
