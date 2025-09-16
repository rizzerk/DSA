#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int elems[MAX];
  int front;
  int rear;
}Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
void display(Queue *q);


int main(){
  Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
  return 0;
}

void initQueue(Queue *q){
  q->front = -1;
  q->rear = -1;
}

int isEmpty(Queue *q){
  //if-1 ang index sa front return 1 or true else 0 or false
  return q->front == -1;
}

int isFull(Queue *q){
  //if nana sa pinaka last nga index and rear return 1 or true else 0 or false
  //only for linear queue;
  return q->rear == MAX -1;
}

void enqueue(Queue *q, int val){
  if(isFull(q)){
    printf("Queue is full\n");
    return;
  } else {
    if(isEmpty(q)){
      q->front = 0;
    }
    q->rear ++;
    q->elems[q->rear] = val;
    printf("%d enqueued \n", val);
  }
}

int dequeue(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return;
  }else{
    int val = q->elems[q->front];
    if(q->front == q->rear){
      q->front = q->rear = -1;
    }else{
      q->front++;    
    }
    return val;
  }
}

void display(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return;
  } 
  printf("Queue: ");
  for(int i = q->front ; i < q->rear; i++){
    printf("%d ", q->elems[i]);
  }
  printf("\n");
}




