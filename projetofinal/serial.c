#include <stdio.h>
int main(void) {
  int i=1, n =55;
  long double euler = 1.0;
  long double fatorial = 1.0;

  while(i <= n){
    fatorial *= i;
    euler+= 1.0/fatorial;
    i++;
  }
  printf("%.62Lf\n", euler);
}
