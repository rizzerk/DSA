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

    /* TEST 1: Basic inserts (no collisions)
       H(a)=0, H(b)=1, H(c)=2, H(d)=3 */
    printf("==== TEST 1: Basic Insert ====\n");
    insert(D, 'a'); // 0
    insert(D, 'b'); // 1
    insert(D, 'c'); // 2
    insert(D, 'd'); // 3
    displayDictionary(D);

    /* TEST 2: Create collisions intentionally
       H(k)=0 -> collides with 'a'
       H(u)=0 -> collides with 'a'/'k'
       H(l)=1 -> collides with 'b'
       H(v)=1 -> collides with 'b'/'l'
       H(m)=2 -> collides with 'c'
       H(w)=2 -> collides with 'c'/'m' */
    printf("\n==== TEST 2: Collision-heavy Inserts ====\n");
    insert(D, 'k'); // hash 0 (synonym for a)
    insert(D, 'u'); // hash 0 (synonym for a)
    insert(D, 'l'); // hash 1 (synonym for b)
    insert(D, 'v'); // hash 1 (synonym for b)
    insert(D, 'm'); // hash 2 (synonym for c)
    insert(D, 'w'); // hash 2 (synonym for c)
    displayDictionary(D);

    /* TEST 3: Duplicates (ignored)
       Insert 'a' and 'k' again — should be ignored */
    printf("\n==== TEST 3: Duplicates (Should be Ignored) ====\n");
    insert(D, 'a'); // duplicate
    insert(D, 'k'); // duplicate
    displayDictionary(D);

    /* TEST 4: Deletion tests
       delete main slot 'a' (hash 0)
       delete synonym 'k' (hash 0)
       delete non-existent 'z' */
    printf("\n==== TEST 4: Deletion Tests ====\n");
    deleteElem(D, 'a'); // mark main slot as DELETED
    deleteElem(D, 'k'); // remove synonym from chain
    deleteElem(D, 'z'); // not found
    displayDictionary(D);

    /* TEST 5: Reinsertion after deletions
       insert 'a' again (should occupy main slot at 0 if allowed)
       insert 'x' which hashes to 3 (collides with 'd') */
    printf("\n==== TEST 5: Reinsertion After Deletion ====\n");
    insert(D, 'a'); // reinsert main slot (hash 0)
    insert(D, 'x'); // hash 3 (collision with d)
    displayDictionary(D);

    /* TEST 6: Fill remaining synonym slots until full or near-full.
       These letters are chosen to produce various hashes.
       Stop once dictionary prints "Dictionary is full" if it occurs. */
    printf("\n==== TEST 6: Fill Until Full (or near-full) ====\n");
    insert(D, 'n'); // hash 3 -> will chain with d/x
    insert(D, 'o'); // hash 4
    insert(D, 'p'); // hash 5
    insert(D, 'q'); // hash 6
    insert(D, 'r'); // hash 7
    insert(D, 's'); // hash 8
    insert(D, 't'); // hash 9
    insert(D, 'y'); // hash 4 (collision with o)
    insert(D, 'z'); // hash 5 (collision with p)
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
    return (key - 'a') % HALF;   
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
  for(i = indx; i != -1 && D[i].data != key; i = D[i].link){
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
