#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // You can adjust the size

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Function prototypes
//version 2 - naay space mahibilin before sa end
void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void display(Queue q);

int main() {
    Queue q;
    initQueue(&q);

    // Sample menu-driven program to test
    int choice, val;
    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if(val != -1) {
                    printf("Dequeued: %d\n", val);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

/* 
   Fill in the code inside each function
*/

void initQueue(Queue *q) {
    // TODO: Initialize front and rear
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    // TODO: Return true if queue is empty
    return q->front == -1;
}

int isFull(Queue *q) {
    // TODO: Return true if queue is full
    return (q->rear + 2) % MAX;
}

void enqueue(Queue *q, int data) {
    // TODO: Insert element into the queue
    if(!isFull(q)){
        if(isEmpty(q)){
            q->front = q->rear = 0; 
        }else{
            
        }
    }
}

int dequeue(Queue *q) {
    // TODO: Remove element from the queue and return it
    // Return -1 if queue is empty
}

void display(Queue q) {
    // TODO: Print all elements of the queue
}
