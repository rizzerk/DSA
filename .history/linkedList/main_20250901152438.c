#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  char fName[20];
  char lName[20];
  int yearlevel;
  struct student *link;
}Student, *StudentPTR;

void initLLV1(Student *S);
Student initLLV2(void);

int main(){
  Student A;
  Student B;

  A.link = &B;
  B.yearlevel = 3;

  printf("%d", A.link->yearlevel);

}
