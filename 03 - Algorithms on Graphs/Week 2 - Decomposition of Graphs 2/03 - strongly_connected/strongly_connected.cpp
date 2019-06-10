/*
Munir Jojo - Verge
05 / 04 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 2 - Decomposition of Graphs 2
			03 - strongly_connected
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
