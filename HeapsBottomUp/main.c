#include <stdio.h>
#include <stdlib.h>

//#define max 100
//int heap[max];

int left(int i)
{
    return 2*i;
}


int right(int i)
{
    return 2*i+1;
}


void BottomUp(int x[], int size)
{
    for (int i =size/2; i>=1; i--) {
        MaxHeapify(x, size, i);
    }
}


void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int MaxHeapify(int x[],int size,int i)
{
    int largest =i;
    left(i);
    right(i);
    
    if (left(i)<=size  && x[left(i)]>x[largest]) {
        largest = left(i);
    }
    else
        largest = i;
    if (right(i)<=size && x[right(i)]>x[largest]) {
        largest =right(i);
    }
    if (largest!=i) {
//        int temp = heap[i];
//        heap[i]=heap[largest];
//        heap[largest]=temp;
//        i = largest;
        swap(&x[i], &x[largest]);
        MaxHeapify(x, size, i);
    }
    return 0;
}


void display(int x[],int size)
{
    for (int i=0; i<size; i++) {
        printf("%d\n",x[i]);
    }
}
int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,9,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    BottomUp(arr, size);
    display(arr, size);
    return 0;
}
