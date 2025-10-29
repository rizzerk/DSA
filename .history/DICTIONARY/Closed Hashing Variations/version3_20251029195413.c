
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
int avail = HALF;  // first available synonym index

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
  avail = HALF;
  int i;
  for(i=0 ; i < HALF; i++){
    D[i].data = EMPTY;
    D[i].link = -1;
  }

  for(; i < MAX-1; i++){
    D[i].link = i+1;
  }

  //set last link to -1
  D[i].link = -1;

}

// Hash function
int hash(char key) {
    return (key - 'a') % HALF;   
}

// Insert new key
void insert(Dictionary D, char key) {
    // TODO:
    // - Compute home = hash(key)
    // - If main slot empty, insert directly (link = -1)
    // - Else allocate from Avail using allocNode()
    // - newNode.link = main.link
    // - main.link = newNode

    //without using helper function

    int h = hash(key);

    int i;
    for(i = h; i != -1; i = D[i].link){
      if(D[i].data == key) return;
    }

    if(D[h].data == EMPTY || D[h].data == DELETED){
      D[h].data = key;
      return;
    }

    int space = avail;
    if(space == -1){
      printf("Dict is full\n");
      return;
    }
    avail = D[space].link;
    

    D[space].link = D[h].link;
    D[space].data = key;
    D[h].link = space;
}

// Search for key
int search(Dictionary D, char key) {
    // TODO:
    // - Compute home = hash(key)
    // - Traverse main + synonyms using link until found or -1

    int h = hash(key);
    int i;
    for(i = h; i != -1; i = D[i].link){
      if(D[i].data == key) return i;
    }

    return -1;
}

// Delete key
void deleteElem(Dictionary D, char key) {
    // TODO:
    // - Find node (track prev and curr)
    // - Adjust links to skip deleted node
    // - Call freeNode(D, deletedIndex)
    // - For practice, set data = 'DEL' or DELETED marker

  //let's do it without helper functions
  int h = hash(key);

  if(D[h].data == key){
    D[h].data = DELETED;
    return;
  }
  //search
  int *trav;
  for(trav = &D[h].link; *trav != -1 && D[*trav].data != key; trav = &D[*trav].link){}
  if(*trav != -1){
    int temp = *trav;
    *trav = D[temp].link;
    D[temp].data = DELETED;

    //dealloc space
    D[temp].link = avail;
    avail = temp;
  }

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

    int space = avail;
    if(space != -1){
      avail = D[space].link;
    }



    return space;
}

// Return node to free list
void freeNode(Dictionary D, int index) {
    // TODO:
    // - D[index].link = Avail
    // - Avail = index
  D[index].link = avail;
  avail = index;

}

// Display available list (optional for tracing)
void displayAvail(Dictionary D) {
    // TODO:
    // - Print Avail chain (useful for visualizing free list)
}
