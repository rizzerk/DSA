#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY '~'
#define DELETED '!'

typedef char Dictionary[MAX];

void initDictionary(Dictionary A){
    for(int i=0; i < MAX; i++){
        A[i] = EMPTY;
    }
}
//member

int Hash(char c){
    return c % 10;
}

int isMember(Dictionary A, char c){
        int indx, sl;

        for (indx = Hash(c), sl =1; sl < MAX && A[indx] != c && A[indx]!= EMPTY; indx = (indx + 1) % MAX, sl++){}

        return (sl <  MAX && A[indx] == c);
}
void insert(Dictionary A, char c){
    int indx, sl; 

    for(indx = Hash(c), sl =1; sl < MAX && A[indx] != c  && A[indx]!= EMPTY && A[indx] != DELETED; indx =(indx + 1)% MAX, sl++){}

    if(sl < MAX && A[indx] != c){
        A[indx] = c;
    }

    
}
void deleteMem(Dictionary A, char c){
    int indx, sl;

    for(indx = Hash(c), sl = 1; sl < MAX && A[indx] != c && A[indx]!= EMPTY; indx = (indx + 1) % MAX, sl++){}

    if(sl < MAX && A[indx] == c){
        A[indx] = DELETED;
    }
}

int getSL(Dictionary A, char c){
    int indx, sl;

        for (indx = Hash(c), sl =1; sl < MAX && A[indx] != c && A[indx]!= EMPTY; indx = (indx + 1) % MAX, sl++){}

        return (sl <  MAX && A[indx] == c) ? sl : 0;
}

int main(){
    Dictionary A;


    return 0;
}

