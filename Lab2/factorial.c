#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  int res, pid, pip[2];
  int i, num, j;
  printf("Enter the number: ");
  scanf("%d", &num);
  j = num;
  int metade = j / 2;

  pipe(pip);
  pid = fork();

  if (pid == -1) { // verificar criação do filho
    perror("Failed to fork");
    return 1;
  }
  if (pid == 0) { // atribuir trabalho ao filho
    for (i = 1; j > metade; j--) {
      i = i * j;
    }
    write(pip[1], &i, sizeof(res));
  } else { // atribui trabalho ao pai
    for (i = 1; metade > 1; metade = metade - 1) {
      i = i * metade;
    }
    wait(&pid);
    read(pip[0], &res, sizeof(int));
    i *= res;
    printf("The factorial of %d is %d\n", num, i);

     }
}
