#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Node definition for cursor-based queue
typedef struct {
    int data;
    int next;   // index of next node (-1 if none)
} Node;

// Virtual heap (manages memory)
typedef struct {
    Node elems[MAX];
    int avail;  // index of first available node
} VHeap;

// Cursor-based queue
typedef struct {
    int front;  // index of first node
    int rear;   // index of last node
} Queue;

// Function prototypes
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int pos);

void initQueue(Queue *Q);
int isEmpty(Queue Q);
int isFull(VHeap VH);
void enqueue(Queue *Q, VHeap *VH, int elem);
int dequeue(Queue *Q, VHeap *VH);
int frontElem(Queue Q, VHeap VH);
int rearElem(Queue Q, VHeap VH);
void display(Queue Q, VHeap VH);

// Main function for testing
int main() {
    VHeap VH;
    Queue Q;

    initVHeap(&VH);
    initQueue(&Q);

    // Example usage:
    // enqueue(&Q, &VH, 10);
    // enqueue(&Q, &VH, 20);
    // display(Q, VH);
    // printf("Dequeued: %d\n", dequeue(&Q, &VH));
    // display(Q, VH);

    return 0;
}

// ---------------------
// Function Definitions
// ---------------------

void initVHeap(VHeap *VH) {
    // Initialize avail list (free nodes chain)
    VH->avail = 0;
    int i;
    for(i=0; i < MAX - 1; i ++){
        VH->elems[i].next = i + 1;
    }

    VH->elems[i].next = -1;
}

int allocSpace(VHeap *VH) {
   int indx =  VH->avail;
   if(indx != -1){
    VH->avail = VH->elems[indx].next;
   }

   
    return indx; // placeholder
}

void deallocSpace(VHeap *VH, int pos) {
    VH->elems[pos].next = VH->avail;
    VH->avail = pos;
}

void initQueue(Queue *Q) {
    // Initialize empty queue
    Q->front = Q->rear = -1;
}

int isEmpty(Queue Q) {
    return Q.front == -1;
}

int isFull(VHeap VH) {
    return VH.avail == -1;
}

void enqueue(Queue *Q, VHeap *VH, int elem) {
    // your code here
   int temp = allocSpace(VH);
   if(temp != -1){
        VH->elems[temp].data = elem;
        VH->elems[temp].next = -1;
        if(isEmpty(*Q)){
            Q->front = temp;
        }else{
            VH->elems[Q->rear].next = temp; 
        }

        Q->rear = temp;
   }
    
}

int dequeue(Queue *Q, VHeap *VH) {
    if(!isEmpty(*Q)){
        int temp = Q->front;
        int n = VH->elems[temp].data;
        if(Q->front == Q->rear){
            Q->rear = Q->front = -1;
        }else{
            Q->front = VH->elems[temp].next;
        }
        VH->elems[temp].next = VH->avail;
        VH->avail = temp;
        return n;
    }
    return -1;
}

int frontElem(Queue Q, VHeap VH) {
    return VH.elems[Q.front].data;
}

int rearElem(Queue Q, VHeap VH) {
    // your code here
    return VH.elems[Q.rear].data;
}

void display(Queue Q, VHeap VH) {
    // Traverse and display elements
}
