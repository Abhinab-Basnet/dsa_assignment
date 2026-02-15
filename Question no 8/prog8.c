#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int comparisons =0;
int swaps =0;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            comparisons++;
            if(arr[j] > arr[j+1]){
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            comparisons++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swaps++;
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
void insertionSort(int arr[], int n){
    comparisons=swaps=0;
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            comparisons++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void merge(int arr[], int l,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[m+1+j];
   }

   int i=0,j=0, k=l;
   while(i<n1 && j<n2){
       comparisons++;
       if(L[i] < R[j]){
           arr[k++] = L[i++];
       }else{
           arr[k++] = R[j++];
       }
       swaps++;
   }
   while(i<n1){
       arr[k++] = L[i++];
   }
   while(j<n2){
       arr[k++] = R[j++];
       swaps++;
   }
   while(i<n1){
       arr[k++] = L[i++];
   }
   while(j<n2){
       arr[k++] = R[j++];
       swaps++;
   }
}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int N, choice;
    printf("Enter number of elements:");
    scanf("%d", &N);

    int arr[N];
    srand(time(0));
    for(int i=0; i<N; i++){
        arr[i] = rand() % 100;
    }
     printf("\nGenerated array: \n");
    printArray(arr, N);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int arr_copy[N];
    for(int i=0; i<N; i++) arr_copy[i] = arr[i]; // Copy array to sort

    switch(choice) {
        case 1:
            bubbleSort(arr_copy, N);
            printf("\nBubble Sorted array: \n");
            break;
        case 2:
            selectionSort(arr_copy, N);
            printf("\nSelection Sorted array: \n");
            break;
        case 3:
            insertionSort(arr_copy, N);
            printf("\nInsertion Sorted array: \n");
            break;
        case 4:
            comparisons = swaps = 0;
            mergeSort(arr_copy, 0, N-1);
            printf("\nMerge Sorted array: \n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printArray(arr_copy, N);
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps/assignments: %d\n", swaps);

    return 0;
}