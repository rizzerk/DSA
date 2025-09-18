#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node * next;
}node, *LL;

void initList(LL*);
LL intList(void);
void insertSorted(LL *, int);
void insertFirst(LL *, int);
void insertLast(LL *,  int);
void deleteMem(LL *,  int);
int deleteFirst(LL *);
int deleteLast(LL *);
void deleteMults(LL*, int);
void displayList(LL);
int isFound(LL *, int);





int main(){

    return 0;
}

void initList(LL* list){
    *list = NULL;
    // **list kay ang pointer sa *list. *list kay gihimog null
}

LL intList(void){
    LL temp = NULL;
    return temp;
}

void insertSorted(LL *list, int data){
    LL newNode, *trav;

    for(trav = list; *trav != NULL && (*trav)->data <= data; trav = &(*trav)->next){}
    newNode = (LL)malloc(sizeof(node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = *trav;
        *trav = newNode;
    }
}

void insertFirst(LL *list, int data){
    LL newNode = (LL)malloc(sizeof(node));

    if(newNode != NULL){
        newNode->data = data;
        newNode->next = *list;
        *list = newNode;
    }
}

void insertLast(LL *list,  int data){
    LL newNode, *trav;

    for(trav = list; *trav != NULL; trav = &(*trav)->next){}
    newNode = (LL)malloc(sizeof(node));
    if(newNode!= NULL){
        newNode->data =data;
        newNode->next = *trav;
        *trav = newNode;
    }
}


void deleteMem(LL *list,  int data){
    LL temp, *trav;

    for(trav = list; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){} //if nakit an niya kay ang trav wala ga point sa next sa last node else kay ang trav ma null.
    if(*trav != NULL){ //if nakit an kay delete
        temp = *trav; 
        *trav = (*trav)->next;
        free(temp);
    }
}

int deleteFirst(LL *list){
    
    if(*list == NULL){
        printf("list is empty\n");
        return -1;
    }

    LL temp;
    temp = *list;
    int data = temp->data;
    *list = temp->next;
    free(temp);
    return data;
}

int deleteLast(LL * list){
    if(*list == NULL){
        printf("list is empty\n");
        return -1;
    }


     LL temp, *trav;
     for(trav = list; (*trav)->next != NULL; trav = &(*trav)->next){}
     temp = *trav;
     int data = temp->data;
     *trav = NULL;
    free(temp);
     return data;

}

void displayList(LL list){
    for(; list != NULL; list = list->next){
        printf("%d ", list->data);
    }
}

int isFound(LL *list, int data){
    LL *trav;

    for(trav = list; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}

    return *trav != NULL;
}

void deleteMults(LL*list, int data){
    if(*list != NULL){

        LL *trav;
        for(trav = list; *trav != NULL; ){
            if((*trav)->data == data){
                LL temp = *trav;
                *trav = temp->next;
                free(temp);
            }else{
                trav = &(*trav)->next;
            }
        }
    }

}