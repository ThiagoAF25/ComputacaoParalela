/*
	Luiz Octavio Tassinari Saraiva
	Thiago Aidar Figueiredo
	Yiou Wu
*/
#include <stdio.h>
#define TAM 4
void preencher(float lista[]){
    for(int i = 0; i < TAM; i++){
        if (i == 3){
            printf("Media dos exercícios: ");
            scanf("%f",&lista[i]);
        }else{
            printf("Nota %d:", i+1);
            scanf("%f",&lista[i]);
        }
    }
}
void notafinal(float *lista){
    float media = 0;
    for(int i = 0; i < TAM; i++){
        if (i == 3){
            media += lista[i];
        }else{
            media += lista[i] *(i+1);
        }
    }
    media = media/7;
    printf("\n Media final: ");
    if (media >= 9) printf("A");
    else if (media >= 7.5) printf("B");
    else if (media >= 6) printf("C");
    else if (media >= 4) printf("D");
    else printf("E");
}
int main()
{
    float notas[TAM];
    preencher(notas);
    notafinal(notas);
    printf("\n");
    return 0;
}
