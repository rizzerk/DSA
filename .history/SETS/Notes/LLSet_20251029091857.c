#include <stdio.h>
#include <stdlib.h>

// --- Structure definition ---
typedef struct Node {
    int data;
    struct Node *next;
} *Node;

// --- Function Prototypes ---
Node createNode(int data);
void insert(Node *head, int data);
void display(Node head);

Node setUnion(Node A, Node B);
Node setIntersection(Node A, Node B);
Node setDifference(Node A, Node B);

// --- Main Function ---
int main() {
    Node A = NULL, B = NULL;
    Node U = NULL, I = NULL, D = NULL;

    // Add elements to Set A
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);

    // Add elements to Set B
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 5);

    printf("Set A: ");
    display(A);
    printf("Set B: ");
    display(B);

    // Perform set operations
    U = setUnion(A, B);
    I = setIntersection(A, B);
    D = setDifference(A, B);

    printf("\nUnion: ");
    display(U);
    printf("Intersection: ");
    display(I);
    printf("Difference (A - B): ");
    display(D);

    return 0;
}

// --- Function Definitions ---

Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node *head, int data) {
    // TODO: Insert a unique element into the list
    Node temp;
    for(temp = *head; temp != NULL; temp = temp->next)
    if (temp->data == data) return;

    Node newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void display(Node head) {
    // TODO: Display all elements in set format

}

Node setUnion(Node A, Node B) {
    // TODO: Combine all unique elements from A and B
    Node result = NULL;
    for(Node temp = A; temp != NULL; temp = temp->next)
    insert(&result, temp->data);
    for (Node temp = B;  temp != NULL; temp = temp->next)
    insert(&result, temp->data);

    return result;
}

Node setIntersection(Node A, Node B) {
    // TODO: Elements common to both A and B
    Node result = NULL;
    for(Node tempA = A; tempA != NULL; tempA = tempA->next)
      for(Node tempB = B; tempB!= NULL; tempB = tempB->next)
        if(tempA->data == tempB->data)
          insert(&result, tempA->data);
      
    return result;
    
}



Node setDifference(Node A, Node B) {
    // TODO: Elements in A but not in B
  Node a, b;
  Node res = NULL;
  for(a = A; a != NULL; a = a->next){
    for(b= B; b != NULL && b->data != a->data; b = b->next){}
    if(b == NULL){
      insert(&res, a->data);
    }
  }

  return res;
}
