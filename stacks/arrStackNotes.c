#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int elems[MAX];
    int top;
}arrStack;

void initStack(arrStack *s){
    s->top = -1;
}

int isFull(arrStack s){
    return s.top == MAX-1;
}

int isEmpty(arrStack s){
    return s.top == -1;
}

void push(arrStack *s, int data){
    if(isFull(*s)){
        printf("Stack is full. Failed to push data.\n");
        return;
    }else{
        s->elems[++s->top] = data;
    }
}


int pop(arrStack *s){
    int data;
    if(!isEmpty(*s)){
        printf("No data to pop. Stakc is empty\n");
        return -1;
    }else{
        data = s->elems[s->top--];
    }

    return data;
}

int peek(arrStack *s){
    return isEmpty(*s) ? -1: s->elems[s->top];
}

//display stack
//sort stack

void sortStack(arrStack *orig){
    arrStack aux;
    initStack(&aux);

    while(!isEmpty(*orig)){
        int temp = pop(orig);

        while(!isEmpty(aux) && peek(&aux) > temp){
            push(orig, pop(&aux));
        }
        push(&aux, temp);
    }

    while(!isEmpty(aux)){
        push(orig, pop(&aux));
    }

}







int main(){

    return 0;
}