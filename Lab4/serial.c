#include <stdio.h>

int A[2000][2000]; //matriz A
int x[2000]; //vetor x
int m = 2000; //linha de matriz A
int n = 2000; //coluna de matriz A
int y[2000] = {0}; //resultado de multiplicacao

int main(int argc, char*argv[]){
  //preencher matriz A
  for (int i = 0; i<m;i++){
    for (int j = 0; j<n;j++){
      A[i][j] = (i%5)*(j%5);
    }
  }
  //preencher vetor X
  for(int i = 0; i<n;i++){
    x[i] = i % 6;
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      y[i] += A[i][j] * x[j];
    }
  }
  return 0;
}
