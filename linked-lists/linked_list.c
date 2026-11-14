#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int elem;
    struct Node* next;
} node ;


void linkedListTraversal(node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->elem);
        ptr = ptr->next;
    }
}

void insertAtFirst(node** ptr_head, int elem) {
    node* ptr = malloc(sizeof(node));
    ptr->elem = elem;
    ptr->next = *ptr_head;

    *ptr_head = ptr;
}

void insertAtLast(node* head, int elem) {
    node* ptr = malloc(sizeof(node));
    while (head->next != NULL) head = head->next;

    ptr->elem = elem;
    ptr->next = NULL;
    head->next = ptr;
}

void insertAtIndex(node* head, int elem, int index) {
    node* ptr = malloc(sizeof(node));
    ptr->elem = elem;

    for(int i = 0; i < index-1; i++) {
        head = head->next;
        if(head == NULL) {
            fprintf(stderr, "The index %d doesn\'t exist.\n", index);
            return;
        }
    }
    node* after = head->next;
    head->next = ptr;
    ptr->next = after;
}

void insertAfterNode(node* prevNode, int elem) {
    node* ptr = malloc(sizeof(node));
    ptr->elem = elem;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

void deleteFirst(node** head) {
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(node* head) {
    node* before_end = head;
    while (before_end->next->next != NULL) {
        before_end = before_end->next;
    }
    free(before_end->next);
    before_end->next = NULL;
}

void deleteNode(node* head, node* _node) {
    node* prev_node = head;
    while(prev_node->next!=_node) prev_node = prev_node->next;
    prev_node->next = _node->next;
    free(_node);
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
    node* head = malloc(sizeof(node));
    node* second = malloc(sizeof(node));

    head->elem = 7;
    head->next = second;

    second->elem = 3;
    second->next = NULL;

    linkedListTraversal(head);

    putchar('\n');
    
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 54);
    insertAtLast(head, 52);
    insertAtIndex(head, 23, 6);
    insertAfterNode(second, 34);
    // deleteLast(head);
    deleteNode(head, second);
    
    linkedListTraversal(head);

    free_list(head);
    
	return 0;
}