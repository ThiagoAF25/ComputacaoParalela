#include <stdio.h>
/*
	Luiz Octavio Tassinari Saraiva
	Thiago Aidar Figueiredo
	Yiou Wu
*/

void imprime(int num){
  	int i = 1, j = num;
  	while(1){
    		if(i > j) break;
    		for(int k = 1; k <=j ;k++){
      			if (k < i) printf("  ");
      			else printf("%d ", k);
    		}
    		++i;
    		--j;
    		printf("\n");
  	}
}

int main(void) {
  	int num;
  	input:
   	printf("Entrada: ");
   	scanf("%d",&num);
  	if (num % 2 == 0) goto input;
  	imprime(num);
  	return 0;
}
