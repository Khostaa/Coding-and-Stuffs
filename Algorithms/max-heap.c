//implement max-heap as priority queue
//bloatware
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//function that swaps
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n\n");
}
void swap(int *p,int *q)
{
    int t = *p; // t is temporary variable to perform swapping
    *p = *q;
    *q = t;
}
//function that finds largest among the nodes
void max_heapify(int arr[], int i, int n)
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
      swap(&arr[largest],&arr[i]);
      max_heapify(arr,largest,n);
    }
}
void build_max_heap(int arr[],int n)
{
    // builds maximum heap
    for(int i= (n/2 - 1);i>=0;i--)
    {
        max_heapify(arr,i,n);
    }
    //Heap Sort
    for(int i=n-1 ;i>=0;i--)
    {
        swap(&arr[0],&arr[i]); 
        max_heapify(arr,i,0); // to get highest element at TOP Again
    }
}
void enqueue(int arr[],int element,int n)
{
    //insertion into HEAP
    arr[n] = element; // adding latest element to last
    int largest = n; // assuming last element as largest
    int l = floor(largest/2); //for comparing largest with its parent node
    while(largest > 0 && arr[largest] > arr[l]) // if largest greater than parent node loop works
    {
        swap(&arr[largest],&arr[l]); // exchanges largest with parent node
        largest = l;
        l= l/2; // for comparing with predecessor parent node
    }
    n = n + 1; // as element is inserterd so, we increase n;
    printf("\nHEAP After Insertion: ");
    display(arr,n);
}
int dequeue(int arr[],int n)
{
    //as dequeue or deletion is done from the TOP
    int temp = arr[0]; // assinging root to temporary variable
    arr[0] = arr[n]; // root is replaced by element at last index
    max_heapify(arr,0,n-1); // adjusting HEAP without HIGHEST PRIORITY element
    n = n-1; // as element is removed/dequeued so, n decreases
    return temp;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7}; //initial heap
    int n = sizeof(arr)/sizeof(arr[0]);// n store size of an array/heap
    int choice,element;
    printf("\nHeap Before Sorting: ");
    display(arr,n);
    build_max_heap(arr,n); // function that finds largest among left, right and root nodes
    printf("\n Heap After Sorting as Priority Queue: ");
    display(arr,n);
   
    do
    {
        printf("\nChoice?\n1.Enqueue\n2.Dequeue\n3.EXIT\n");
        printf(">");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d",&element);
                enqueue(arr,element,n);
                break;
                
            case 2:
                printf("\n%d is removed from the HEAP.\n",dequeue(arr,n));
                printf("\nHEAP After deletion: ");
                display(arr,n);
                break;
            case 3:
                printf("Bye Bye!\n");
                break;
            default:
                printf("Enter Valid Number.!\n");
                break;

        }
    } while (choice != 3);
    
    return 0;
}