#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void thread_Euler(int n, mpf_t *global_euler);

int main(int agrc , char*argv[]) {
  int thread_count, n = 3250;
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
  mpf_t fatorial, var, res, local_euler;
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  long double mult_fatorial;
  mpf_init2(fatorial, 33500U);
  mpf_init2(var, 33500U);
  mpf_init2(res, 33500U);
  mpf_init2(local_euler, 33500U);
  mpf_set_ui(local_euler,1);
  mpf_set_ui(fatorial,1);
  mpf_set_ui(var, 1);
  mpf_set_ui(res, 1);
  for(int i = my_rank+1; i <= n; i+=thread_count){
    mult_fatorial = 1;
    for(int j = 0; (j< thread_count) && ((i-j)>1); j++){
      mult_fatorial *= i-j;
    }
    mpf_mul_ui(fatorial, fatorial, mult_fatorial);
    mpf_div(res, var, fatorial);
    mpf_add(local_euler, local_euler, res);
  }
#   pragma omp critical
  mpf_add(*global_euler, *global_euler, local_euler);

  mpf_clear(local_euler);
  mpf_clear(fatorial);
  mpf_clear(var);
  mpf_clear(res);
}

