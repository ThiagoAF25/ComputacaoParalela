#include <stdio.h>

/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

#include <stdio.h>

void soma(int matriz[3][3], int linha1, int linha2, int coluna){
  	for(int i = 0 ; i<coluna ; i++){
     		matriz[linha2][i] = matriz[linha1][i] + matriz[linha2][i]; 
  	}
}

void mult(int matriz[3][3], int linha1, int linha2, int coluna){
  	for(int i = 0 ; i<coluna ; i++){
     		matriz[linha2][i] = matriz[linha1][i] * matriz[linha2][i]; 
  	}
}


void print(int matriz[3][3], int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		printf("\n");
    		for(int j = 0; j < colunas;j++){
      			printf("%d ", matriz[i][j]);
    		}
  	}
}


int main(){
  	int matriz[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
  	print(matriz, 3, 3);
  	printf("\n\n");
  	soma(matriz, 0, 1, 3);
  	print(matriz, 3, 3);
  	printf("\n\n");
  	mult(matriz, 0, 1, 3);
  	print(matriz, 3, 3);
	printf("\n");
	return 0;
}
