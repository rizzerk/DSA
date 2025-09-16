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
int getSize(Queue q);
void display(Queue q);


int main(){
Queue q;
    initializeQueue(&q);
    
    int choice, value;
    
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Size\n");
        printf("6. Is Empty?\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
                
            case 2:
                dequeue(&q);
                break;
                
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
                
            case 4:
                display(q);
                break;
                
            case 5:
                printf("Queue size: %d\n", getSize(q));
                break;
                
            case 6:
                printf("Queue is %s\n", isEmpty(&q) ? "empty" : "not empty");
                break;
                
            case 7:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);
    
    freeQueue(&q);
    return 0;


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

int getSize(Queue q){
  int count = 0;
  for(count; q.front != NULL; q.front = q.front->next, count++){}
  return count;
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




