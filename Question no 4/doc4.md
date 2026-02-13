## INSERTION AND DELETION IN DOUBLY LINKED LIST.

## INTRODUCTION
A doubly linked list is a linear data structure in which each node contains three part: data, a pointer to the previous node, and a pointer to the next node. Unlike a singly linked list, a doubly linked list allow traversal in both forward and backward directions. This program demonstrates insertion after a given node and deletion of a specific node in a doubly linked list.

## OBJECTIVES
The objectives of this program are:
-  To create a doubly linked list.

-  To insert a new node after a given node in the list.

-  To delete a specified node from the list.

-  To display the elements of the doubly linked list.

-  To understand pointer manipulation in doubly linked lists.

## DATA STRUCTURE USED

The program uses a doubly linked list:
```bash
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```
**EXPLANATION**
- **data**

Stores the integer value of the node.

- **prev**

Stores the address of the previous node in the list.

- **next**

Stores the address of the next node in the list.

## DESCRIPTION OF FUNCTION IMPLEMENTED
1. **insert_After(struct Node *prevNode, int newData)**

 **Purpose:**

To insert a new node after a given node in a doubly linked list.
```bash
void insert_After(struct Node *prevNode, int newData){
    if(prevNode == NULL){
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != NULL){
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}
```
**Description:**

- Checks whether the given previous node is NULL.

-  Allocates memory for a new node dynamically.

-  Assigns data to the new node.

-  Adjusts the next and prev pointers to insert the node after the specified node.

-  Maintains the bidirectional links of the doubly linked list.

2. **delete+Node(struct Node **head, struct Node *delNode)**

**Purpose**

To delete a given node from the doubly linked list.
```bash
void delete_Node(struct Node **head, struct Node *delNode){
    if(*head == NULL || delNode == NULL){
        return;
    }
    if(*head == delNode){
        *head = delNode->next;
    }
    if(delNode->next != NULL){
        delNode->next->prev = delNode->prev;
    }
    if(delNode->prev != NULL){
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}
```
**Description**

- Checks whether the list or the node to be deleted is NULL.

-  Updates the head pointer if the node to be deleted is the first node.

-  Adjusts the prev and next pointers of adjacent nodes.

-  Frees the memory occupied by the delete node.

3. display(struct Node *head)

**Purpose;**

To display all elements of the doubly linked list.
```bash
void display(struct Node *head){
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```
**Description**

-  Starts traversal from the head node.

-  Prints each node's data while moving in the forward direction.

-  Continues until the end of the list is reached.


## ORGANIZATION OF main() FUNCTION
```bash
int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    display(head);
    
    insertAfter(second, 25);
    display(head);

    deleteNode(&head, second);
    display(head);

    return 0;
}
```
**STEPS PERFORMED IN main():**

1. Created three nodes and links them to form a doubly linked list.

2. Displays the initial list.

3. Inserts a new node with value 25 after the second node.

4. Displays the updated list.

5. Deletes the second node from the list.

6. Displays the final list.

## SAMPLE OUTPUT
```bash
Doubly Linked List: 10 20 30
Doubly Linked List: 10 20 25 30
Doubly Linked List: 10 25 30
```

## CONCLUSION
This program demonstrates the implementation of insertion and deletion operations in a doubly linked list. The presence of both prev and next pointers makes insertion and deletion more efficient compared to singly linked lists. the program highlights how proper pointer manipulation ensures correct maintenance of the list structure.