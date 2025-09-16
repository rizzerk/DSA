#include <stdio.h>

int main (){
  int arr[] ={1,2,3,4,5,6,7,8,9};
  int max = 0;
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    max = max >= arr[i] ? max : arr[i];
  }

  printf("%d", max);


}