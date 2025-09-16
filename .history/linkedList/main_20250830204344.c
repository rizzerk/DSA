#include <stdio.h>
#include <stdlib.h>

typedef struct personal {
  char fName[20];
  char lName[20];
}Personal, *PersonalPTR;


typedef struct student {
  char fName[20];
  char lName[20];
  int yearlevel;
  struct student *link;
}*StudentPTR;

int main(){
  
}
