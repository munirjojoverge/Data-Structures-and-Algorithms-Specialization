/*
Munir Jojo - Verge
04 / 09 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week4_divide_and_conquer
			2_majority_element
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	/*
	My initial thought is that since I cannot use the "counting" technique used for sorting since we have 10^9 possibilities
	we can stil use quick sort (N log N) and later loop over all the ordered items and count them. Every time the element is different
	is because I jumped to a new element. At any point when the count is > n/2 return n. This last loop is O(n) and therefore the 
	whole approach is: O() = O(n log n) + O(n) and theerefore this should be O(n log n)
	*/
	std::sort(a.begin(), a.end());

	int element = a[0];
	int count = 1;
	int mayority = int(a.size() / 2);
	for (size_t i = 1; (i < a.size() && count <= mayority) ; i++)
	{
		if (a[i] == element)
			count++;
		else
		{
			element = a[i];
			count = 1;
		}
	}
	return (count > mayority);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
