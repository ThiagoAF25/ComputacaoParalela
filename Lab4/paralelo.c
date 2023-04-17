#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count = 4; //numero de threads
int A[2000][2000]; //matriz A
int x[2000]; //vetor x
int m = 2000; //linha de matriz A
int n = 2000; //coluna de matriz A
int y[2000] = {0}; //resultado de multiplicacao
void *Pth_mat_vect(void *rank){
    long my_rank = (long) rank;
    int i, j;
    int local_m = m/thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank+1) * local_m -1;
    
    for(i=my_first_row; i<=my_last_row; i++){
        y[i] = 0.0;
        for(j=0;j<n;j++){
            y[i] += A[i][j] * x[j];
        }
    }
    
    return NULL;
}

int main(int argc, char*argv[]){
  long thread;
  pthread_t* thread_handles;
  //preencher matriz A
  for (int i = 0; i<m;i++){
    for (int j = 0; j<n;j++){
      A[i][j] = (i%5)*(j%5);
    }
  }
  //preencher vetor X
  for(int i = 0; i<n;i++){
    x[i] = i % 6;
  }
  //thread_count = strtol(argv[1], NULL, 10);
  //Serve para ler o numero de threads na forma de argumento na linha de comando

  thread_handles = malloc (thread_count*sizeof(pthread_t));
  
  //Cria uma thread para cada elemento em thread_handes
  //O tipo de thread_handes é pthread_t, que funciona como um id para cada thread.
  for (thread = 0; thread < thread_count; thread++){
    pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*)thread);
  }

  //pthread_join ativa a rotina de cada thread criada 
  for (thread = 0; thread < thread_count; thread++){
    pthread_join(thread_handles[thread], NULL);
  }

  free(thread_handles);
  return 0;
}
