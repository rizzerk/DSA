#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the linked list
typedef struct {
    Node *head;   // pointer to the first node
    int count;    // number of nodes in the list
} LinkedList;

// Function prototypes
void initialize(LinkedList *L);
void insertFirst(LinkedList *L, int elem);
void insertLast(LinkedList *L, int elem);
void insertSorted(LinkedList *L, int elem);
void deleteFirst(LinkedList *L);
void deleteLast(LinkedList *L);
void deleteAllOccur(LinkedList *L, int elem);
int isMember(LinkedList *L, int elem);
void display(LinkedList *L);
void freeList(LinkedList *L);

// Main function for testing
int main() {
    LinkedList L;
    initialize(&L);

    // Example usage:
    // insertFirst(&L, 10);
    // insertLast(&L, 20);
    // display(&L);

    freeList(&L); // free all allocated nodes
    return 0;
}

// Function definitions (YOU will write inside)
void initialize(LinkedList *L) {
    L->head = NULL;
    L->count = 0;
}

void insertFirst(LinkedList *L, int elem) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = elem;
        newNode->next = L->head;
        L->head = newNode;
        L->count++;
    }
}

void insertLast(LinkedList *L, int elem) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node ** trav;
    for(trav = &L->head; *trav != NULL; trav = &(*trav)->next){}
    if(newNode != NULL){
        newNode->data = elem;
        newNode->next = NULL;
        *trav = newNode;
        L->count++;
    }


}

void insertSorted(LinkedList *L, int elem) {
    // your code here
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node **trav;
    for(trav = &L->head; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next){}
    if(newNode != NULL){
        newNode->data =elem;
        newNode->next = *trav;
        *trav = newNode;
        L->count++;
    }
}

void deleteFirst(LinkedList *L) {
    // your code here
    if(L->head != NULL){
        Node * temp = L->head;
        L->head = temp->next;
        free(temp);
        L->count--;
    }
}

void deleteLast(LinkedList *L) {
    // your code here
    if(L->count > 0){
        Node *temp;
        Node **trav;
        for(trav = &L->head; (*trav)->next != NULL; trav = &(*trav)->next){}
        temp = *trav;
        *trav = NULL;
        free(temp);
        L->count --;
    }
}

void deleteAllOccur(LinkedList *L, int elem) {
    if(L->count > 0){
        Node **trav;
        for(trav = &L->head; *trav != NULL;){
            if((*trav)->data == elem){
                    Node *temp = *trav;
                    *trav = (*trav)->next;
                    free(temp);
                    L->count--;
            }else{
                trav  = &(*trav)->next;
            }
        }
    }
}

int isMember(LinkedList *L, int elem) {
    
    Node *trav;
    for(trav = L->head; trav != NULL && trav->data != elem; trav = trav->next){}
    if(trav != NULL){
        return 1;
    }
    
    return 0; // placeholder
}

void display(LinkedList *L) {
    Node *trav;
    for(trav=L->head ; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
}

void freeList(LinkedList *L) {
    Node *trav = L->head;
    while(trav != NULL){
        Node *temp  = trav;
        trav = trav->next;
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}
