//Double ended Array queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
  int elems[MAX];
  int front;
  int rear;
}Queue;


void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void insertFront(Queue *q, int val);
void insertRear(Queue *q, int val);
int deleteFront(Queue *q);
int deleteRear(Queue *q);
int peekFront(Queue *q);
int peekRear(Queue *q);
void display(Queue *q);

int main(){
  Queue dq;
    initQueue(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    printf("Deleted from rear: %d\n", deleteRear(&dq));
    display(&dq);

    printf("Deleted from front: %d\n", deleteFront(&dq));
    display(&dq);


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

void insertFront(Queue *q, int val){
  if(isFull(q)){
    printf("Queue is full \n");
    return;
  }else{
    if(isEmpty(q)){
      q->front = q->rear = 0;
    }else{
      q->front = (q->front - 1 + MAX) % MAX;
    }
    q->elems[q->front] = val;
    printf("%d inserted at front\n", val);
  }
}


void insertRear(Queue *q, int val){
  if(isFull(q)){
    printf("Queue is Full\n");
    return;
  }else{
    if(isEmpty(q)){
      q->front = q->rear = 0;
    }else{
      q->rear = (q->rear + 1) % MAX;
    }
    q->elems[q->rear] = val;
    printf("%d inserted at the rear\n", val);
  }
}

int deleteFront(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return -1;
  }else {
    int val = q->elems[q->front];
    if(q->front == q->rear){
      q->front = q->rear = -1;
    }else{
      q->front = (q->front + 1) % MAX;
    }    
    return val;
  }

}
int deleteRear(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return -1;
  }else{
    int val = q->elems[q->rear];
    if(q->front == q->rear){
      q->front = q->rear = -1;
    }else{
      q->rear = (q->rear - 1 + MAX) % MAX;
    }

    return val;
  }

}

int peekFront(Queue *q){
  if(!isEmpty(q)){
    return q->elems[q->front];  
  }else{
    printf("Queue is Empty\n");
    return -1;
  }
}
int peekRear(Queue *q){
  if(!isEmpty(q)){
    return q->elems[q->rear];  
  }else{
    printf("Queue is Empty\n");
    return -1;
  }
}
void display(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return;
  }else {
    printf("Queue: ");
    int i = q->front;
    while (i!= q->rear)
    {
      printf("%d ", q->elems[i]);
      i = (i+1) % MAX;
    } 
    printf("%d \n", q->elems[q->rear]);
    return;
  }
}






















