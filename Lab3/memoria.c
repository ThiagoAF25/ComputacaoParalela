#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define ADDKEY 123
struct shmid_ds buf ;

int main() {
      int shmid, *shmPTR; /* identificador da memória comum */
      key_t key;
      pid_t childpid;
      key = ftok("/.",ADDKEY);
      shmid = shmget(key, 1024, 0644 | IPC_CREAT); //Cria o segmento de memoria compartilhada
      shmPTR = (int*) shmat(shmid, (void*) 0, 0); 
      *shmPTR = 1; //Valor inicial na memória compartilhada
      printf("Valor inicial = %d \n", *shmPTR);
      childpid = fork();
      if (childpid == -1) {
            perror("Failed to fork");
      return 1;
      }
      if (childpid == 0) /* child code */{
        shmid = shmget(key, 1024, 0644 | IPC_CREAT);
        shmPTR = ( int*) shmat(shmid, (void*)0, 0);
        *shmPTR += 2; //valor da variavel apos adicao de 2
        printf("Soma 2 no processo filho: %d\n", *shmPTR);
      }else{
        wait(0);
        shmid = shmget(key, 1024, 0644 | IPC_CREAT);
        shmPTR = ( int*) shmat(shmid, 0, 0);
        *shmPTR *= 3; // Multiplica o resultado do filho por 3
        printf("Multiplicação por 3 no processo pai = %d", *shmPTR);
        if ((shmctl(shmid, IPC_RMID, NULL)) == -1){ 
              perror("Erro shmctl()") ;
              exit(1) ; }
        exit(0);
      }
}
