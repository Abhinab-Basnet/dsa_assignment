## Min Heap and Max Heap Implementation

## INTRODUCTION

A heap is a specialized complete binary tree that satisfies the heap property:

- Min Heap: The value of each node is less than or equal to its children. The root contains the smallest element.

- Max Heap: The value of each node is greater than or equal to its children. The root contains the largest element.

This program demonstrates building a Min Heap and a Max Heap from an array of integers using the heapify technique.

## OBJECTIVES

The objectives of this program are:

1. To understand the concept of Min Heap and Max Heap.

2. To implement minHeapify and maxHeapify functions.

3. To build Min Heap and Max Heap from an input array.

4. To manipulate array elements to satisfy heap properties.

5. To display the resulting Min Heap and Max Heap.

## DATA STURCTURE USED

This program uses:
```bash
int arr[n];  
```
**EXPLANATION**

- arr[n]

The input array is used to represent the binary tree in a level-order manner.

- The heap structure is stored implicitly in the array:

- Left child of node i → 2*i + 1

- Right child of node i → 2*i + 2

- Parent of node i → (i-1)/2

## DESCRIPTION OF FUNCTION IMPLEMENTED

1. swap(int *a, int *b)

**Purpose:**
 
 Swaps the values of two integers using pointers.
 ```bash
 void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
```
**Description**

- Stores the value of *a in temp.

- Assigns the value of *b to *a.

- Assigns the value of temp to *b.


2. min_Heapify(int arr[], int n , int i)

**Purpose:**

Ensures that the subtree rooted at index i satisfies Min Heap property.
```bash
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
```
**Description**

- Finds the smallest among the root, left child, and right child.

- If the root is not the smallest, swaps it with the smallest child.

- ecursively applies minHeapify to the affected subtree to maintain the Min Heap property.

3. max_Heapify(int arr[],int n, int i)

**Purpose:**

Ensures that the subtree rooted at index i satisfies Max Heap property.
```bash
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
```
**Description**

- Finds the largest among the root, left child, and right child.

- If the root is not the largest, swaps it with the largest child.

- Recursively applies maxHeapify to the affected subtree to maintain the Max Heap property.


4. build_Min_Heap(int arr[], int n)

 **Purpose:**

Builds a Min Heap from an unsorted array.

```bash
void build_Min_Heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        min_Heapify(arr, n, i);
    }
}
```
**Description**

- Starts from the last non-leaf node (n/2 - 1).

- Calls minHeapify on each node in reverse level order.

- Ensures the entire tree satisfies the Min Heap property.


5. build_Max_Heap(int arr[], int n)

**Purpose:**

Builds a Max Heap from an unsorted array.

```bash
void build_Max_Heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        max_Heapify(arr, n, i);
    }
}
```
 **Description**

- Starts from the last non-leaf node.

- Calls maxHeapify on each node in reverse level order.

- Ensures the entire tree satisfies the Max Heap property.

6. printArray(int arr[], int n)

**Purpose:**

 Prints the elements of the array representing the heap.
 ```bash
 void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```
**Description**

- Traverses the array from index 0 to n-1.

- Prints each element separated by a space.

## ORGANIZATION OF main() FUNCTION
```bash
int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    build_Min_Heap(arr, n);
    printf("Min Heap: ");
    printArray(arr, n);

    build_Max_Heap(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);

    return 0;
}
```
**STEPS PERFORMED IN main() FUNCTION:**

1. Reads the number of elements from the user.

2. Inputs the array elements.

3. Calls build_Min_Heap() to create a Min Heap.

4. Displays the Min Heap.

5. Calls build_Max_Heap() to create a Max Heap.

6. Displays the Max Heap.

## SAMPLE INPUT/OUTPUT

**Input**
```bash
Enter number of elements: 5
Enter elements: 4 2 7 1 3
```
**Output**
```bash
Min Heap: 1 2 4 7 3
Max Heap: 7 4 2 1 3
```

## CONCLUSION

This program demonstrates the construction of Min Heap and Max Heap from an array using the heapify technique. It shows how parent-child relationships in a binary tree can be efficiently maintained using arrays. The program highlights the recursive process of heapifying subtrees to satisfy heap properties.