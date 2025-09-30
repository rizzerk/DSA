//int A[5] = {1, 0, 1, 0, 0}; // Set A has elements 0 and 2
//int B[5] = {1, 1, 1, 0, 0}; // Set B has elements 0, 1, and 2


#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

typedef int Set[10]; //universal set

void initSet(Set S);
int isMember(Set S, int elem);
void insertElem(Set S, int elem);
void deleteElem(Set S, int elem);
int * setUnion(Set A, Set B);
int * setIntersection(Set A, Set B);
int * setDifference(Set A, Set B);
int isSubset(Set A, Set B);
int isEqual(Set A, Set B);
void display(Set S);

int main(){

}


void initSet(Set S){
    for(int i = 0; i < MAX; i++){
        S[i] = 0;
    }

    //or memset(S, 0, MAX * sizeof(S[0]));
}


//finds or contains
int isMember(Set S, int elem){
    return S[elem] == 1 ? 1 : 0;
}

void insertElem(Set S, int elem){
    S[elem] = 1;
}

void deleteElem(Set S, int elem){
    S[elem] = 0;
}

int * setUnion(Set A, Set B){
    int *C =  (int*)calloc(MAX, sizeof(int));

    for(int i= 0; i < MAX; i++){
        if(A[i] == 1 || B[i] == 1){
            C[i] = 1;
        }
    }

    return C;
}

int * setIntersection(Set A, Set B){
    int *C =  (int*)calloc(MAX, sizeof(int));

    for(int i= 0; i < MAX; i++){
        if(A[i] == 1 && B[i] == 1){
            C[i] = 1;
        }
    }

    return C;
}

int * setDifference(Set A, Set B){
    int *C =  (int*)calloc(MAX, sizeof(int));

    for(int i= 0; i < MAX; i++){
        if(A[i] == 1 && B[i] == 0){
            C[i] = 1;
        }
    }

    return C;
} 

int isSubset(Set A, Set B){
    for(int i=0;  i < MAX; i++){
        if(A[i] == 1 && B[i] == 0){
            return 0;
        }
    }

    return 1;
}

int isEqual(Set A, Set B){
    for(int i=0 ; i < MAX; i++){
        if(A[i] !=  B[i]){
            return 0;
        }
    }

    return 1;
}

void display(Set S);