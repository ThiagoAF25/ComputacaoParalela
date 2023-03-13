#include <stdio.h>
#include <stdlib.h>
/*
	Luiz Octavio Tassinari Saraiva
	Thiago Aidar Figueiredo
	Yiou Wu
*/
void print(int **ptr, int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		printf("\n");
    		for(int j = 0; j < colunas;j++){
      			printf("%d ",ptr[i][j]);
    		}
  	}
}

int** preencher(int **ptr, int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		for(int j = 0; j < colunas;j++){
      			printf("Posicao %d,%d:", i, j);
      			scanf("%d", &ptr[i][j]);
    		}
  	}
  	print(ptr, linhas, colunas);
  	return ptr;
}

int** transposta(int **ptr, int linhas, int colunas){
  	int **transp = (int **)malloc(colunas* sizeof(int*));
  	for(int i = 0; i < colunas; i++) transp[i] = (int *)malloc(linhas * sizeof(int));
  	for(int i = 0; i < linhas; i++){
    		for (int j = 0; j < colunas; j++){
      			transp[j][i] = ptr[i][j];
    		}
  	}
  	return transp;
}



int main(){
  	int linhas, colunas;
  	printf("Numero de linhas: ");
  	scanf("%d", &linhas);
  	printf("Numero de colunas: ");
  	scanf("%d", &colunas);
  	int **matriz = (int **)malloc(linhas * sizeof(int*));
  	for(int i = 0; i < linhas; i++) matriz[i] = (int *)malloc(colunas * sizeof(int));
  	matriz = preencher(matriz, linhas, colunas);
  	int **transp = transposta(matriz, linhas, colunas);
  	print(transp, colunas, linhas);
	printf("\n");
	return 0;
}
