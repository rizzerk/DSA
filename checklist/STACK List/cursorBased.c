#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct{
	int elem;
	int link;
}Node;

typedef struct{
	Node node[MAX];
	int Avail;
}VirtualHeap;

typedef int Stack;

typedef enum{
	TRUE,FALSE
}boolean;

void initHeap(VirtualHeap* vh){
    vh->Avail = 0;
    int i;
    for(i = 0; i < MAX -1 ; i++){
        vh->node[i].link = i +1;
    }
    vh->node[i].link = -1;
}


void initialize(Stack*s){
    *s = -1; 
}

boolean isFull(VirtualHeap* vh){
    return vh->Avail == -1;
}

boolean isEmpty(Stack s){
    return s == -1;    
}

void push(VirtualHeap* vh, Stack* s, int x){
        Stack new = vh->Avail;
        if(new != -1){
            vh->Avail = vh->node[new].link;
            vh->node[new].elem = x;
            vh->node[new].link = *s;
            *s = new;
        }
}

int pop(VirtualHeap* vh,Stack* s){
    if(!isEmpty(*s)){
        Stack temp = *s;
        int n = vh->node[temp].elem;
        *s = vh->node[temp].link;
        vh->node[temp].link = vh->Avail;
        vh->Avail = temp;
    }

    return 0;
}

int top(VirtualHeap* vh,Stack s){
    return (s != -1) ? vh->node[s].elem : -1;
}

void display(VirtualHeap*,Stack *s);