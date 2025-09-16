#include <stdio.h>

int main (){
  int arr[] ={3, 1, 4, 1, 5, 8, 2, 6};
  // int arr[] ={1, 2};
  int max = 0;
  int s = -1;
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    max = max >= arr[i] ? max : arr[i]; //biggest number
    s = s < max && s >= arr[i] ?  arr[i] : s; //if s is less than max and s greater than index[i] s = s if not then s = arr[i]
  }

  printf("%d", max);
  printf("%d", s);
}