/*

The interval bisection method works iff
the function is continuous and you can
establish and initial left & right guess,
such that:
   f(left) and f(right) have differnt signs
(i.e.: both positive or both negative).

COMPILE THIS CODE BY RUNNING:

gcc interval_bisection04_lab.c -lm

The -lm links with the math library

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1 (double x)
{
  double y ;
  y = x*x - 2 ;
  return y ;
}


double f2 (double x)
//  three roots,
//  -3 - sqrt(3) = -4.732050,
//  -3 + sqrt(3) = -1.267949,
//   6
{
  double y ;
  y = x*x*x - 30*x - 36 ;
  return y ;
}



int interval_bisection(double (*f)(double x), // f points at a function with one double input and a double output
		       double left, double right,
		       double epsilon, int maxreps,
		       double results[2])
// return 0 failure, else 'numreps' (>= 1)
// 'maxreps' is the maximum iterations through the loop
{
  // example of a valid function call to f:
  // double fl ;
  // fl = f(left) ;

  // Your algorithm should continue until 'maxreps' iterations have been
  // performed or the difference between guesses is within 'epsilon'

  // YOUR CODE GOES BELOW!!!!!!!!!
  double mid,midValue,leftValue,rightValue;

  // Change left and right if left < right
  if (left > right){
    double tmp = left;
    left = right;
    right = tmp;
  }

  for(int i=0; i < maxreps; i++){
    leftValue = f(left);
    rightValue = f(right);

    //interval midpoint
    mid = (left + right)/2;
    midValue = f(mid);

    if((fabs(left-mid) < epsilon) || (fabs(right-mid) < epsilon)){
        results[0] = mid;
        results[1] = midValue;
        return i;
    }
    if(signbit(leftValue) == signbit(midValue)){
        left = mid;
    }
    else{
        right = mid;
    }
  }
  return 0;
}


int main()
{
  int maxreps,numr ;
  double left_guess,right_guess,res[2] ;

  // test #1:

  left_guess  = 1 ;
  right_guess = 2 ;

  maxreps = 100 ;
  numr = interval_bisection(f1, left_guess,right_guess,  1e-12, maxreps,  res) ;
  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;

    // res[0] is our approximation to a root.
    // res[1] is the function evaluated at res[0],
    // which should be close to 0 if we came close to finding a root.

    // NOTE: numreps equals maxreps, if the algorithm performed maxreps repititions
  }

  //////////////////////////////////////////////////////////////


  // test #2 :

  numr = interval_bisection(sin, 3,4,  1e-12, 50,  res) ;
  // for this test the function is the sin(x)

  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;
  }

  /////////////////////////////////////////////////////////////

  // test #3:

  printf("Enter left,right for root search : ") ;
  scanf("%lf %lf",&left_guess,&right_guess) ;

  maxreps = 100 ;
  numr = interval_bisection(f2, left_guess,right_guess,  1e-12, maxreps,  res) ;

  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;
  }

}
