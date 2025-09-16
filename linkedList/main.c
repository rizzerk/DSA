#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student {
  char fName[20];
  char lName[20];
  int yearlevel;
  struct student *link;
}Student, *StudentPTR;

void initLLV1(StudentPTR *S);
StudentPTR initLLV2(void);
void insert(StudentPTR S);

//PN = Pointer Node Trav

int PNTrav(StudentPTR);

int main(){
  Student A;
  Student B;

  A.link = &B;
  B.yearlevel = 3;

  printf("%d", A.link->yearlevel);

}

void initLLV1(StudentPTR *S){
  *S = NULL;
}

StudentPTR initLLV2(void){
  StudentPTR S = NULL;
  return S;
}

int PNTrav(StudentPTR L, char fName[]){ //L passes the address of the first node
  StudentPTR trav; 
  //trav = address of first node
  for(trav = L; trav != NULL; trav = trav->link && strcmp(trav->fName, fName)){}


}