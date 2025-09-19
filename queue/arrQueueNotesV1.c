#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int elems[MAX];
    int front;
    int rear;
    int ctr;
}arrQueue;

void initQueue(arrQueue *q){
    q->front = -1;
    q->rear = -1;
    q->ctr = 0;
}

//circular
int isFull(arrQueue *q){
    return q->ctr == MAX;
}

int isEmpty(arrQueue *q){
    return q->ctr == 0;
}

void enqueue(arrQueue *q, int data){
    if(!isFull(q)){
     
        if(isEmpty(q)){
         q->front = q->rear = 0;   
        }else{
            q->rear = (q->rear + 1) % MAX;
        }
        q->elems[q->rear] = data;
        q->ctr++;
    }
}

int dequeue(arrQueue *q){
    int data = -1;

    if(!isEmpty(q)){
        data = q->elems[q->front];
        if(q->ctr == 1){
            q->front = q->rear = -1;
        } else{
            q->front = (q->front + 1) % MAX;
        }
        q->ctr --;
    }

    return data;
}


int main(){

    return 0;
}