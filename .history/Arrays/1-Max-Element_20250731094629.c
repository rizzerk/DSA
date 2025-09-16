#include <stdio.h>

int main (){
  // int arr[] ={3, 1, 4, 1, 5, 8, 2, 6};
  int arr[] ={1, 1,1,1};
  int max = 0;
  int s = -1;
  for(int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    max = max >= arr[i] ? max : arr[i];
    s = s < max && s >= arr[i] ?  s : arr[i];
    s = s == max ? -1 : s;
  }

  printf("%d", max);
  printf("%d", s);
}