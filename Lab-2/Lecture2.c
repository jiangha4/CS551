#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f (double x)
{
  double y;
  y = x*x*x - 30*x - 36;
  return y ;
}

double f_prime(double x)
{
  double y;
  y = 3*x*x - 30;
  return y;
}


// implement fixed point iteration
int main()
{
  double guess,value,d_value;

  printf("Enter guess for root search : ");
  scanf("%lf",&guess);

  for(int i=0;i<20;i++){
    value = f(guess);
    d_value = f_prime(guess);

    guess = guess - (value/d_value);

    printf("X value: %.17lf, Y value: %.17lf\n",guess,value);
    printf("New guess: %.17lf\n",guess);
  }

  return 0;
}
