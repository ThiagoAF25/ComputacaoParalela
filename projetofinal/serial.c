#include <stdio.h>
#include <math.h>
#include <gmp.h>

int main(void) {
  FILE *fptr;
  int i=1, n = 100000;
  mpf_t euler, res;
  mpf_init2(euler, 3350000U);
  mpf_init2(res, 3350000U);
  mpf_set_ui(euler,1);
  mpf_set_ui(res, 1);

  while(i <= n){
    mpf_div_ui(res, res, i);
    mpf_add(euler, euler, res);
    i++;
  }
  fptr = fopen("ResultadosSerial.txt","w");

  gmp_fprintf(fptr,"%.999999Ff\n", euler);

  mpf_clear(euler);
  mpf_clear(res);
  fclose(fptr);
  return 0;
}

