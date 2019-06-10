/*
Munir Jojo - Verge
04 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			5_maximum_number_of_prizes
*/

// Only for Visual Studio implementation
//#include "stdafx.h"



#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int total_candies = 0;
  for (int k = 1; total_candies + k <= n; k++)
  {
	  summands.push_back(k);
	  total_candies += k;

  }
  int last = summands.size() - 1;
  summands[last] = summands[last] + (n - total_candies);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
