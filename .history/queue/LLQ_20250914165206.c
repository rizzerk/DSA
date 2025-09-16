#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data; 
  struct Node* next;
}Node;

typedef struct
{
  Node* front;
  Node* rear;
}Queue;

Node* createNode(int data);
void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int peak(Queue *q);
void display(Queue q);


int main(){

}

Node* createNode(int data){
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}

void initQueue(Queue *q){
  q->front = NULL;
  q->rear = NULL;
}
int isEmpty(Queue *q){
  return q->front == NULL;
}

void enqueue(Queue *q, int val){
  Node *newNode = createNode(val);
  if(isEmpty(q)){
    q->front = q->rear = newNode;
  }else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
  printf("Enqueued: %d\n", val);
}

int dequeue(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return -1;
  }

  Node *temp = q->front;
  int val = temp->data;
  q->front = q->front->next;

  if(q->front == NULL){
    q->rear == NULL;
  } 

  free(temp);
  printf("Dequeued: %d\n", val);
  return val;
}
int peak(Queue *q){
  if(isEmpty(q)){
    printf("Queue is Empty\n");
    return -1;
  }
  return q->front->data;
}
void display(Queue q){
  if(isEmpty(&q)){
    printf("Queue is Empty\n");
    return;
  }else {
    for(; q.front != NULL ; q.front = q.front->next){
      printf("%d ", q.front->data);
    }
  }
}




