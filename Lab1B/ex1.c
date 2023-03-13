#include <stdio.h>
/* Luiz Octavio Tassinari Saraiva
   Thiago Aidar Figueiredo
   Yiou Wu
*/
int menorMatriz(int matriz[3][3]){
    int linhamenor, menor = matriz[0][0]; //linhamenor guarda linha com o menor número e menor o menor número
    for(int i = 0; i < sizeof(matriz[0][0])-1;i++){ //Verificando linha a linha
       for(int j = 0; j < sizeof(matriz[0][0])-1;j++){ //Verificando coluna a coluna
          printf("i: %d j: %d\n",i,j);
           if (matriz[i][j]<menor){ //Se o número da posição for menor, troca linhamenor(linha que possui o menor número) e menor
              linhamenor = i;
              printf("Linha: %d\n", linhamenor);
              menor = matriz[i][j];
              printf("Menor: %d\n", menor);
           }
       }
    }
    return linhamenor+1;
}

int main()
{
    int matriz[3][3]= {{4,5,6},{10,1,6},{9,8,7}};
    printf("Linha: %d",menorMatriz(matriz));

    return 0;
}
