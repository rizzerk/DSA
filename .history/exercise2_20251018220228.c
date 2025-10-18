#include <stdio.h>

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

int main(){


}