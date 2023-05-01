#include <stdio.h>
#include <math.h>
#include <gmp.h>

int main(void) {
  int i=1, n = 10000;
  mpf_t euler, fatorial, var, res;
  //mpf_init_set_d(euler, 1.0);
  //mpf_init_set_d(fatorial, 1.0);
  mpf_init2(euler, 2097152U);
  mpf_init2(fatorial, 2097152U);
  mpf_init2(var, 2097152U);
  mpf_init2(res, 2097152U);
  mpf_set_ui(euler,1);
  mpf_set_ui(fatorial,1);
  mpf_set_ui(var, 1);
  mpf_set_ui(res, 1);

  while(i <= n){
    mpf_mul_ui(fatorial, fatorial, i);
    mpf_div(res, var, fatorial);
    mpf_add(euler, euler, res);
    i++;
  }
  gmp_printf("%.9999Ff", euler);

  mpf_clear(euler);
  mpf_clear(fatorial);

  return 0;
}

