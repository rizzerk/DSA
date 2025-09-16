#include <stdio.h>

int main (){
  int arr[] = {1,2,3,4,5};

  int len = sizeof(arr)/sizeof(arr[0]);
  int i = len-1;
  int j = 0;

  while(i > j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    j++;
    i--;
  }

  for(i = 0; i <len; i++){
    printf("%d", arr[i]);
  }


}