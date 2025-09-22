


#include <stdio.h>
#include <stdlib.h>

// Define the list structure
typedef struct {
    int *elems;   // pointer to a dynamic array
    int count;    // number of elements in the list
} List;

// Function prototypes
void initialize(List *L, int size);
void insertFirst(List *L, int elem);
void insertLast(List *L, int elem);
void insertSorted(List *L, int elem);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAllOccur(List *L, int elem);
int isMember(List L, int elem);
void display(List L);
void freeList(List *L);

// Main function for testing
int main() {
    List L;
    initialize(&L, 100); // allocate space for 100 elements initially
    //V4 - List *L = initialize(100);

    // Example usage:
    // insertFirst(&L, 10);
    // insertLast(&L, 20);
    // display(L);

    freeList(&L); // free allocated memory before program ends
    return 0;
}

// Function definitions (YOU will write inside)
//v3
void initialize(List *L, int size) {
    L->elems = (int*)malloc(sizeof(int)*size);
    L->count = 0;
}

//v4
List* initialize(int size) {
    List *l = (List*)malloc(sizeof(List));
    l->elems = (int*)malloc(sizeof(int)*size);
    l->count = 0;
    return l; 
}


void insertFirst(List *L, int elem) {
    if(L->count < 100){
        int i;
        for(i = L->count; i > 0; i--){
            L->elems[i] = L->elems[i -1];
        }
        L->elems[i] = elem;
        L->count++; 
    } 
}

void insertLast(List *L, int elem) {
    if(L->count < 100){
        L->elems[L->count++] = elem;
    } 
}

void insertSorted(List *L, int elem) {
    if(L->count < 100){
        int i;
        for(i = 0 ; i < L->count && L->elems[i] < elem; i++){}
        if(i < L->count){
            int j;
            for(j = L->count; j > i; j++){
                L->elems[j] = L->elems[j-1];
            }
        }
         L->elems[i] = elem;
         L->count++;
    }
}

void deleteFirst(List *L) {
    if(L->count > 0){
        int i;
        for(i = 0; i < L->count-1 ; i++){
            L->elems[i] = L->elems[i+1];
        }
        L->count--;
    }
}

void deleteLast(List *L) {
    if(L->count > 0){
        L->count--;
    }
}

void deleteAllOccur(List *L, int elem) {
    if(L->count > 0){
        // int i;
        // for(i = 0; i < L->count; i++){
        //     if(L->elems[i] == elem){
        //         int j;
        //         for(j = i; j < L->count-1; j+){
        //             L->elems[j] = L->elems[j+1];
        //         }
        //         L->count--;
        //         i--;
        //     }
        // }

        //or

        int i, j=0;
        for(i = 0; i < L->count; i++){
            if(L->elems[i] != elem){
                L->elems[j++] = L->elems[i];
            }
        }
        L->count = j;
    }
}

int isMember(List L, int elem) {
    // your code here
    for(int i=0; i < L.count; i ++){
        if(elem == L.elems[i]){
            return 1;
        }
    }
    return 0; // placeholder
}

void display(List L) {
    for (int i = 0; i < L.count; i++)
    {
        printf("%d ", L.elems[i]);
    }
}

void freeList(List *L) {
    free(L->elems);
    L->elems  = NULL;
    L->count = 0;    
}
