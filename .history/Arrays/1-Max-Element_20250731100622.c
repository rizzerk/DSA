#include <stdio.h>

int main (){
  int arr[] ={3, 1, 4, 1, 5, 8, 2, 6};
  int max = 0;
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    max = max >= arr[i] ? max : arr[i]; //biggest number
  }


  printf("%d", max);
}