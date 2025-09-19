#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue structure
typedef struct {
    int elems[MAX];
    int front; // index of first element
    int rear;  // index of last element
    int count; // number of elements in the queue
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
    Q->count = 0;
    Q->front = Q->rear = -1;
}

int isEmpty(Queue Q) {
    // your code here
    return Q.count == 0;
}

int isFull(Queue Q) {
    // your code here
    return Q.count == MAX;
}

void enqueue(Queue *Q, int elem) {
    // your code here
    if(!isFull(*Q)){
        if(isEmpty(*Q)){
            Q->front = Q->rear = 0;
        }else{
            Q->rear = (Q->rear + 1) % MAX;
        }

        Q->elems[Q->rear] = elem;
        Q->count++;
    }
}

int dequeue(Queue *Q) {
    // your code here
    if(!isEmpty(*Q)){
        int val= Q->elems[Q->front];
        Q->front = (Q->front + 1)% MAX;
        Q->count--;
        if(Q->count == 0){
            Q->front = Q->rear = -1; //reset
        }
        return val;
    }
    return -1; // placeholder
}

int frontElem(Queue Q) {
    return (!isEmpty(Q)) ? Q.elems[Q.front] : -1; // placeholder
}

int rearElem(Queue Q) {
    return (!isEmpty(Q)) ? Q.elems[Q.rear] : -1;
}

int size(Queue Q) {
    // your code here
    return Q.count;
}

void display(Queue Q) {
    for(int i= Q.front; i != Q.rear; i = (i+1) % MAX){
        printf("%d ", Q.elems[i]);
    }
    printf("%d \n", Q.elems[Q.rear]);
}
