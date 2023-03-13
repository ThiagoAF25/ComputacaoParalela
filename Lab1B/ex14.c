/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

#include <stdio.h>
#define TAM 100

void inserechar(char *str, int pos, char add){
  	for (int i = TAM; i>=pos; i--){
    		str[i+1] =  str[i];
  	}
  	str[pos] = add;
}

int main(){
  	char Str[TAM] = "na quinta tem aula magna";
  	int pos = 10;
  	char adiciona = 'a';
	printf("%s\n", Str);
  	inserechar(Str, pos, adiciona);
  	printf("%s\n", Str);
	return 0;
}
