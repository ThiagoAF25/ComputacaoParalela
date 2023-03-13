#include <stdio.h>
#define TAM 100

/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

void removechar(char *str, int pos){
  	for (int i = pos; i < TAM-1; i++){
    		str[i] =  str[i+1];
  	}
}

int main(){
  	char Str[TAM] = "tem aula magna na quinta";
  	int pos = 10;
	printf("%s\n", Str);
  	removechar(Str, pos);
  	printf("%s\n", Str);
	return 0;
}
