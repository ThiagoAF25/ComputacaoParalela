#include <stdio.h>

/*
Luiz Octavio Tassinari Saraiva
Thiago Aidar Figueiredo
Yiou Wu
*/

	struct pessoa{
  		char nome[20];
  		int idade;
  		float peso;
  		float altura;
	};


	int main(){
  		struct pessoa Pessoas[3];
  		for(int i=0; i<3; i++){
    			printf("Digite o nome da %d° pessoa: ", i+1);
    			scanf("%s", Pessoas[i].nome);
    			printf("Digite a idade da %d° pessoa: ", i+1);
    			scanf("%d", &Pessoas[i].idade);
    			printf("Digite o peso da %d° pessoa: ", i+1);
    			scanf("%f", &Pessoas[i].peso);
    			printf("Digite o altura da %d° pessoa: ", i+1);
    			scanf("%f", &Pessoas[i].altura);
  		}

  		for(int i=0; i<3; i++){
    			printf("Nome: %s\n", Pessoas[i].nome);
    			printf("Idade: %d\n", Pessoas[i].idade);
    			printf("Peso: %.2f\n", Pessoas[i].peso);
    			printf("Altura: %.2f\n", Pessoas[i].altura);
  		}
		printf("\n");
		return 0;
	}
