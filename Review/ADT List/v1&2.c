

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define the list structure
typedef struct {
    int elems[MAX];  // array to hold elements
    int count;       // number of elements currently in the list
} List;

// Function prototypes
void initialize(List *L);
void insertFirst(List *L, int elem);
void insertLast(List *L, int elem);
void insertSorted(List *L, int elem);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAllOccur(List *L, int elem);
int isMember(List L, int elem);
void display(List L);

// Main function for testing
int main() {
    List L;
    initialize(&L);

    // You can call your functions here for testing
    // Example:
    // insertFirst(&L, 10);
    // insertLast(&L, 20);
    // display(L);

    return 0;
}

// Function definitions (YOU will write inside)

//V1
void initialize(List *L) {
    L->count = 0;
}

//V2
List* initialize() {
    List * list = (List*)malloc(sizeof(List));
    if(list != NULL){
        list->count = 0;
    }
    return list; // placeholder
}


void insertFirst(List *L, int elem) {
    if(L->count < MAX){
        int i;
       for(i= L->count; i > 0; i--){
           L->elems[i] = L->elems[i-1];
       }
       L->elems[i] = elem;
       L->count ++;
    }
}

void insertLast(List *L, int elem) {
    if(L->count < MAX){
        L->elems[L->count] = elem;
        L->count++;
    }
    
}

void insertSorted(List *L, int elem) {
    int i;
    if(L->count < MAX){
        for(i = 0; i < L->count && L->elems[i] < elem; i++){}
            int j;
            for(j = L->count; j > i; j--){
                L->elems[j] = L->elems[j-1];
            }
            L->elems[i] = elem;
            L->count++;  
    }
}

void deleteFirst(List *L) {
    if(L->count > 0){
        int i;
        for(i=0; i < L->count - 1; i++){
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
    // your code here
    if(L->count > 0){
        int i;
        for(i = 0; i < L->count; i++){
            if(L->elems[i] == elem){
                for(int j= i; j < L->count -1; j++){
                    L->elems[j] = L->elems[j+1];
                }
                L->count--;
                i--; //i check ang gi shift
            }
        }
    }
}

int isMember(List L, int elem) {
    int i;
    for(i = 0; i < L.count && L.elems[i] != elem; i ++){}
    if(i < L.count){
        return 1;
    }

    return 0;
}

void display(List L) {
    for(int i= 0 ; i < L.count; i++){
        printf("%d ", L.elems[i]);
    }
}
