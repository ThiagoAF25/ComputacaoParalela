#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void thread_Euler(int n, mpf_t *global_euler);

int main(int agrc , char*argv[]) {
  int thread_count, n = 10000;
  mpf_t global_euler;
  mpf_init2(global_euler, 33500U);
  thread_count = strtol(argv[1],NULL, 10);
#pragma omp parallel num_threads(thread_count)

  thread_Euler(n,  &global_euler);
  printf("Euler: ");
  
  gmp_printf("%.9999Ff\n", global_euler);

  mpf_clear(global_euler);


  return 0;
}

void thread_Euler(int n, mpf_t *global_euler){
  mpf_t res, local_euler;
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  mpf_init2(res, 33500U);
  mpf_init2(local_euler, 33500U);
  mpf_set_ui(local_euler,1);
  mpf_set_ui(res, 1);
  for(int i = 1; i <= n; i++){
    if(i % thread_count == my_rank){
      mpf_div_ui(res, res, i);
      mpf_add(local_euler, local_euler, res);
    }else{
      mpf_div_ui(res, res, i);
    }
  }
#   pragma omp critical
  mpf_add(*global_euler, *global_euler, local_euler);

  mpf_clear(local_euler);
  mpf_clear(res);
}
