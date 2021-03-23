#include <stdio.h>

void insertionSort(int arr[], int n){
  int value, hole;
  for(int i=1; i<n; i++){
    value = arr[i];
    hole = i;
    while(hole > 0 && arr[hole-1]>=value){
      arr[hole] = arr[hole-1];
      hole--;
    }
    arr[hole] = value;
  }

  printf("\nSorted Array : \n");
  for(int i=0; i<n; i++){
    printf("%d\t", arr[i]);
  }

}


int main(){
  int arr[6], n=6;
  printf("Enter the array : \n");
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  insertionSort(arr, n);
}

