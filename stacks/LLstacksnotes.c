#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node * next;
}node;

typedef struct 
{
    node *top;
}stack;



void initStack(stack *s){
    s->top = NULL;
}

int isEmpty(stack *s){
    return s->top == NULL;
}

void push(stack *s, int data){
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
    }
}

int pop(stack *s){
    int retVal = -1;
    if(!isEmpty(s)){
        node *temp = s->top;
        s->top = temp->next;
        retVal = temp->data;
        free(temp);
    } 
    return retVal;
}

int peek(stack *s){
    return isEmpty(s) == 0 ? s->top->data : -1;
}

void sortStack(stack *orig){
    stack aux;
    initStack(&aux);
    int temp;
    while(!isEmpty(orig)){
        temp = orig->top->data;
        while (!isEmpty(&aux) && peek(&aux) > temp)
        {
            push(orig, pop(&aux));
        }
        push(&aux, temp);
    }

    while(!isEmpty(&aux)){
        push(orig, pop(&aux));
    }
}

int main(){

    return 0;
}