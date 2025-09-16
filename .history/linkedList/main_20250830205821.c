#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  char fName[20];
  char lName[20];
  int yearlevel;
  struct student *link;
}Student, *StudentPTR;

int main(){
  Student A;
  Student B;

  A.link = &B;
  B.yearlevel = 3;

  printf("%d", A.link->yearlevel);

}
