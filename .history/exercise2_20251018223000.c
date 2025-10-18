#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct  node * next;
}*SET;

typedef SET Dictionary[MAX];

void initDictionary ( Dictionary A){

    for(int i =0 ; i < MAX; i++){
        A[i] = NULL;
    }

}

int Hash(int data){
    return data % 10;
}

void insertUnique( Dictionary A, int data){
    int indx = Hash(data);
    SET newNode, *trav;

    newNode = (SET)malloc(sizeof(struct node));

    for(trav = &A[indx]; *trav != NULL && (*trav)->data != data;  trav = &(*trav)->next);
    if(newNode != NULL && *trav == NULL){ 
        newNode->data = data;
        newNode->next = NULL;
        *trav = newNode;
    }

}


int main(){
    Dictionary A;

    initDictionary(A);

}