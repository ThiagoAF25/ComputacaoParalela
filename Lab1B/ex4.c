#include <stdio.h>
#include <string.h>
/*
	Luiz Octavio Tassinari Saraiva
	Thiago Aidar Figueiredo
	Yiou Wu
*/

int main(){
  	char nome1[20], nome2[20];
  	printf("Digite o primeiro nome:");
  	scanf("%s", nome1);
  	printf("Digite o segundo nome:");
  	scanf("%s", nome2);
  	if(strcmp(nome1,nome2)<0){
    		printf("Nome: %s\n", nome1);
    		printf("Nome: %s\n", nome2);
  	}else{
    		printf("Nome: %s\n", nome2);
    		printf("Nome: %s\n", nome1);
  	}
 	 return 0;
}
