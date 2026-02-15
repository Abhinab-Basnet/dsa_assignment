// Given the array of the data (unsorted), Write a program to build the min and max heap.

#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_Heapify(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        min_Heapify(arr, n, smallest);
    }
}

void max_Heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        max_Heapify(arr, n, largest);
    }
}
void build_Min_Heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        min_Heapify(arr, n, i);
    }
}
void build_Max_Heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        max_Heapify(arr, n, i);
    }
}
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;

    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    build_Min_Heap(arr, n);
    printf("Min Heap:");
    printArray(arr, n);

    build_Max_Heap(arr, n);
    printf("Max Heap:");
    printArray(arr, n);

    return 0;
}