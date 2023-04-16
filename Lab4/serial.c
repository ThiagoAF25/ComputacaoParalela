#include <stdio.h>


int A[8][4] = {{1,1,1,1},{2,3,4,5},{3,6,10,15},{4,10,20,35},{5,15,30,70},{6,21,56,126},{7,28,84,210},{8,36,120,330}}; //matriz A
int x[4] = {1,2,3,4}; //vetor x
int m = 8; //linha de matriz A
int n = 4; //coluna de matriz A
int y[8] = {0}; //resultado de multiplicacao

int main(int argc, char*argv[]){
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      y[i] += A[i][j] * x[j];
    }
  }
  for(int j = 0; j <m; j++){
    printf("%d\t",y[j]);
  }
  printf("\n");
  return 0;
}
