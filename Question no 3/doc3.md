## REVERSE TRAVERSAL OF SINGLY LINKED LIST USING RECURSION

## INTRODUCTION
A linked list is a dynamic structure in which elements are stored in nodes and each nodes points to next node in the list.
In a signly linked list, traversal is normally performed in the forward direction only.Reverse traversal is not directly possible because there is no link to the previous node. This program demonstrates reverse traversal of a singly linked list using recursion.

## OBJECTIVES
The objectives of this program are:

1.To create a singly linked list.

2.To insert elements at the end of the linked list.

3.To traverse and display the linked list in reverse order using recursion.

4.To demonstrate the practical application of linked list traversal.

## DATA STRUCTURE USED
The program uses a singly linked list.
```bash
struct Node {
    int data;
    struct Node *next;
};
```
**EXPLANATION**

- data

Stores the integer value of the node.

- next

Stores the address of the next node in the linked list.

## DESCRIPTION OF FUNCTION IMPLEMENTED

1. **insert(struct Node **head, int value)**

**Purpose**

Insert a new node at the end of the linked list.
```bash
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
```
**DESCRIPTION**

-  Dynamically allocates memory for a new node.

-  Assigns data to the new node.

-  If the list is empty, the new node becomes the head.

-  Otherwise, the node is inserted at the end of the list.



2. **reverse_Traverse(struct Node *head)**

 **Purpose:**

Traverse and display the linked list in reverse order.
```bash
void reverse_Traverse(struct Node *head) {
    if (head == NULL)
        return;

    reverse_Traverse(head->next);
    printf("%d ", head->data);
}
```

### ORGANIZATION OF MAIN FUNCTION
```bash
int main() {
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Reverse Traversal of Linked List:\n");
    reverse_Traverse(head);

    return 0;
}
```
**Steps Performed in main():**

-  Initiliazes the linked list as empty.

-  Inserts elements into the linked list.

- Calls the reverse traversal function.

-  Displays the elements in reverse order.

## SAMPLE OUTPUT

```bash
Reverse Traversal of Linked List:
40 30 20 10
```

## CONCLUSION
This program demonstrates how reverse traversal of a singly linked list can be achieved using recursion. Since singly linked list donot support backward traversal,recursion provides an efficient and elegant solution without altering the list structure. The program highliights the importance of recursion in linked list operations.