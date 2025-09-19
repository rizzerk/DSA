#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue structure
typedef struct {
    int elems[MAX];
    int front; // index of first element
    int rear;  // index of last element 
} Queue;

// Function prototypes
void initQueue(Queue *Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
void enqueue(Queue *Q, int elem);
int dequeue(Queue *Q);
int frontElem(Queue Q);
int rearElem(Queue Q);
int size(Queue Q);
void display(Queue Q);

// Main function for testing
int main() {
    Queue Q;
    initQueue(&Q);

    // Example usage:
    // enqueue(&Q, 10);
    // enqueue(&Q, 20);
    // display(Q);
    // printf("Dequeued: %d\n", dequeue(&Q));
    // display(Q);

    return 0;
}

// Function definitions (YOU will write inside)
void initQueue(Queue *Q) {
    Q->front = Q->rear = -1;
}

int isEmpty(Queue Q) {
    return (Q.rear+ 1) % MAX == Q.front;
}

int isFull(Queue Q) {
    return (Q.rear + 2) % MAX == Q.front;
}

void enqueue(Queue *Q, int elem) {
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->elems[Q->rear] = elem;
    }
}

int dequeue(Queue *Q) {
    if(!isEmpty){
        int n = Q->elems[Q->front];
        Q->front = (Q->front+1) % MAX;
        return n;
    }
    return -1; // placeholder
}

int frontElem(Queue Q) {
    return Q.elems[Q.front];
}

int rearElem(Queue Q) {
    return Q.elems[Q.rear];
}

int size(Queue Q) {
    
}

void display(Queue Q) {
    // your code here
}
