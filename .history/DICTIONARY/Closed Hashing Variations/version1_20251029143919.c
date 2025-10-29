#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define HALF (MAX / 2)
#define EMPTY -1
#define DELETED -2

typedef int ElemType;

typedef struct {
    ElemType key;
} Node;

typedef Node HashTable[MAX];

// Global variable for tracking synonym insertions
int last = HALF;  // next available slot in synonym area

// ================== FUNCTION PROTOTYPES ==================

// Basic operations
void initDictionary(HashTable D);
int hash(ElemType key);
void insert(HashTable D, ElemType key);
void deleteElem(HashTable D, ElemType key);
int isMember(HashTable D, ElemType key);
void displayDictionary(HashTable D);
ElemType retrieve(HashTable D, int index);
void makeEmpty(HashTable D);

// Helper functions
int getSynonymSlot(void);
int isFull(void);

// ================== MAIN (FOR TESTING) ==================
int main() {
    HashTable D;
    initDictionary(D);

    // sample calls
    // insert(D, 15);
    // insert(D, 25);
    // deleteElem(D, 15);
    // displayDictionary(D);

    return 0;
}

// ================== FUNCTION DEFINITIONS ==================

// Initialize all slots to EMPTY
void initDictionary(HashTable D) {
    // TODO: set all D[i].key = EMPTY
    //       reset last = HALF

    for(int i=0; i < MAX; i ++){
      D[i].key = EMPTY;
    }

    last = HALF;
}

// Hash function for main area
int hash(ElemType key) {
    // TODO: return key % HALF;
    return key % 10;
}

// Insert element into dictionary
void insert(HashTable D, ElemType key) {
    // TODO:
    // 1. Compute home index = hash(key)
    // 2. If EMPTY, insert directly
    // 3. Else insert in synonym area using getSynonymSlot()
    // 4. Update last

    int indx = hash(key);
    if(D[indx].key == EMPTY || D[indx].key == DELETED){
      D[indx].key = key;
    }else{
      if(last < MAX){
        D[last].key = key;
        last++;  
      }else{
        printf("Dictionary is full\n");
        return;
      }
    }

}

// Delete element from dictionary
void deleteElem(HashTable D, ElemType key) {
    // TODO:
    // 1. Search for key
    // 2. If found, mark as DELETED
}

// Check if element exists in dictionary
int isMember(HashTable D, ElemType key) {
    // TODO:
    // 1. Compute home index
    // 2. Check in main area
    // 3. If not found, check synonym area
    // 4. Return TRUE/FALSE
}

// Display the table
void displayDictionary(HashTable D) {
    // TODO: print all indices, keys, and status (EMPTY, DELETED, or value)
}

// Retrieve element by index (optional)
ElemType retrieve(HashTable D, int index) {
    // TODO: return D[index].key
}

// Clear all entries
void makeEmpty(HashTable D) {
    // TODO: set all keys to EMPTY again
    //       reset last = HALF
}

// Allocate slot in synonym area
int getSynonymSlot(void) {
    // TODO:
    // 1. Check if last < MAX
    // 2. Return current last
    // 3. Increment last
    // 4. If full, handle overflow



}

// Check if dictionary is full
int isFull(void) {
    // TODO: return (last >= MAX);
}
