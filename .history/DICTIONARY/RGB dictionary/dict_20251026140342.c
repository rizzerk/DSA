#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


// Write your functions here...
int hashFunction(int rgb[3]){
    int r = rgb[0] * 3;
    int g = rgb[1] * 5;
    int b = rgb[2] * 7;
    int sum = r + g + b; 
    int hash= sum % PALETTE_SIZE;
    return hash;
}

void createDictionary(Dictionary *dict){
    for(int i=0; i < PALETTE_SIZE; i++){
        dict->buckets[i] = NULL;
    }
}

Node* createNode(Color newColor){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = newColor;
    newnode->next = NULL;

    return newnode;
}

void insertColor(Dictionary *dict, Color newColor){
    //insert at head;
    int indx = hashFunction(newColor.RGBVal);
    Node **trav;
    // for(trav = &dict->buckets[indx]; *trav != NULL && strcmp(newColor.colorName, (*trav)->data.colorName) != 0; trav = &(*trav)->next);
    // if(*trav != NULL){
    //     //color already exists;
    //     return;
    // }
//or

if (searchColor(dict, newColor.RGBVal) != NULL) {
    // Color with same RGB already exists
    return;
}

    Node *newnode = createNode(newColor);
    if(newnode != NULL){
        newnode->next = dict->buckets[indx];
        dict->buckets[indx] = newnode;
        printf("Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n", 
            //just to be sure that head is updated lol
            dict->buckets[indx]->data.colorName,
            dict->buckets[indx]->data.RGBVal[0],
            dict->buckets[indx]->data.RGBVal[1],
            dict->buckets[indx]->data.RGBVal[2],
            indx
        );
    }
}

Color* searchColor(Dictionary *dict, int rgb[3]){
int indx = hashFunction(rgb);
printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n", rgb[0], rgb[1],rgb[2], indx);
Node *trav = dict->buckets[indx];
while (trav != NULL)
{
    if (trav->data.RGBVal[0] == rgb[0] && trav->data.RGBVal[1] == rgb[1] && trav->data.RGBVal[2] == rgb[2])
    {
        return &trav->data;
    }else{
        trav = trav->next;
    }
}
return NULL;

}