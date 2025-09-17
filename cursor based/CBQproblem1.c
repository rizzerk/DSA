#include <stdio.h>
#include <stdlib.h>
#define MAX 99

typedef struct{
    char FN[24], LN[16], MI;
}nametype;

typedef struct{
    char ID[10];
    nametype name;
    char course[8];
    int yrLevel;
}studRec;

//Virtual Heap Definition

typedef struct {
    studRec stud;
    int link;
}nodetype;

typedef struct{
    nodetype VSpace[MAX];
    int firstAvail; //index of first avaiable node
}vHeap;

//Queue definition

typedef struct{
    int start;
    int end;
    int cnt;
    vHeap *vptr;
}queue;

void initVHeap(vHeap *VH){
    VH->firstAvail = 0;
    int i;
    for(i = 0; i < MAX - 1; i ++){
        VH->VSpace[i].link = i +1; //set the links
    }

    VH->VSpace[i].link = -1; //last index
}

/*TO DO: Write the code of the following functions:
    1.) initQueue() -   Given the queue and the address of the virtual heap, 
                        the function will initiliaze the given queue to be empty
    2.) removeFirst -   The function will remove the first element of the given queue
                        and return it to the calling function. A dummy variable contains "XXXXX", and
                        'X' for string and character firled respectively; and zero values for the rest
                        of the fields is returned if there is no first element. Note: This function 
                        cannot call any function.
*/

void initQueue(queue *q, vHeap *vh){
    q->start = -1;
    q->end = -1;
    q->cnt = 0;
    q->vptr = vh;
}

studRec removeFirst(queue *q){
    studRec temp = {"XXXXX", {"XXXXX", "XXXXX", 'X'}, "XXXXX", 0};

    int indx = q->start;
    if(indx != -1){ //or q->cnt > 0
        q->start = q->vptr->VSpace[indx].link; 
        temp =  q->vptr->VSpace[indx].stud; 


        if(indx == q->end){
            q->start = -1; //not sure
            q->end = -1;
        }


        //dealloc
        q->vptr->VSpace[indx].link = q->vptr->firstAvail; 
        q->vptr->firstAvail = indx;

        q->cnt--;
    }      

    return temp;
}




int main(){

    return 0;
}