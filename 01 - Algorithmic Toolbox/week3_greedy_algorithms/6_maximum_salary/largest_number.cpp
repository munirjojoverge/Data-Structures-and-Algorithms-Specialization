/*
Munir Jojo - Verge
04 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			6_maximum_salary
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool IsGreaterOrEqual(const string s, const string maxDigit) {
	string concat1 = s + maxDigit;
	string concat2 = maxDigit + s;

	return (concat1.compare(concat2) >= 0);
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  while (!a.empty()) {
	  int maxDigit_idx = 0;
	  for (int i = 1; i < a.size(); i++)
	  {
		  if (IsGreaterOrEqual(a[i], a[maxDigit_idx]))
			  maxDigit_idx = i;
	  }
	  ret << a[maxDigit_idx];
	  a.erase(a.begin() + maxDigit_idx, a.begin() + maxDigit_idx + 1);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
 
  std::cout << largest_number(a) << std::endl;
}
