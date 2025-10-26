#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"


// write your functions here...
Set* createSet() {
    Set *set;
    set->head = NULL;
    set->size = 0;
    return set;
}


// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell){
    if(containsSpell(set, spell)){
        return 0;
    }

    //insert first

    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL){ return 0; }
    newnode->spell = spell;
    newnode->next = set->head;
    set->head = newnode;
    set->size++;
    return 1;
}


// Remove a spell from the set
bool removeSpell(Set** set, String spell){
    
}


// Check if a spell exists in the set
bool containsSpell(Set* set, String spell){
    Node **trav;
    for(trav = &set->head; *trav != NULL &&  strcmp((*trav)->spell, spell) != 0; trav = &(*trav)->next){}
    if(*trav != NULL){
        return 1;
    }

    return 0;
}


// Print all spells in the set
void printSet(Set* set);


// Free all memory associated with the set
void destroySet(Set* set);


Set* unionSets(Set* set1, Set* set2);
Set* intersectSets(Set* set1, Set* set2);
