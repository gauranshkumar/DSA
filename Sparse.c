#include <stdio.h>
int main(){
  int sparseMatrix[5][6] = {
    {0,0,0,0,9,0},
    {0,8,0,0,0,0},
    {4,0,0,2,0,0},
    {0,0,0,0,0,5},
    {0,0,2,0,0,0}
  };
  int compactMatrix[3][6];
  int count = 0;
  for(int i=0;i<5;i++){
    for(int j=0; j<6; j++){
      if(sparseMatrix[i][j] != 0){
        compactMatrix[0][count] = i;
        compactMatrix[1][count] = j;
        compactMatrix[2][count] = sparseMatrix[i][j];
        count++;
      }
      }
    }

  printf("Sparse Matrix is:\n");

  for(int i=0;i<5;i++){
    for(int j=0; j<6; j++){
      printf("%d\t", sparseMatrix[i][j]);
      }
    printf("\n");
    }
 printf("Compact Matrix\n");
  for(int i=0; i<3; i++){
    for(int j=0;j<6; j++){
      printf("%d\t", compactMatrix[i][j]);
    }
    printf("\n");
  }
}
