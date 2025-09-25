#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Set structure
typedef struct {
    int elems[MAX]; // elements of the set
    int count;      // number of elements
} Set;

// Function prototypes
void initSet(Set *S);
int isMember(Set S, int elem);
void insertElem(Set *S, int elem);
void deleteElem(Set *S, int elem);
Set setUnion(Set A, Set B);
Set setIntersection(Set A, Set B);
Set setDifference(Set A, Set B);
int isSubset(Set A, Set B);
int isEqual(Set A, Set B);
void display(Set S);

// Main function for testing
int main() {
    Set A, B, C;
    initSet(&A);
    initSet(&B);

    // Example usage:
    // insertElem(&A, 1);
    // insertElem(&A, 2);
    // insertElem(&B, 2);
    // insertElem(&B, 3);

    // C = setUnion(A, B);
    // display(C);

    return 0;
}


void initSet(Set *S) {
    // Initialize empty set
    S->count = 0;
}

int isMember(Set S, int elem) {
    // Check if elem is in the set
    for(int i=0; i < S.count; i++){
        if(S.elems[i] == elem){
            return 1;
        }
    }

    return 0;              
}

void insertElem(Set *S, int elem) {
    // Insert elem if not already a member
    if(!isMember(*S, elem) && S->count < MAX){
        S->elems[S->count++] = elem;
    }
}

void deleteElem(Set *S, int elem) {
    // Remove elem if it exists
    // for(int i=0; i < S->count; i++){
    //     if(S->elems[i] == elem){
    //         //shift elems
    //         for(int j = i; j < S->count-1; j++){
    //             S->elems[j] = S->elems[j+1];
    //         }
    //         S->count--;
    //         return;
    //     }
    // }

    int i; 
    for(i = 0;  i < S->count && S->elems[i] != elem; i++){}
    if(i < S->count){ 
        //if found 
        for(int j= i ; j < S->count-1; j++){
            S->elems[j] = S->elems[j + 1];
        }
        S->count--;
    }

}

Set setUnion(Set A, Set B) {
    Set C;
    initSet(&C);
    
    for(int i=0; i < A.count; i++){
        insertElem(&C, A.elems[i]);
    }

    for(int i=0; i < B.count; i++){
        insertElem(&C, B.elems[i]);
    }


    return C;
}

Set setIntersection(Set A, Set B) {
    Set C;
    initSet(&C);
    
    for(int i=0; i < A.count; i++){
        if(isMember(B, A.elems[i])){
            insertElem(&C, A.elems[i]);
        }
    }


    return C;
}

Set setDifference(Set A, Set B) {
    Set C;
    initSet(&C);
    
    for(int i=0; i < A.count; i++){
        if(!isMember(B, A.elems[i])){
            insertElem(&C, A.elems[i]);
        }
    }
    
    return C;
}

int isSubset(Set A, Set B) {
    // return 1 if A ⊆ B
    for(int i=0; i < A.count; i++){
        if(!isMember(B, A.elems[i])){
            return 0;
        }
    }
    return 1;
}

int isEqual(Set A, Set B) {
    // return 1 if A == B
    return isSubset(A, B) && isSubset(B, A) ? 1 : 0;
}

void display(Set S) {
    // Display elements of set
    for (int i = 0; i < S.count; i++)
    {
        printf("%d ", S.elems[i]);
    }
    
    printf("\n");
}
