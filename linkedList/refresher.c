#include <stdio.h>

typedef struct  node
{
    int data;
    struct  node * next;
}*LL, node;


void initList(LL*);
LL initListv2(void);
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


}  


void initList(LL* list){
    *list = NULL;
}

LL initListv2(void){
    LL list = NULL;
    return list;
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
    if(newNode != NULL){
        newNode->next = *trav;
        newNode->data = data;
        *trav = newNode;
    }
}

void deleteMem(LL *list,  int data){
    LL temp, *trav;
    for(trav = list; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

int deleteFirst(LL *list){
    if(*list == NULL){
        printf("List is empty \n");
        return -1;
    }
    
    LL temp;

    temp = *list;
    *list = temp->next;
    // *list = (*list)->next;
    int retval = temp->data;
    free(temp);

    return retval;
}

int deleteLast(LL *list){
    if(*list == NULL){
        printf("List is empty \n");
        return -1;
    }

    LL temp,  *trav;
    for( trav = list ; (*trav)->next != NULL; trav =  &(*trav)-> next){}
    temp = *trav;
    *trav = NULL;
    int retval = temp->data;
    free(temp);

    return retval;

}

void deleteMults(LL*list, int data){
    
    if(*list != NULL){
    LL temp, *trav;

    for(trav = list;  *trav != NULL;){
        if((*trav)->data == data){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }

    }
}
}

void displayList(LL head){
    for(;head != NULL; head = head->next){
        printf("%d ", head->data);
    }

}

int isFound(LL *list, int data){
    LL *trav;
     for(trav = list; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}

     return *trav != NULL;
}