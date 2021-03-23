#include <stdio.h>
#include <string.h>

void countSort(int arr[], int n){
  //finding Max 
  int max=arr[0];
  for(int i=1; i<n; i++){
    max = arr[i]>max?arr[i]:max;
  }

  //creating countArr initialised with 0
  int countArr[max];
  for(int i=0; i<max; i++){
    countArr[i] = 0;
  }

  for(int i=0; i<n; i++){
    countArr[arr[i]]++;
  }

  //adding count
  for(int i=1; i<=max; i++){
    countArr[i] += countArr[i-1];
  }

  //final sorted array
  int fArr[n];

  for(int i=n-1; i>=0; i--){
    fArr[--countArr[arr[i]]] = arr[i];
  }

  for(int i=0; i<n; i++){
    arr[i] = fArr[i];
  }
}

int main(){
  int size;
  printf("Enter the size of Array : ");
  scanf("%d",&size);
  int arr[size];
  printf("Enter the Array :\n");
  for(int i=0; i<size;i++){
    scanf("%d", &arr[i]);
  }
  printf("\nSorted Array is : \n");
  countSort(arr, size);
  for(int i=0; i<size;i++){
    printf("%d\n", arr[i]);
  }

  return 0;
}


