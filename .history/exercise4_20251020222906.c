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
    return c % MAX;
}

int isMember(Dictionary A, char c){
        int indx, sl;

        for (indx = Hash(c), sl =1; sl < MAX && A[indx] != c && A[indx]!= EMPTY; indx = (indx + 1) % MAX, sl++){}

        return (sl <  MAX && A[indx] == c);
}
int insert(Dictionary A, char c){
    int indx, sl; 

    for(indx = Hash(c), sl =1; sl < MAX && A[indx] != c  && A[indx]!= EMPTY && A[indx] != DELETED; indx =(indx + 1)% MAX, sl++){}

    if(sl < MAX && A[indx] != c){
        A[indx] = c;
    }

        int searchLength = (indx - Hash(c) + MAX) % MAX + 1;
        return searchLength; //or sl;
}
void deleteMem(Dictionary A, char c){
    int indx, sl;

    for(indx = Hash(c), sl = 1; sl < MAX && A[indx] != c && A[indx]!= EMPTY; indx = (indx + 1) % MAX, sl++){}

    if(sl < MAX && A[indx] == c){
        A[indx] = DELETED;
    }
}

int main(){
    Dictionary A;


    return 0;
}

