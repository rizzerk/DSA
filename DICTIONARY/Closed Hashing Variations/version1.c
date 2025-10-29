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

    printf("===== INITIAL STATE =====\n");
    displayDictionary(D);

    printf("===== INSERTING MAIN AREA ELEMENTS =====\n");
    insert(D, 10);  // goes to main area (10 % 10 = 0)
    insert(D, 11);  // main area (1)
    insert(D, 12);  // main area (2)
    insert(D, 13);  // main area (3)
    insert(D, 14);  // main area (4)
    insert(D, 15);  // main area (5)
    insert(D, 16);  // main area (6)
    insert(D, 17);  // main area (7)
    insert(D, 18);  // main area (8)
    insert(D, 19);  // main area (9)
    displayDictionary(D);

    printf("===== INSERTING SYNONYM AREA ELEMENTS (COLLISIONS) =====\n");
    // All of these collide with existing home addresses
    insert(D, 20); // same home as 10 (0)
    insert(D, 30); // same home as 10 (0)
    insert(D, 40); // same home as 10 (0)
    insert(D, 21); // same home as 11 (1)
    displayDictionary(D);

    printf("===== DUPLICATE INSERT TEST =====\n");
    insert(D, 10);  // duplicate, should be ignored
    insert(D, 30);  // duplicate, should be ignored
    displayDictionary(D);

    printf("===== MEMBERSHIP CHECKS =====\n");
    printf("Is 15 in dictionary? %s\n", isMember(D, 15) ? "YES" : "NO");
    printf("Is 50 in dictionary? %s\n", isMember(D, 50) ? "YES" : "NO");

    printf("===== DELETION TESTS =====\n");
    printf("-- Deleting 15 (main area)\n");
    deleteElem(D, 15);
    printf("-- Deleting 30 (synonym area)\n");
    deleteElem(D, 30);
    displayDictionary(D);

    printf("===== RETRIEVE TEST =====\n");
    for (int i = 0; i < 5; i++) {
        printf("Index %d → Key = %d\n", i, retrieve(D, i));
    }

    printf("===== FULL SYNONYM AREA TEST =====\n");
    // Fill up remaining synonym slots until full
    while (!isFull()) {
        insert(D, last + 100);
    }
    displayDictionary(D);

    printf("===== MAKE EMPTY TEST =====\n");
    makeEmpty(D);
    displayDictionary(D);

    printf("All tests completed successfully!\n");

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
    return key % HALF;
}

// Insert element into dictionary
void insert(HashTable D, ElemType key) {
    // TODO:
    // 1. Compute home index = hash(key)
    // 2. If EMPTY, insert directly
    // 3. Else insert in synonym area using getSynonymSlot()
    // 4. Update last

    //no helper function
    int indx = hash(key);
    if(D[indx].key == key){
      return;
    }

    if(D[indx].key == EMPTY || D[indx].key == DELETED){
      D[indx].key = key;
    }
    
    else{
      int i;
      for(i = HALF; i < last && D[i].key != key; i++){}
      if(i < last){
        //already exist;
        return;
      }else if(i < MAX){
        //i is last 
        D[i].key = key;
        last++;
      }else{
        //dict is full
        printf("Dictionary is Full! Can't insert %d \n", key);
        return;
      }

    }

}

// Delete element from dictionary
void deleteElem(HashTable D, ElemType key) {
    // TODO:
    // 1. Search for key
    // 2. If found, mark as DELETED
    
    //no helper function
    int indx = hash(key);
    if(D[indx].key == key){
      D[indx].key = DELETED;
      return;
    }

    int i;
    for(i = HALF; i < last && D[i].key != key; i++){}
    if(i < last){
      D[i].key = D[--last].key;
    }
}

// Check if element exists in dictionary
int isMember(HashTable D, ElemType key) {
    // TODO:
    // 1. Compute home index
    // 2. Check in main area
    // 3. If not found, check synonym area
    // 4. Return TRUE/FALSE

    int indx = hash(key);
    if(D[indx].key == key){
      return 1;
    }
    int i;
    for(i = HALF; i < last && D[i].key != key; i++){}
    return i < last ? 1 : 0;
}

// Display the table
void displayDictionary(HashTable D) {
    // TODO: print all indices, keys, and status (EMPTY, DELETED, or value)
    printf("\n==================== HASH TABLE ====================\n");
    printf("Index\tKey\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < MAX; i++) {
        if (D[i].key == EMPTY)
            printf("%d\tEMPTY\n", i);
        else if (D[i].key == DELETED)
            printf("%d\tDELETED\n", i);
        else
            printf("%d\t%d\n", i, D[i].key);
    }

    printf("----------------------------------------------------\n");
    printf("Next available synonym slot (last): %d\n", last);
    printf("====================================================\n\n");

}

// Retrieve element by index (optional)
ElemType retrieve(HashTable D, int index) {
    // TODO: return D[index].key
    if(index < 0 || index >= MAX){
      printf("Out of Bounds\n");
      return EMPTY;
    }

  return D[index].key;
}

// Clear all entries
void makeEmpty(HashTable D) {
    // TODO: set all keys to EMPTY again
    //       reset last = HALF
    for(int i=0;  i < MAX; i ++){
      D[i].key = EMPTY;
    }

    last = HALF;
}

// Allocate slot in synonym area
int getSynonymSlot(void) {
    // TODO:
    // 1. Check if last < MAX
    // 2. Return current last
    // 3. Increment last
    // 4. If full, handle overflow

    if(last < MAX){
      int n = last;
      last++;
      return n;
    }


      return last;
}

// Check if dictionary is full
int isFull(void) {
    return last >= MAX;
}
