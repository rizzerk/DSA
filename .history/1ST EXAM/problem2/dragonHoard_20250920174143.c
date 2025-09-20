#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include <stdbool.h>

#define MAX 10

// Treasure structure
typedef struct {
    char itemName;    // Single-letter treasure identifier
    float weight;     // Mystical weight units
} Item;

// Mystical storage node
typedef struct {
    Item item;        // The stored treasure
    int next;         // Link to next treasure in chain
} Node;

// The mystical realm storage
typedef struct {
    Node nodes[MAX];  // 10 mystical storage compartments
    int avail;        // Portal to available slots
} VSpace;

// Kira's Mystic Satchel
typedef struct {
    int top;              // Index of topmost treasure
    float currentWeight;  // Current mystical burden
    float maxWeight;      // Weight Ward limit
    VSpace *vs;          // Pointer to mystical storage realm
} Stack;

// Function prototypes
void initVSpace(VSpace *vs);
void initStack(Stack *s, VSpace *vs, float maxWeight);
int allocNode(VSpace *vs);
void deallocNode(VSpace *vs, int index);
void pickupTreasure(Stack *s, Item i);
void retrieveTreasure(Stack *s);
void peekTreasure(Stack s);
void displaySatchel(Stack s);
bool isEmpty(Stack s);
void emptySatchel(Stack *s);
void visualizeStorage(VSpace vs);
void showAdventureMenu();
void runCaveScenario(int scenario, Stack *satchel, VSpace *storage);
void runGuildScenario(int scenario, Stack *satchel, VSpace *storage);
void runAllScenarios();
void runInteractiveMode();

#endif