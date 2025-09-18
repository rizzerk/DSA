#include <stdio.h>
#include <stdlib.h>

#define MAX 0xA

/*
The records of all BSCS, BSIS,  BSIT, BSMath students are stored in the DCISM list 
represented in memory using a linked list implementation. A combo list is created to 
store the records of all BSCS and BSIT represented in memory using linked list and 
array implementations respectively. Given below is the definition of the array list, 
linked list and combo list.
*/

typedef struct{
    char FN[24], LN[16], MI;
}nametype;

typedef struct{
    char ID[10];
    nametype name;
    char course[8];
    int yrLevel;
}studRec;

//definition of ArrayList (Version2) and LinkList

typedef struct cell{
    studRec studs[MAX];
    int ctr; //element count
}*ArrayList;

typedef struct node{
    studRec stud;
    struct  node *link;
}*LinkList;

//Definiton ComboList

typedef struct{
    LinkList CS;
    ArrayList IT;
}ComboList;

/*
Based on the above definition and description, complete the code below by filling in the blanks. 
Given the DCISM list of student records with courses BSCS, BSIS, BSIT and BSMath; represented in memory 
using linked list, the function will all remove all BSCS and BSIT student records from the DCISM list 
and put them in a newly created combo list of student records. The newly created combo list will be 
returned to the calling function. No other user-defined function is created except function createList(). 
Assume that there is enough space in memory for all the records.
*/

ComboList createList(Blank_A D)
{
    ComboList dcism;
    LinkList *trav, temp;
    //Initialize ComboList
    //initializes the CS list
    BLANK_B
    //Blank_C and Blank_D initialize the IT list
    BLANK_C
    BLANK_D

    for(trav = D; *trav != NULL;)
    //BLANK_E detrmines if record is owned by a computer science student
    //BLANK_F determines if record is owned by an information technology student

    if(BLANK_E || BLANK_F){
        temp = *trav;
        *trav = temp->link;

        if(BLANK_E){
            //Blank_G and Blank_H insert the removed revord above to CS list in combo list and put in 1st position
            BLANK_G
            BLANK_H
        }else{
            //Blank_I and Blank_J insert the removed record above to IT list and put in the last positon
            BLANK_I
            BLANK_J
            free(temp);
        }

    }else{
        trav = &(*trav)->link;
    }

    return dcism;

}