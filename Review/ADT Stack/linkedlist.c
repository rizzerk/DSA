#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int elem;
	struct node *link;
}*Stack;

typedef enum{
	TRUE,FALSE
}boolean;

void initialize(Stack* s){
    *s = NULL;
}

boolean isEmpty(Stack s){
    return s == NULL ? TRUE : FALSE;
}

void push(Stack* s, int x){
    Stack newNode = (Stack)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = x;
        newNode->link = *s;
        *s = newNode;
    }
}

int pop(Stack* s){
    if(!isEmpty(*s)){
        Stack temp = *s;
        int n = temp->elem;
        *s = (*s)->link; //temp->link
        free(temp);
        return n;
    }
    return -1;
}

int top(Stack s){
    return s->elem;
}

// void display(Stack *s){
// }