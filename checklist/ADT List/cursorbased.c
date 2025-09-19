#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data;
    int next; // index of next element in array
} Node;

typedef struct {
    Node elems[MAX]; // array to store nodes
    int avail;       // index of first available node
} vHeap;

typedef int cList; // head of the list (index of first node)

// Function prototypes
void initVHeap(vHeap *VH);
int allocSpace(vHeap *VH);
void deallocSpace(vHeap *VH, int pos);
void initialize(cList *L, vHeap *VH);
void insertFirst(cList *L, vHeap *VH, int elem);
void insertLast(cList *L, vHeap *VH, int elem);
void insertSorted(cList *L, vHeap *VH, int elem);
void deleteFirst(cList *L, vHeap *VH);
void deleteLast(cList *L, vHeap *VH);
void deleteAllOccur(cList *L, vHeap *VH, int elem);
int isMember(cList L, vHeap *VH, int elem);
void display(cList L, vHeap *VH);

// Main function for testing
int main() {
    vHeap VH;
    cList L;

    initVHeap(&VH);
    initialize(&L, &VH);

    // Example usage:
    // insertFirst(&L, &VH, 10);
    // insertLast(&L, &VH, 20);
    // display(L, &VH);

    return 0;
}

// Function definitions (YOU will fill in)
void initVHeap(vHeap *VH) {
    // Initialize all nodes as available
    VH->avail = 0;
    int i;
    for(i = 0; i < MAX - 1; i++){
        VH->elems[i].next = i+1;
    }
    VH->elems[i].next = -1;
}

int allocSpace(vHeap *VH) {
    // Allocate node from available list
    int indx = VH->avail;
    if(indx != -1){
        VH->avail = VH->elems[indx].next;
    }
    return indx; // placeholder
}

void deallocSpace(vHeap *VH, int pos) {
    // Return node at pos to available list
    VH->elems[pos].next = VH->avail;
    VH->avail = pos;
}

void initialize(cList *L, vHeap *VH) {
    // Initialize the list head
    *L = -1;
}

void insertFirst(cList *L, vHeap *VH, int elem) {
    // Insert element at beginning
    int temp = allocSpace(VH);
    if(temp != -1){
        VH->elems[temp].data = elem;
        VH->elems[temp].next = *L;
        *L = temp;
    }
}

void insertLast(cList *L, vHeap *VH, int elem) {
    // Insert element at end
    cList temp = allocSpace(VH);
    if(temp != -1){
        cList *trav;
        for(trav = L; *trav != -1; trav = &VH->elems[*trav].next){}
        VH->elems[temp].data = elem;
        VH->elems[temp].next = -1; //or -1;
        *trav = temp;
    }
}

void insertSorted(cList *L, vHeap *VH, int elem) {
    // Insert element in order
    cList temp = allocSpace(VH);
    if(temp != -1){
        cList *trav;
        for(trav = L; *trav != -1 && VH->elems[*trav].data < elem; trav = &VH->elems[*trav].next){}
        VH->elems[temp].data = elem;
        VH->elems[temp].next = *trav;
        *trav = temp;
    }
}

void deleteFirst(cList *L, vHeap *VH) {
    // Delete first element
    if(*L != -1){
        int temp = *L;
        *L = VH->elems[*L].next;
        deallocSpace(VH, temp);
    }
}

void deleteLast(cList *L, vHeap *VH) {
    // Delete last element
    if(L != -1){
        cList *trav;
        for(trav = L; VH->elems[*trav].next != -1; trav = &VH->elems[*trav].next){}
        int temp = *trav;
        *trav = VH->elems[temp].next;
        deallocSpace(VH, temp);
    }
}

void deleteAllOccur(cList *L, vHeap *VH, int elem) {
    // Delete all occurrences of elem
    if(L != -1){
        cList *trav;
        for(trav = L; *trav != -1;){
            if(VH->elems[*trav].data == elem){
                int temp = *trav;
                *trav = VH->elems[*trav].next;
                deallocSpace(VH, temp);
            }else{
                 trav = &VH->elems[*trav].next;
            }

        }
    }

}

int isMember(cList L, vHeap *VH, int elem) {
    // Search for elem
    cList trav;
    for(trav = L; trav != -1 && VH->elems[trav].data != elem; trav = VH->elems[trav].next){}
    if(trav != -1){
        return 1;
    }

    return 0; // placeholder
}

void display(cList L, vHeap *VH) {
    // Display list elements
    for(int i = L; i != -1;  i = VH->elems[i].next){
        printf("%d ", VH->elems[i].data);
    }
}
