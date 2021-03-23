#include <stdio.h>

void selectionSort(int arr[], int n){
  for(int i=0; i<n-2; i++){
    int iMin = i;
    for(int j=i+1; j<n-1;j++){
      if(arr[j] < arr[iMin]){
        iMin = j;
      }
        int temp = arr[i];
          arr[i] = arr[iMin];
          arr[iMin] = temp;
    }
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
  selectionSort(arr, size);
  for(int i=0; i<size;i++){
    printf("%d\n", arr[i]);
  }

  return 0;
}
