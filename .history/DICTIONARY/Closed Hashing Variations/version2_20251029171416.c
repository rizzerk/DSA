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
  //tests by bff gpt
   Dictionary D;
    initDictionary(D);

    printf("==== TEST 1: Basic Insert ====\n");
    insert(D, 'a'); // H(a)=3
    insert(D, 'b'); // H(b)=9
    insert(D, 'c'); // H(c)=4
    insert(D, 'd'); // H(d)=4 (collision)
    displayDictionary(D);

    printf("\n==== TEST 2: More Insertions (Trigger Multiple Collisions) ====\n");
    insert(D, 'e'); // H(e)=9 (collision with b)
    insert(D, 'f'); // H(f)=0
    insert(D, 'g'); // H(g)=3 (collision with a)
    insert(D, 'h'); // H(h)=4 (collision with c)
    insert(D, 'i'); // H(i)=5
    insert(D, 'j'); // H(j)=6
    displayDictionary(D);

    printf("\n==== TEST 3: Duplicates (Should be Ignored) ====\n");
    insert(D, 'a'); // duplicate
    insert(D, 'b'); // duplicate
    displayDictionary(D);

    printf("\n==== TEST 4: Deletion Tests ====\n");
    deleteElem(D, 'a'); // delete main slot
    deleteElem(D, 'g'); // delete synonym
    deleteElem(D, 'x'); // non-existent
    displayDictionary(D);

    printf("\n==== TEST 5: Reinsertion After Deletion ====\n");
    insert(D, 'x'); // should reuse deleted main slot (hash(x)=?)
    insert(D, 'k'); // random new insertion
    displayDictionary(D);

    printf("\n==== TEST 6: Fill Until Full ====\n");
    insert(D, 'l');
    insert(D, 'm');
    insert(D, 'n');
    insert(D, 'o');
    insert(D, 'p');
    insert(D, 'q');
    insert(D, 'r');
    insert(D, 's');
    insert(D, 't');
    insert(D, 'u'); // may trigger full
    displayDictionary(D);

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


  int indx = hash(key);
  int i;
  int prev = -1;
  for(i = indx; i != -1 && D[indx].data != key; i = D[i].link){
    prev = i;
  }

  if (i == -1) {
        printf("%c not found\n", key);
        return;
    }

    // If it's the main slot
  if (prev == -1) {
        D[i].data = DELETED;
        return;
    }

 

    D[prev].link = D[i].link;
    D[i].data = DELETED;
    D[i].link = -1;

}

//below by bff gpt

// Display dictionary
void displayDictionary(Dictionary D) {
     printf("\nIndex\tData\tLink\n");
    printf("====================\n");
    for (int i = 0; i < MAX; i++) {
        if (D[i].data == EMPTY)
            printf("%2d\tEMPTY\t%d\n", i, D[i].link);
        else if (D[i].data == DELETED)
            printf("%2d\tDEL\t%d\n", i, D[i].link);
        else
            printf("%2d\t%c\t%d\n", i, D[i].data, D[i].link);
    }
    printf("last = %d\n", last);
    printf("====================\n");
}

// Get next synonym slot
int getSynonymSlot(void) {
   if (isFull()) {
        printf("No more synonym slots available\n");
        return -1;
    }
    last++;
    return last;
}

// Check if dictionary full
int isFull(void) {
   return last >= MAX - 1;
}
