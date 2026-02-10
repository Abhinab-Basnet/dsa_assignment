//Write and Implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void insert (struct Node **head, int value){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node * temp = *head;
    while(temp->next != NULL)
    temp = temp->next;

    temp->next = newNode;
}

void reverse_Traverse(struct Node *head){
    if (head == NULL)
    return;

    reverse_Traverse(head->next);
    printf("%d", head->data);
}

int main(){
    struct Node *head = NULL;
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Reverse tracersal of Linked List:\n");
    reverse_Traverse(head);

    return 0;
}