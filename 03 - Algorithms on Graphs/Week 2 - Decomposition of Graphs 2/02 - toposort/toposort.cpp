/*
Munir Jojo - Verge
05 / 04 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 2 - Decomposition of Graphs 2
			02 - Topological Sort
*/

// Only for Visual Studio implementation


//#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

#define NOT_EXPLORED 0
#define BEING_EXPLORED 1
#define USED 2

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
	if (used[x] == USED)
		return;
	
	used[x] = BEING_EXPLORED;
	
	for (size_t i = 0; i < adj[x].size(); i++)
	{
		dfs(adj, used, order, adj[x][i]);
	}

	order.push_back(x);
	used[x] = USED;
	return;


}     

vector<int> toposort(vector<vector<int> > adj) {
	int n_vertices = adj.size();
  vector<int> used(n_vertices, NOT_EXPLORED);
  vector<int> order;
  //write your code here
  for (size_t i = 0; i < n_vertices; i++)
  {
	  dfs(adj, used, order, i);

  }

  return order;
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
  vector<int> order = toposort(adj);
  for (int i = order.size()-1; i >= 0; --i) {
    std::cout << order[i] + 1 << " ";
  }
  std::cout << std::endl;
}
