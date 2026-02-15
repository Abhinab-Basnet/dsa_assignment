## Random Number Sorting Using Various Algorithms

## INTRODUCTION

This program generates a list of N random integers in the range [1, 1000], where N is provided by the user at runtime. The user can then choose a sorting algorithm to sort these numbers.

- Supported sorting algorithms:

1. Bubble Sort

2. Selection Sort

3. Insertion Sort

4. Merge Sort

The program sorts the array using the chosen algorithm, displays the array before and after sorting, and shows the total number of comparisons and swaps/assignments performed.

## OBJECTIVES

The objectives of this program are:

- To generate a random list of integers using rand() function.

- To implement and demonstrate Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort algorithms.

- To allow the user to choose a sorting algorithm at runtime.

- To track the number of comparisons and swaps/assignments performed during sorting.

- To display the original and sorted arrays clearly.

## DATA STRUCTURE USED

This program uses:
```bash
int arr[];
int arr_copy[N];
```
**EXPLANATION**

- **arr[N]**: Contains the original randomly generated integers.

- **arr_copy[N]**: Used to sort the numbers while keeping the original array intact.

- The program uses basic arrays as the main data structure for sorting.

## DESCRIPTION OF FUNCTIONS IMPLEMENTED

1. **printArray(int arr[], int n)**

**Purpose:**

Prints all elements of the array.
```bash
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
```
**Description**

- Iterates through the array from index 0 to n-1.

- Prints each element separated by a space.

2. **bubbleSort(int arr[], int n)**

**Purpose**

Sorts the array using the Bubble Sort algorithm.

```bash
void bubbleSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
}
```
**Description**

- Repeatedly compares adjacent elements and swaps them if they are in the wrong order.

- Counts the number of comparisons and swaps.

- Ensures the largest element “bubbles up” to the end of the array in each pass.

3. **selectionSort(int arr[], int n)**

**Purpose**

Sorts the array using the Selection Sort algorithm.

```bash
void selectionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        if(min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
    }
}
```
**Description**
 
 - Finds the minimum element in the unsorted portion of the array.

- Swaps it with the first unsorted element.

- Updates comparison and swap counts.

4. **insertionSort(int arr[], int n)**

**Purpose**

Sorts the array using the Insertion Sort algorithm.

```bash
void insertionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0) {
            comparisons++;
            if(arr[j] > key) {
                arr[j+1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j+1] = key;
    }
}
```
**Description**

- Picks an element and inserts it into its correct position in the sorted part of the array.

- Counts comparisons and shifts as swaps.

5. **mergeSort(int arr[], int l, int r) and merge()**
  
  **Purpose**

  Sorts the array using the Merge Sort algorithm.
 ```bash
void merge(int arr[], int l, int m, int r) { ... }
void mergeSort(int arr[], int l, int r) { ... }
```
**Description**

- Divides the array into two halves recursively.

- Merges the two halves in sorted order using the merge() function.

- Counts comparisons and assignments/swaps during merging.

## ORGANIZATION OF main() FUNCTION:
```bash
int main() {
    int N, choice;
    scanf("%d", &N);

    int arr[N];
    srand(time(0));

    for(int i=0; i<N; i++)
        arr[i] = (rand() % 1000) + 1;

    printArray(arr, N);

    printf("Choose sorting algorithm:\n1. Bubble\n2. Selection\n3. Insertion\n4. Merge\n");
    scanf("%d", &choice);

    int arr_copy[N];
    for(int i=0; i<N; i++) arr_copy[i] = arr[i];

    switch(choice) {
        case 1: bubbleSort(arr_copy, N); break;
        case 2: selectionSort(arr_copy, N); break;
        case 3: insertionSort(arr_copy, N); break;
        case 4: mergeSort(arr_copy, 0, N-1); break;
    }

    printArray(arr_copy, N);
    printf("Comparisons: %d\nSwaps/Assignments: %d\n", comparisons, swaps);

    return 0;
}
```
**STEPS PERFORMED IN main() FUNCTION**

- Reads the number of elements N from the user.

- Generates N random integers in the range [1,1000].

- Displays the unsorted array.

- Prompts the user to select a sorting algorithm.

- Sorts the array using the chosen algorithm.

- Displays the sorted array.

- Shows total comparisons and swaps/assignments.

## SAMPLE INPUT/OUTPUT

**Input**
```bash
Enter number of elements: 5
Generated array: 523 15 732 44 301
Choose sorting algorithm: 2
```
**Output**
```bash
Original array: 523 15 732 44 301
Sorted array: 15 44 301 523 732
Total comparisons: 10
Total swaps: 4
```
## CONCLUSION

This program demonstrates multiple sorting algorithms on randomly generated integers. It highlights:

- Differences in sorting techniques.

- Tracking of comparisons and swaps for analysis.

- How arrays can be efficiently sorted using Bubble, Selection, Insertion, and Merge Sort.

It provides a clear understanding of the working and efficiency of basic sorting algorithms.