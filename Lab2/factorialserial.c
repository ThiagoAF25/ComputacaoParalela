#include <stdio.h>

int main() {
int num, j;
  double i;
  printf("Enter the number: ");
  scanf("%d", &num);
  j = num;
  for (i = 1; j > 1; j = j - 1) {
    i = i * (double)j;
  }
  printf("The factorial of %d is %lf\n", num, i);
}
