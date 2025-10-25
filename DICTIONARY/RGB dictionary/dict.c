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
    for(int i=0; i < PALETTE_SIZE - 1; i++){
        dict->buckets[i] = NULL;
    }
}

Node* createNode(Color newColor){

}

void insertColor(Dictionary *dict, Color newColor){

}

Color* searchColor(Dictionary *dict, int rgb[3]){

}