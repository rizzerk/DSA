#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int next;
}node;


typedef struct{
    node elems[MAX]; //memory
    int avail; //store ang index nga gamiton or ang i allocate
}vHeap;

typedef int cList;

void initVHeap(vHeap *VH);
int allocSpace(vHeap *VH);
void deallocSpace(vHeap *VH, int pos);
void initCList(cList *CL);
void insertFirst(cList *CL, vHeap *VH, int data);
void deleteMem(cList *CL, vHeap *VH, int data);
void displayCList(cList CL, vHeap VH);

int main(){
    vHeap myHeap;
	cList myList;
	cList listTwo;
	
	initVHeap(&myHeap);
	initCList(&myList);
	initCList(&listTwo);
	
	insertFirst(&myList, &myHeap, 10);
	insertFirst(&myList, &myHeap, 20);
	insertFirst(&myList, &myHeap, 30);
	insertFirst(&myList, &myHeap, 40);
	insertFirst(&myList, &myHeap, 50);
	
	deleteMem(&myList, &myHeap, 30);
	insertFirst(&listTwo, &myHeap, 100);
	insertFirst(&listTwo, &myHeap, 500);
	
	displayCList(myList, myHeap);
	displayCList(listTwo, myHeap);
    return 0;
}


void initVHeap(vHeap *VH){
    //set the available index to the first index 0
    VH->avail = 0;

    //initialize the array of spaces
    int i;
    for(i=0; i < MAX-1; i++){
        VH->elems[i].next = i+1;
    }

    //set the last index to point to -1
    VH->elems[i].next = -1;

}

int allocSpace(vHeap *VH){
    //mag initialize ug variable nga i return
    int allocatedIndex = VH->avail; //ang ihatag nga space (index) kay ang index nga available;

    //if dili sya null or -1 kay i update ang available space;
    if(allocatedIndex != -1){
        VH->avail = VH->elems[allocatedIndex].next; //ang next available space kay ang next sa gi pass nga allocated space;
    }

    return allocatedIndex; //di mag matter if -1 or nah kay i check ra gihapon balik
}

void deallocSpace(vHeap *VH, int pos){
    //flip and mirror alloSpace without if and return
    VH->elems[pos].next = VH->avail;
    VH->avail = pos;
}

void initCList(cList *CL){
    //set to  null (-1 sa cursor based)
    *CL = -1;
}


void insertFirst(cList *CL, vHeap *VH, int data){
    cList temp; //or new node

    temp = allocSpace(VH); //should catch an integer kay int man ang cList. I should hold the index nga ato gamiton.
    if(temp != -1){
        VH->elems[temp].data = data; //update sa data
        VH->elems[temp].next = *CL;  //ang next kay ang head (int to int)   
        *CL = temp; //ang index nga gi point sa CL (head sa list) kay ang newNode or newIndex;
    }

}

void deleteMem(cList *CL, vHeap *VH, int data){
    cList temp, *trav;
    for(trav = CL; *trav != -1 && VH->elems[*trav].data != data; trav = &VH->elems[*trav].next){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->elems[*trav].next;
        deallocSpace(VH, temp);
    }
}

void displayCList(cList CL, vHeap VH){
    for(;CL != -1; CL = VH.elems[CL].next){
        printf("%d ", VH.elems[CL].data);
    }
}