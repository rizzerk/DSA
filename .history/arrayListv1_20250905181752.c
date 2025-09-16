#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
	int elems[MAX];
	int count;
}List;

void initListV1(List*);
List initListV2(void);

void insertLast(List*, int);
void insertFirst(List*, int);
void insertSorted(List*, int);

void deleteLast(List*);
void deleteFirst(List*);
void deleteElem(List*, int);

int findElem(List, int);

void displayList(List);

int main(void)
{
	List listNum;
	//initListV2();
	initListV1(&listNum);
	int i;

	for(i = 2; i < 20; i += 2){
		insertLast(&listNum, i);
	} //inside the elems are even numbers
	
  insertFirst(&listNum, 1);
  insertSorted(&listNum, 0);
  insertSorted(&listNum, 5);
  insertSorted(&listNum, 22);
  insertSorted(&listNum, 11);
  deleteElem(&listNum, 4);
  displayList(listNum);

	printf("Searching for %d. Found at: %d\n", 12, findElem(listNum, 12));

  
	
	
	return 0;
}

void initListV1(List *L){
  L->count = 0;
}

List initListV2(void){
  List temp;
  temp.count = 0;
  return temp;
}

void insertLast (List *L, int data){
  if(L->count != MAX){
    L->elems[L->count] = data;
    L->count++;   
  }
}

void insertFirst (List *L, int data){
  if(L->count < MAX){
    for(int i = L->count; i >0; i--){
      L->elems[i] = L->elems [i-1];
    }
    L->elems[0] = data;
    L->count++;
  }
}



void insertSorted (List *L, int data){
  if(L->count < MAX){
    int i;
    //linear search
    // for(i =0;  i < L->count && data >=  L->elems[i]; i++){}
    // for(int j = L->count; j > i; j--){
    //   L->elems[j] = L->elems[j-1];
    // }


    //binary search
    int low =0, high = L->count-1;
    while (low <= high){
      int mid = (low + high) /2;
      if(data < L->elems[mid]){
        high = mid-1;
      } else {
        low = mid +1;
      }
    }

    for(int j = L->count; j > low ;j--){
      L->elems[j] = L->elems[j-1];
    }
    L->elems[low] = data;
    L->count++;
  }
}

void deleteLast (List *L){
  if(L->count > 0){
    L->count --;
  }
}

void deleteFirst (List *L){
  if(L->count > 0){
    for(int i = 0; i < --L->count -1; i++){
    L->elems[i] = L->elems[i+1];
    }
  }
}

void deleteElem (List *L, int x){
  
  int low=0, high = L->count -1;
  while (low<= high){
    int mid = (low + high) /2;
    if(x == L->elems[mid]){
      for(int i=mid; i < L->count -1; i++){
        L->elems[i] = L->elems[i+1];
      }
      L->count --;
      return;
    } else if (x < L->elems[mid]){
      high = mid- 1;
    } else{
      low = mid +1;
    }
  }
}

int findElem(List L, int x){
  //linear search
  // int i;
  // for(i=0; i < L.count && L.elems[i] != x; i++){}
  // return i < L.count ? i : -1;

  int low = 0, high = L.count -1;
  while (low <=high){
    int mid = (low + high) /2;
    if(x == L.elems[mid]){
      return mid;
    }else if (x < L.elems[mid]){
      high = mid -1;
    } else {
      low = mid +1;
    }
  }
  return -1;

}

void displayList(List L){
  for(int i=0; i < L.count; i++){
    printf("L[%d]: %d\n", i, L.elems[i]);
  }
}