#include <stdio.h>

int linearSearch(int arr[], int item, int size){
  for(int i=0; i<size;i++){
    if(item == arr[i]){
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int item, int size){
  int left =0, right = size-1, mid;
  while(mid>=0 && mid<size){
    mid = (left+right)/2;
    if(item<arr[mid]){
      right = mid -1;
    }
    else if(item>arr[mid]){
      left = mid + 1;
    }
    else if(item == arr[mid]){
      return mid;
    }
    else{
     return -1;
    }
  }
  return -1;
}

void bubbleSort(int arr[], int size){
  for(int i=0; i<size; i++){
    for(int j=i; j<size; j++){
      if(arr[i] > arr[j]){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}


int main(){
  int arr[10] = {2,3,1,5,6,2,8,4,9,7}, num;
  bubbleSort(arr, 10);
  for(int i=0;i<10;i++){
    printf("%d\t",arr[i]);
  }
  printf("Enter Number to Search : ");
  scanf("%d",&num);
  printf("\nLinear Search %d : %d", num,linearSearch(arr, num, 10));
  printf("\nBinary Search %d : %d\n", num,binarySearch(arr, num, 10));
}
