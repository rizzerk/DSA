#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* link;
}node, *LL;

void initLL(LL*);
void insertSorted(LL *, int data);
void insertFirst(LL *, int data);
void insertLast(LL *, int data);
void deleteMem(LL *, int data);
void deleteMults(LL *, int data);
void deleteFirst(LL *);
void deleteLast(LL *);
void display(LL);

int main(){


}

void initLL(LL* list){
  *list = NULL;
}

void insertSorted(LL * list, int data){
  LL newNode, *trav;

  for(trav = list; *trav != NULL && (*trav)->data <= data; trav = &(*trav)->link){} 
  newNode = (LL)malloc(sizeof(node));
  
  if(newNode != NULL){
    newNode->data = data;
  newNode->link = *trav;
  *trav = newNode;
  }

}

void insertFirst(LL *list, int data){
  LL newNode = (LL)malloc(sizeof(node));
  
  if(newNode != NULL){
    newNode->data = data;
    newNode->link = *list;
    *list = newNode;
  }

}


void insertLast(LL *, int data){
  LL newNode, *trav;
  


}
