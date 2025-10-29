//bati ni sya nga version 

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define HALF (MAX / 2)
#define EMPTY -1
#define DELETED -2

typedef struct {
    char data;  // or int if your keys are numbers
    int link;
} Node;

typedef Node Dictionary[MAX];
int last = HALF -1; // tracks the last used index in synonym area

// ================== FUNCTION PROTOTYPES ==================
void initDictionary(Dictionary D);
int hash(char key);
void insert(Dictionary D, char key);
int search(Dictionary D, char key);
void deleteElem(Dictionary D, char key);
void displayDictionary(Dictionary D);
int getSynonymSlot(void);
int isFull(void);

// ================== MAIN ==================
int main() {
    Dictionary D;
    initDictionary(D);

    // sample calls (uncomment for testing)
    // insert(D, 'a');
    // insert(D, 'b');
    // deleteElem(D, 'a');
    // displayDictionary(D);

    return 0;
}


// Initialize dictionary
void initDictionary(Dictionary D) {
    for(int i = 0; i < MAX; i++){
      D[i].data = EMPTY;
      D[i].link = -1;
    }

    last = HALF -1;
}

// Hash function
int hash(char key) {
    return key % HALF;
}

// Insert key
void insert(Dictionary D, char key) {
    // TODO:
    // - compute hash
    // - if main slot empty, insert there
    // - else find synonym slot via getSynonymSlot()
    // - link it to chain
    if(search(D,key) == 1){
      return;
    }

    int indx = hash(key);
    if(D[indx].data == EMPTY || D[indx].data == DELETED){
      D[indx].data = key;
      return;
    }
    last++;
    if(last >= MAX){
      printf("Dictionary is full\n");
      return;
    }

    D[last].data = key;
    D[last].link = D[indx].link;
    D[indx].link = last;

}

// Search key
int search(Dictionary D, char key) {
    // TODO:
    // - follow links from main slot until found or -1

    int indx = hash(key);
    int i;
    for(i = indx; i != -1 && D[i].data != key; i = D[i].link){}
    return i != -1;
}

// Delete key
void deleteElem(Dictionary D, char key) {
    // TODO:
    // - find key
    // - mark as DELETED
    // - fix links if needed

  if(search(D,key) == 0){
      printf("Not found \n");
      return;
  }
  int indx = hash(key);
  if(D[indx].data == key){
    D[indx].data = DELETED;
    return;
  }

  int i;
  int prev = -1;
  for(i = indx; i != -1 &&D[indx].data != key;){
    prev = i;
    i = D[i].link;
  }

  if(i != -1){
    D[prev].link = D[i].link;
  }

  D[i].link = -1;

}

// Display dictionary
void displayDictionary(Dictionary D) {
    // TODO: print index, data, and link for all slots
    //       also print current value of last
}

// Get next synonym slot
int getSynonymSlot(void) {
    // TODO: return current last, then increment last
    //       handle overflow
}

// Check if dictionary full
int isFull(void) {
    // TODO: return 1 if last >= MAX else 0
}
