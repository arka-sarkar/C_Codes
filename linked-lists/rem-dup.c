#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int elem;
    struct Node* next;
} node ;


void linkedListTraversal(node* head) {
    node *copy_head = head;
    while (head != NULL) {
        if(head != copy_head) putchar(' ');
        printf("%d", head->elem);
        head = head->next;
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
    int n;
    scanf(" %d", &n);
    node* head = malloc(sizeof(node));
    scanf(" %d", &(head->elem));
    head->next=NULL;
    int elem;
    for(int i = 1; i < n; i++) {
        scanf(" %d", &elem);
        insertAtLast(head, elem);
    }

    node* temp = head;
    while(temp->next != NULL) {
        if(temp->elem == temp->next->elem) {
            node* temp1 = temp->next;
            temp->next = temp1->next; 
            free(temp1);
        } else temp=temp->next;
    }
    
    linkedListTraversal(head);
    free_list(head);
    putchar('\n');
    return 0;
}