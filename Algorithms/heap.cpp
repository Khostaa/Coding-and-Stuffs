// Using CPP
#include <iostream>
using namespace std;

void enqueue(int arr[], int *i);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);
void display(int arr[], int *i);
void dequeue(int arr[], int *i);
void HeapSort(int arr[], int n);
void buildHeap(int arr[], int n);

int main()
{
    int Arr[10],caseNum = 1;
    int i = 0;
    while (caseNum != 4)
    {
        cout<< "1. Enqueue" << endl;
        cout<< "2. Dequeue" << endl;
        cout<< "3. Display" << endl;
        cout<< "4. Exit" << endl;
        cout<< "Enter your choice: ";
        cin>> caseNum;
        switch (caseNum)
        {
            case 1:
                cout<< "Enqueue" << endl;
                enqueue(Arr,&i);
                break;
            case 2:
                cout<< "Dequeue" << endl;
                dequeue(Arr,&i);
                break;
            case 3:
                cout<< "Display" << endl;
                display(Arr,&i);
                break;
            case 4:
                cout<< "Exit" << endl;
                break;
            default:
                cout<< "Invalid choice" << endl;
                break;
        }
    }
}

void enqueue(int arr[], int *i)
{
    cout<< "Enter the number: ";
    cin>> arr[*i];
    *i = *i + 1;
    // heapify(arr, *i, *i/2);
    HeapSort(arr, *i);
}

void heapify(int arr[],int n, int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;
    if (l <= n && arr[l-1] > arr[largest-1])
        largest = l;
    if (r <= n && arr[r-1] > arr[largest-1])
        largest = r;
    if (largest != i)
    {
        swap(arr[i-1], arr[largest-1]);
        heapify(arr, n, largest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void buildHeap(int arr[], int n)
{
    for (int i = n/2; i >= 1; i--)
        heapify(arr, n, i);
}

void HeapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n; i >= 2; i--)
    {
        swap(arr[0], arr[i-1]);
        n = n - 1;
        heapify(arr, n, 1);
    }
}

void dequeue(int arr[], int *i)
{
    if (*i == 0)
        cout<< "Queue is empty" << endl;
    else
    {
        cout<< "Deleted element is: " << arr[0] << endl;
        arr[0] = arr[*i-1];
        *i = *i - 1;
        // heapify(arr, *i, 1);
        HeapSort(arr, *i);
    }
}

void display(int arr[], int *i)
{
    if (*i == 0)
        cout<< "Queue is empty" << endl;
    else
    {
        cout<< "Queue is: " << endl;
        for (int j = 0; j < *i; j++)
            cout<< arr[j] << " ";
        cout<< endl;
    }
}