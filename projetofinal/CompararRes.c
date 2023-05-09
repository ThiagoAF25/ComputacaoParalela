#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  FILE *fptr1, *fptr2;
  char arq[30], char1, char2;
  fptr1 = fopen("EulerOriginal.txt", "r");
  if(fptr1 == NULL){
      printf("File not found\n");
      return 0;
  }
  printf("Qual arquivo deseja comparar? ->");
  scanf("%s", arq);
  fptr2 = fopen(arq, "r");
  if(fptr2 == NULL){
      printf("File not found\n");
      return 0;
  }
  int pos = 0, igual = 1;

  while (1) {
      pos++;
      char1 = fgetc(fptr1);
      char2 = fgetc(fptr2);
      while (isspace(char1)) {
          char1 = fgetc(fptr1);
      }
      while (isspace(char2)) {
          char2 = fgetc(fptr2);
      }
      if (char1 == EOF || char2 == EOF) break;
    
      if (char1 != char2) {
          printf("Diferança na posição %d:\n", pos);
          printf("Dígito de Euler original: %c\n", char1);
          printf("Dígito encontrado: %c\n\n", char2);
          igual = 0;
          break;
      }

  }

  if (igual == 1) printf("Aproximação correta.\n\n");

  fclose(fptr1);
  fclose(fptr2);
}
