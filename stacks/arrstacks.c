#include <stdio.h>

#define MAX 10
typedef struct 
{
  int elems[MAX];
  int top;
  /* data */
}arrStack;

//init
void initStack(arrStack *S);
//isEmpty
int isEmpty(arrStack S);
//isFull
int isFull(arrStack S);
//push
void push(arrStack *S, int data);
//pop kuhaon/iremove (tas i hold kay nag return man syag int) niya ang value sa top
int pop(arrStack *S);

//tan awn niya unsay naa sa top sa stack
int peek(arrStack *S);

int main(){

}

void initStack(arrStack *S){
  S->top = -1;
}

int isEmpty(arrStack S){
  return S.top == -1 ? 1 : 0;
}

int isFull(arrStack S){
  return S.top == MAX - 1 ? 1 :0;
}

void push(arrStack *S, int data){
  if(isFull(*S) == 0){ S->elems[++S->top] = data;}//addan niyag 1 ang top tas i access niya ang index/top para i add ang data 
                                                  //basically insert last tas keep track sa last index
  else {printf("stack is Full");}                                                
}

int pop(arrStack *S){
  
  return isEmpty(*S) == 0 ? S->elems[(S->top)--] : printf("stack is empty");
  // or
  // int n;
  // if(isEmpty(*S) == 0){
  //   n = S->elems[S->top];
  //   S->top --;
  // } else {
  //   n =-1;
  //   printf("Stack is Empty");
  // }

  // return n;
}

int peek(arrStack *S){
  int topValue = -1;
  if(isEmpty(*S) == 0){
    topValue = S->elems[S->top];
  }

  return topValue;
}