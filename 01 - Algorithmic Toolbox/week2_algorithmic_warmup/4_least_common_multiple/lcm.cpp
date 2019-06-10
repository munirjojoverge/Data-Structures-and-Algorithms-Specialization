/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			4_least_common_multiple
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>

long long lcm_naive(unsigned int a, unsigned int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (a * b);
}

/*
			   a * b
LCM (a, b) = ----------
			 GCD (a, b)
*/
long long int gcd_euclid(long long int a, long long int b) {
	if (b == 0)
		return a;
	long long int a_prime = a % b;
	return gcd_euclid(b, a_prime);
}

long long int lcm_opt(long long int a, long long int b) {
	long long int lcm = (a * b) / gcd_euclid(a, b);
	return lcm;
}



int main() {
  long long a, b;
  std::cin >> a >> b;
  // First Let's make sure we pass the values being a the "highest" number.
  if (b > a) {
	  long long tmp = a;
	  a = b;
	  b = tmp;
  }
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_opt(a, b) << std::endl;
  return 0;
}
