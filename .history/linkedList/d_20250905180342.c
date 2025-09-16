#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

typedef struct{
  int elem[MAX];
  int count;
}Etype, *EPtr;

void init(EPtr *L){
  *L = (EPtr)malloc(sizeof(Etype));
  if(*L != NULL){
    (*L)->count = 0;
  }
}

int main(){

}