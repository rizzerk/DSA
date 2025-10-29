
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define HALF (MAX / 2)
#define EMPTY -1
#define DELETED -2

typedef struct {
    char data;  // or int
    int link;   // next index
} Node;

typedef Node Dictionary[MAX];
int Avail = HALF;  // first available synonym index

// ================== FUNCTION PROTOTYPES ==================
void initDictionary(Dictionary D);
int hash(char key);
void insert(Dictionary D, char key);
int search(Dictionary D, char key);
void deleteElem(Dictionary D, char key);
void displayDictionary(Dictionary D);

// Helper functions
int allocNode(Dictionary D);
void freeNode(Dictionary D, int index);
void displayAvail(Dictionary D);

// ================== MAIN ==================
int main() {
    Dictionary D;
    initDictionary(D);

    // sample practice
    // insert(D, 'a');
    // insert(D, 'b');
    // insert(D, 'c');
    // deleteElem(D, 'a');
    // displayDictionary(D);

    return 0;
}

// ================== DEFINITIONS ==================

// Initialize dictionary and synonym links
void initDictionary(Dictionary D) {
    // TODO:
    // - Set all main area data to EMPTY, link = -1
    // - Initialize synonym area links as linked free list
    //   e.g. D[i].link = i+1
    // - Set last synonym link to -1
    // - Set Avail = HALF
}

// Hash function
int hash(char key) {
    // TODO: return key % HALF;
}

// Insert new key
void insert(Dictionary D, char key) {
    // TODO:
    // - Compute home = hash(key)
    // - If main slot empty, insert directly (link = -1)
    // - Else allocate from Avail using allocNode()
    // - newNode.link = main.link
    // - main.link = newNode
}

// Search for key
int search(Dictionary D, char key) {
    // TODO:
    // - Compute home = hash(key)
    // - Traverse main + synonyms using link until found or -1
}

// Delete key
void deleteElem(Dictionary D, char key) {
    // TODO:
    // - Find node (track prev and curr)
    // - Adjust links to skip deleted node
    // - Call freeNode(D, deletedIndex)
    // - For practice, set data = 'DEL' or DELETED marker
}

// Display dictionary contents
void displayDictionary(Dictionary D) {
    // TODO:
    // - Print index, data, link
    // - Show Avail value
}

// Allocate node from synonym area
int allocNode(Dictionary D) {
    // TODO:
    // - Return current Avail
    // - Update Avail = D[Avail].link
}

// Return node to free list
void freeNode(Dictionary D, int index) {
    // TODO:
    // - D[index].link = Avail
    // - Avail = index
}

// Display available list (optional for tracing)
void displayAvail(Dictionary D) {
    // TODO:
    // - Print Avail chain (useful for visualizing free list)
}
