#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMTABLES 10

typedef enum {VIP, Regular} category;

typedef struct {
    char name[30];
    category guestType;
    int tableNumber; // Tables from 0 - 9
}guest;

typedef struct tableNode{
    guest G;
    struct tableNode* nextTable;
}tableNode, *tableList;

typedef struct{
    tableList front;
    tableList end;
}table;

void initTable(table* T);
void initAllTables(table T[]);
void displayTableList(tableList TL, int tableNum);
void categorizeGuests(guest G[], int numGuests, table T[]);
void removeGuests(guest G[], int numGuests, table T[]);

int main(void) {
    table tables[NUMTABLES];
    guest guestList[20] = {
        {"Alice Tan",        VIP,     3},
        {"Brian Cruz",       Regular, 1},
        {"Catherine Lee",    VIP,     2},
        {"David Santos",     Regular, 4},
        {"Ella Martinez",    VIP,     1},
        {"Frank Lim",        Regular, 3},
        {"Grace Yu",         VIP,     2},
        {"Henry Dela Cruz",  Regular, 4},
        {"Isabelle Ong",     VIP,     3},
        {"Jack Rivera",      Regular, 2},
        {"Karen Sy",         VIP,     1},
        {"Leo Mendoza",      Regular, 4},
        {"Mika Tanaka",      VIP,     3},
        {"Nathan Cruz",      Regular, 2},
        {"Olivia Perez",     VIP,     1},
        {"Paul Santos",      Regular, 4},
        {"Queenie Lo",       VIP,     5},
        {"Ryan Torres",      Regular, 6},
        {"Sophia Wang",      VIP,     8},
        {"Tommy Villanueva", Regular, 0}
    };
    guest guestListRemove[4] = {
        {"Frank Lim",      Regular, 3},
        {"Paul Santos",    Regular, 4},
        {"Catherine Lee",    VIP, 2}, 
        {"Tommy Villanueva", Regular, 0}
    };
    int i;
    
    initAllTables(tables);
    categorizeGuests(guestList, 20, tables);
    printf("INITIAL TABLE LIST\n");
    for(i = 0; i < NUMTABLES; i++){
        displayTableList(tables[i].front, i);
    }
    
    removeGuests(guestListRemove, 4, tables);
    printf("AFTER REMOVE\n");
    for(i = 0; i < NUMTABLES; i++){
        displayTableList(tables[i].front, i);
    }
    
    return 0;
}

void initTable(table* T)
{
    T->front = T->end = NULL;
}

void initAllTables(table T[])
{
    int i;
    for(i = 0; i < NUMTABLES; i++){
        initTable(&T[i]);
    }
}

void displayTableList(tableList TL, int tableNum)
{
    printf("Table Number [%d]: ", tableNum);
    for(;TL != NULL; TL = TL->nextTable){
        printf("%s | ", TL->G.name);
    }
    printf("\n");
}
/*
    Write the function:
        void categorizeGuests(guest G[], int numGuests, table T[]);
    This function processes all guests in the array G[] and places each guest
    into the correct table inside array T.
    - Use the guest's tableNumber to locate the correct table in T[].
    - VIP guests must be inserted at the FRONT of their table's list.
    - Regular guests must be inserted at the END of their table's list.

    The function does not return a value. It updates the table lists directly.
*/
void categorizeGuests(guest G[], int numGuests, table T[])
{
  for(int i =0 ; i < numGuests; i++){
    int tn = G[i].tableNumber;

    tableList guest = (tableList)malloc(sizeof(tableNode));
    guest->G = G[i];
    guest->nextTable = NULL;

    if(T[tn].front == NULL){
        T[tn].front = guest;
        T[tn].end = guest;
    }else{
      if(G[i].guestType == 0)
      {
        guest->nextTable = T[tn].front;
        T[tn].front = guest;
      } 
      else if (G[i].guestType == 1)
      {
        T[tn].end->nextTable = guest;
        T[tn].end = guest;
      }
    }
    
  }

}

/*
    Write the function:
        void removeGuests(guest G[], int numGuests, table T[]);
    This function goes through each guest in the array G and removes that guest
    from their assigned table list in T.
    - Use the guest's tableNumber to locate the correct table.
    - Search the table's linked list for a node with the same guest name.
    - If found, unlink the node from the list and free its memory.
    - If the removed node was the last node in the list, update the table's
      end pointer so it points to the new last node (or set it to NULL if the
      table becomes empty).

    The function does not return a value. It directly updates the table lists.
*/
void removeGuests(guest G[], int numGuests, table T[])
{
  for(int i = 0; i < numGuests; i++){
    int tn = G[i].tableNumber;

    tableList *trav, temp;
    
    for(trav = &T[tn].front; *trav != NULL && strcmp(G[i].name, (*trav)->G.name) != 0; trav = &(*trav)->nextTable){}
      if(*trav != NULL){
        temp = *trav;
        *trav= temp->nextTable;
        if(temp == T[tn].end){
          T[tn].end = (trav == &T[tn].front) ? T[tn].front : NULL;
        }

        if(T->front == NULL){
          T[tn].end == NULL;
        }

      }

    }

  


}