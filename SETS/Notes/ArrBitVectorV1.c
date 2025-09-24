//Example
//int A[5] = {1, 0, 1, 0, 0}; // Set A has elements 0 and 2
//int B[5] = {1, 1, 1, 0, 0}; // Set B has elements 0, 1, and 2

#include <stdio.h>
#include <stdlib.h>
#define MAX 100  // universe size: elements are from 0 to MAX-1

typedef struct {
    int bits[MAX];  // each index is 0 (not in set) or 1 (in set)
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

    // Insert elements into A: {1, 3, 5}
    insertElem(&A, 1);
    insertElem(&A, 3);
    insertElem(&A, 5);

    // Insert elements into B: {3, 4, 5}
    insertElem(&B, 3);
    insertElem(&B, 4);
    insertElem(&B, 5);

    printf("Set A: ");
    display(A);  // Expected: 1 3 5

    printf("Set B: ");
    display(B);  // Expected: 3 4 5

    // Union of A and B
    C = setUnion(A, B);
    printf("Union (A U B): ");
    display(C);  // Expected: 1 3 4 5

    // Intersection of A and B
    C = setIntersection(A, B);
    printf("Intersection (A ∩ B): ");
    display(C);  // Expected: 3 5

    // Difference A - B
    C = setDifference(A, B);
    printf("Difference (A - B): ");
    display(C);  // Expected: 1

    // Difference B - A
    C = setDifference(B, A);
    printf("Difference (B - A): ");
    display(C);  // Expected: 4

    // Subset check
    printf("Is A subset of B? %s\n", isSubset(A, B) ? "Yes" : "No");  // No
    printf("Is intersection(A,B) subset of A? %s\n", isSubset(setIntersection(A,B), A) ? "Yes" : "No");  // Yes

    // Equality check
    printf("Is A equal to B? %s\n", isEqual(A, B) ? "Yes" : "No");  // No
    printf("Is A equal to A? %s\n", isEqual(A, A) ? "Yes" : "No");  // Yes


    return 0;
}

// ---------------------
// Function Definitions
// ---------------------

//S is the Universal set
void initSet(Set *S) {
    // Set all bits to 0
    for(int i = 0; i < MAX; i++){
        S->bits[i] = 0;
    }

   //or memset(S, 0, sizeof(S)); //for integer only

}

int isMember(Set S, int elem) {
    // return 1 if elem is in set, 0 otherwise
    return S.bits[elem] == 1 ? 1 : 0;
}

void insertElem(Set *S, int elem) {
    S->bits[elem] = 1;
}

void deleteElem(Set *S, int elem) {
    S->bits[elem] = 0;
}

Set setUnion(Set A, Set B) {
    Set C;
    initSet(&C);
    
    // for each index, C.bits[i] = A.bits[i] OR B.bits[i]
    for(int i=0; i < MAX; i++){
        if(A.bits[i] == 1 || B.bits[i] == 1){
            C.bits[i] = 1;
        }
    }


    return C;
}

Set setIntersection(Set A, Set B) {
    Set C;
    initSet(&C);
    // for each index, C.bits[i] = A.bits[i] AND B.bits[i]
    for(int i = 0; i <MAX ; i++){
        if(A.bits[i] == 1 && B.bits[i] ==1){
            C.bits[i] = 1;
        }
    }


    return C;
}

Set setDifference(Set A, Set B) {
    Set C;
    initSet(&C);
    // for each index, C.bits[i] = A.bits[i] AND NOT(B.bits[i])
    for(int i = 0; i < MAX; i++){
        if(A.bits[i] == 1 && B.bits[i] == 0){
            C.bits[i] = 1;
        }

    }

    return C;
}

int isSubset(Set A, Set B) {
    // return 1 if all bits set in A are also set in B
    for(int i =0 ; i < MAX ; i++){
        if(A.bits[i] == 1 && B.bits[i] == 0){
            return 0;
        }
    }
    return 1; // placeholder
}

int isEqual(Set A, Set B) {

    // return 1 if all bits are equal
     for(int i =0 ; i < MAX ; i++){
        if(A.bits[i] != B.bits[i]){
            return 0;
        }
    }
    return 1; // placeholder
}

void display(Set S) {
    // print indices of bits that are 1
    for(int i = 0; i < MAX; i++){
        if(S.bits[i] == 1){
            printf("%d ", i);
        }
    }

    printf("\n");
}
