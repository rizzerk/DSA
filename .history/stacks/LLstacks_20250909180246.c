#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;

typedef struct{
  node * head;
}stack;

void initStack(stack *s);
int isEmpty(stack s);
void push(stack *s, int data);
int pop(stack *s);
int peek(stack *s);

int main(){


}

void initStack(stack *s){
  s->head = NULL;
}

int isEmpty(stack s){
  return s.head == NULL ? 1: 0;
}

//same ra sa insertfirst sa LL
void push(stack *s, int data){
  node *temp = (node*)malloc(sizeof(node));
  if(temp != NULL){
    temp->link = s->head;
    temp->data = data;
    s->head = temp;
  }
}

int pop(stack *s){
  int n = -1;
  if(isEmpty(*s)==0){
    node *temp = s->head;
    n = temp->data;
    s->head = s->head->link;
    free(temp);
    return n;
  }else{
    printf("the stack is empty");
    return n;
  }

}

int peek(stack *s){
 return isEmpty(*s) == 0 ? s->head->data : -1;
}


