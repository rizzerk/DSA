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

  CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // should say full
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);
    
  return 0;
}

void initQueue(Queue *q){
  q->front = -1;
  q->rear = -1;
}

int isEmpty(Queue *q){
  return q->front == -1;
}

int isFull(Queue *q){
  return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int val){
  //mainly updates the rear
  if(isFull(q)){
    printf("Queue is Full\n");
    return;
  }else{
    if(isEmpty(q)){ //if empty kay same sila nga ga point sa first index
      q->front = q->rear = 0;
    }else{
      q->rear = (q->rear +1) % MAX; //normal nga pag add 1 pero if malapas na sa max kay balik zero
    }
    q->elems[q->rear] = val;
  }
}

int dequeue(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return -1;
  }else{
    int val = q->elems[q->front]; //store ang value sa front nga i pahawa sa queue
    if(q->front == q->rear){ //one element left
      q->front = q->rear = 0;//balik uno after deleting the sole element left
    } else {
      q->front = (q->front +1) % MAX; //normal nga pag add 1 pero if malapas na sa max kay balik zero
    }
    return val;
  }
}

void display(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty");
    return;
  }else {
    printf("Queue: ");
    int i = q->front;
    while (1!= q->rear)
    {
      printf("%d ", q->elems[i]);
    }
    return;
  }
}







