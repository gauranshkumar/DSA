#include <stdio.h>
#include <stdbool.h>  
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int arr[], int size){
  for(int i=0; i<size; i++){
    bool flag = false;
    for(int j=0; j<size-1-i; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        flag = true;
      }
    }
    if(!flag){
      break;
    }
  }
}

int main(){
  int size;
  printf("Enter the size of Array : ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of Array : \n");
  for(int i=0;i<size;i++){
    scanf("%d", &arr[i]);
  }

  bubble_sort(arr, size);
  printf("Sorted Array : \n");
  for(int i=0;i<size;i++){
    printf("%d\n", arr[i]);
  }
}
