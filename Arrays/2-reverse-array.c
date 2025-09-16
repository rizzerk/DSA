#include <stdio.h>

int main (){
  int arr[] = {1,8,2,3,4,5};

  int len = sizeof(arr)/sizeof(arr[0]);
  int i = len-1; //index
  int j = 0; //first index

  while(i > j){ //i is greater than j
    //swap each end of array 
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    j++; //first index to half
    i--; //last index to half
  }

  for(i = 0; i <len; i++){
    printf("%d", arr[i]);
  }


}