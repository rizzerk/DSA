#include <stdio.h>

int main (){
  int arr[] ={3, 1, 4, 1, 5, 8, 2, 6};
  int max = 0;
  int s= -1;
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    max = max >= arr[i] ? max : arr[i]; //biggest number
  }
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    s = s < max && arr[i] >= s  && arr[i] != max ?  arr[i] : s; //second largest
  }



  printf("%d", max);
  printf("%d", s);
}