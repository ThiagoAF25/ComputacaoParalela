#include <stdio.h>

/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

#include <stdio.h>

void print(int matriz[3][3], int linhas, int colunas){
  	for(int i = 0; i < linhas;i++){
    		printf("\n");
    		for(int j = 0; j < colunas;j++){
      			printf("%d ", matriz[i][j]);
    		}
  	}
	printf("\n");
}

void substituir(int matriz[3][3], int linha, int coluna){
  	for(int i=0; i<linha; i++){
    		for(int j=0; j<coluna; j++){
      			if(matriz[i][j]<0){
        			matriz[i][j] *= -1;
      			}
    		}
  	}
}

int main(){
  	int matriz[3][3]= {{-4,5,6},{10,-1,6},{9,-8,7}};
  	print(matriz, 3 ,3);
	substituir(matriz, 3, 3);
  	print(matriz, 3, 3);
  	return 0;
}
