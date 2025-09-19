

#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
	int containers[MAX];
	int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}
bool isFull(Stack *s){
    return s->top ==MAX -1 ;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s, int value){
    (!isFull(s)) ? s->containers[++s->top] = value : printf("Stack is full\n");
}

int pop(Stack *s){
     return (!isEmpty(s)) ? s->containers[s->top--] : -1;
}

int peek(Stack *s){
    return (!isEmpty(s)) ? s->containers[s->top] : -1;
}

void display(Stack *s){
    if(!isEmpty(s)){
        for(int i= s->top; i >= 0 ; i--){
            printf("%d ", s->containers[i]);
        }
    }
}


