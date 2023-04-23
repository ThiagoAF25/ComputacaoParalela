#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x){
    return exp(x);
}

void Trap(double a, double b, int n){
  double h, approx = 0.0, x_i;
  h = (b-a)/n;
  approx = (f(a)+f(b))/2.0;
  for(int i=1; i<=n-1; i++){
    x_i = a + i* h;
    approx += f(x_i);
  }
  approx = h*approx;
  printf("With n = %d trapezoids, our estimate\n", n);
  printf("of the integral from %f to %f = %.14e\n", a, b, approx);
}

int main(){
    double a,b;
    int n;
    a = 0;
    b = 100;
    n = 1000000000; // 1 bilhao
    //printf("Enter a,b and n\n");
    //scanf("%lf %lf %d",&a, &b,&n);
    Trap(a,b,n);

    return 0;
}



