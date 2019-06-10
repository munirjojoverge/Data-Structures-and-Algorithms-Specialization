/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week5_dynamic_programming1
			4_longest_common_subsequence_of_two_sequences
*/

// Only for Visual Studio implementation
#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
