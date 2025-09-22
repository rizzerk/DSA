#include <stdio.h>
#include <stdbool.h>
#include "dragonHoard.h"


// TREASURE RETRIEVAL ENCHANTMENT (Pop Function)
void retrieveTreasure(Stack *s) {
    // [Task 1] To do code logic...
    //if(!isEmpty(*s))
    if(s->top != -1)
    
    {
        int temp = s->top;
        float n = s->vs->nodes[temp].item.weight;
        s->vs->nodes[s->top].next = s->vs->nodes[temp].next;
        
        s->currentWeight -= n;
        s->top = s->vs->nodes[temp].next;
        printf("Retrieved '%c': SUCCESS (Remaining: %.1f)\n", 
                            s->vs->nodes[temp].item.itemName, 
                            s->currentWeight
                            );
        
        
        s->vs->nodes[temp].next = s->vs->avail;
        s->vs->avail = temp;
        
    }else{
        printf("Retrieval FAILED - Satchel is empty!\n");
    }


}


// Main adventure function
int main() {
    printf("The Dragon's Hoard Adventure\n");
    printf("Testing treasure pickup and retrieval\n\n");

    // Show menu and get single choice
    int choice;
    Stack kiraSatchel;
    VSpace mysticalStorage;

    // Initialize
    initVSpace(&mysticalStorage);
    initStack(&kiraSatchel, &mysticalStorage, 25.0);

    showAdventureMenu();
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            runCaveScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 7:
        case 8:
        case 9:
        case 10:
            runGuildScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 11:
            runAllScenarios();
            break;

        case 12:
            runInteractiveMode();
            break;

        case 0:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}