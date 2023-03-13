/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

#include <stdio.h>

int localiza(char *palavra, char letra, int tamanho){
  	int res = -1;
  	for(int i = 0; i < tamanho ; i++){
    		if (letra == palavra[i]){
      			res = i;
      			break;
    		}
  	}
  	return res;
}

int main(){
  	int tamanho = 30;
  	char palavra[30] = "hello world";
  	char letra = 'o';
	printf("%s\n", palavra);
  	int res = localiza(palavra, letra, tamanho);
  	printf("A letra esta na posição: %d\n", res);
  	return 0;
}
