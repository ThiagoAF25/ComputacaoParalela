#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	Luiz Octavio Tassinari Saraiva
	Thiago Aidar Figueiredo
	Yiou Wu
*/

int** preencher(int **ptr, int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		for(int j = 0; j < colunas;j++){
      			printf("Posicao %d,%d:", i, j);
      			scanf("%d", &ptr[i][j]);
    		}
  	}
  	return ptr;
}

void print(int **ptr, int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		printf("\n");
    		for(int j = 0; j < colunas;j++){
      			printf("%d ", ptr[i][j]);
    		}
  	}
}

int** multiplica(int **ptr, int linhas, int colunas, int opcao){
  	int num;
  	int pos;
  	if (opcao == 1){
    		printf("Digite a linha que será multiplicada: ");
    		scanf("%d", &pos);
    		printf("Digite o numero pelo qual quer multiplica: ");
    		scanf("%d", &num);
    		for(int j = 0; j < colunas;j++){
      			ptr[pos][j]= ptr[pos][j] * num;
      		}
    	}
	else {
        	printf("Digite a coluna que será multiplicada: ");
        	scanf("%d", &pos);
        	printf("Digite o numero pelo qual quer multiplicar: ");
        	scanf("%d", &num);
        	for(int j = 0; j < linhas;j++){
          		ptr[j][pos] =ptr[j][pos]*num; 
        	}
      	}
 	 return ptr;
}

int main(){
  	int linhas, colunas, op;
  	printf("Numero de linhas: ");
  	scanf("%d", &linhas);
  	printf("Numero de colunas: ");
 	scanf("%d", &colunas);
  	int **matriz = (int **)malloc(linhas * sizeof(int*));
  	for(int i = 0; i < linhas; i++) matriz[i] = (int *)malloc(colunas * sizeof(int));
  	matriz = preencher(matriz, linhas, colunas);
  	print(matriz, linhas, colunas);
  	while(1){
    		printf("\n\nDigite 1 para multiplicar uma linha,\n2 para multiplicar uma coluna \nou 0 para sair: ");
    		scanf("%d", &op);
    		if (op == 0) break;
    		else if(op == 1 || op == 2) multiplica(matriz, linhas, colunas, op);
    		print(matriz, linhas, colunas);
  	}
  	return 0;
	printf("\n");
}
