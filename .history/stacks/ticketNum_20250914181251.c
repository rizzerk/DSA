#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct {
    char name[50];
    int ticketNumber;
} Customer;

typedef struct {
    Customer customers[MAX];
    int front;
    int rear;
    int count;
} Queue;

// Function prototypes (already provided)
void initQueue(Queue* Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue* Q, Customer c);
Customer dequeue(Queue* Q);
Customer front(Queue Q);
void displayQueue(Queue Q);

// YOUR TASK: Implement these functions!
// 1. initQueue() - Initialize an empty queue
// 2. isEmpty() - Check if queue is empty
// 3. isFull() - Check if queue is full
// 4. enqueue() - Add a customer to the rear of the queue
// 5. dequeue() - Remove and return the customer at the front
// 6. front() - Return the customer at front without removing
// 7. displayQueue() - Display all customers in the queue

int main() {
    Queue customerQueue;
    initQueue(&customerQueue);
    
    Customer customers[] = {
        {"Alice Johnson", 101},
        {"Bob Smith", 102},
        {"Carol Brown", 103},
        {"David Wilson", 104},
        {"Eve Davis", 105}
    };
    
    printf("=== CUSTOMER SERVICE QUEUE SIMULATION ===\n\n");
    
    // Add customers to queue
    printf("Adding customers to queue:\n");
    for(int i = 0; i < 5; i++) {
        if(!isFull(customerQueue)) {
            enqueue(&customerQueue, customers[i]);
            printf("Added: %s (Ticket #%d)\n", customers[i].name, customers[i].ticketNumber);
        }
    }
    
    printf("\nCurrent queue:\n");
    displayQueue(customerQueue);
    
    // Serve 2 customers
    printf("\nServing customers:\n");
    for(int i = 0; i < 2; i++) {
        if(!isEmpty(customerQueue)) {
            Customer served = dequeue(&customerQueue);
            printf("Now serving: %s (Ticket #%d)\n", served.name, served.ticketNumber);
        }
    }
    
    printf("\nQueue after serving 2 customers:\n");
    displayQueue(customerQueue);
    
    // Check who's next without removing them
    if(!isEmpty(customerQueue)) {
        Customer next = front(customerQueue);
        printf("\nNext customer to be served: %s (Ticket #%d)\n", next.name, next.ticketNumber);
    }
    
    printf("\nFinal queue status:\n");
    displayQueue(customerQueue);
    
    return 0;
}


void initQueue(Queue* Q){
  Q->front = Q->rear = -1;
  Q->count = 0;
}

bool isEmpty(Queue Q){
  return Q.front == -1;
}

bool isFull(Queue Q){
  return (Q.rear + 1) % MAX == Q.front;
}

void enqueue(Queue* Q, Customer c){
  if(isFull(*Q)){
    printf("Queue is full\n");
    return;
  }else{
    if(isEmpty(*Q)){
      Q->front = Q->rear = 0;
    }else{
      Q->rear = (Q->rear + 1) % MAX;
    }

    Q->customers[Q->rear] = c;
    Q->count ++;
  }
}
Customer dequeue(Queue* Q){
  Customer copy = Q->customers[Q->front];
  if(Q->front == Q->rear){
    Q->front = Q->rear = -1;
  }else{
    Q->front = (Q->front + 1)% MAX;
  }
  Q->count--;
  return copy;
}
Customer front(Queue Q){
  return Q.customers[Q.front];
}
void displayQueue(Queue Q){
  for(int i= Q.front, j = 0; j < Q.count; i = (i+1)% MAX, j++){
    printf("Queue %d: %s (#%d) \n", j+1, Q.customers[i].name,Q.customers[i].ticketNumber);
  }



}







