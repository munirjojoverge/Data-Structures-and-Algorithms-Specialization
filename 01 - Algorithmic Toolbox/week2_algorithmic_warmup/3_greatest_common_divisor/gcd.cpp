/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			3_greatest_common_divisor
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_euclid(int a, int b) {
	if (b == 0)
		return a;
	int a_prime = a % b;
	return gcd_euclid(b, a_prime);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // First Let's make sure we pass the values being a the "highest" number.
  if (b > a) {
	  int tmp = a;
	  a = b;
	  b = tmp;
  }
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_euclid(a, b) << std::endl;
  return 0;
}
