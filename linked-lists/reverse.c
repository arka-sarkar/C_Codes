#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int elem; struct Node* next;
} node;

void linkedListTraversal(node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->elem);
        ptr = ptr->next;
    }
}

void insertAtLast(node* head, int elem) {
    node* ptr = malloc(sizeof(node));
    while (head->next != NULL) head = head->next;

    ptr->elem = elem;
    ptr->next = NULL;
    head->next = ptr;
}

void free_list(node* head) {
    node* temp;
    while(head!=NULL){
        temp = head->next;
        free(head);
        head=temp;
    }
}

int main() {
    node *head = malloc(sizeof(node));

    head->elem = 12;
    head->next = NULL;

    insertAtLast(head, 34);
    insertAtLast(head, 28);
    insertAtLast(head, 44);
    insertAtLast(head, 378);    
    insertAtLast(head, 37);
    
    node *prev=NULL, *curr=head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    linkedListTraversal(head);

    return 0;
}