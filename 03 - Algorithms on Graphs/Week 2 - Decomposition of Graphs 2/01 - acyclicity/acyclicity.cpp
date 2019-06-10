/*
Munir Jojo - Verge
05 / 04 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 2 - Decomposition of Graphs 2
			01 - acyclicity
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

#define NOT_EXPLORED 0
#define BEING_EXPLORED 1
#define FULLY_EXPLORED 2

int explore(vector<vector<int> > &adj, vector<int> &state, int x)
{
	state[x] = BEING_EXPLORED;
	bool IsCycle = false;
	size_t i = 0;
	while ((i < adj[x].size()) && (IsCycle == false))
	{
		if (state[adj[x][i]] == NOT_EXPLORED) // 
			IsCycle = explore(adj, state, adj[x][i]);
		else if (state[adj[x][i]] == BEING_EXPLORED)  // there is a cycle
		{
			IsCycle = true;
		}
		i++;
	}
	state[x] = FULLY_EXPLORED;
	return IsCycle;

}


int acyclic(vector<vector<int> > &adj, int n_vertices, int n_edges) {
  //write your code here
  if (n_vertices == 0 || n_edges == 0)
	  return 0;
  
  // We need to choose the first node with a connection. Not necessarly we will have vertix 0 with a connection!
  bool IsCycle = false;
  size_t i = 0;
  vector<int> state(n_vertices, NOT_EXPLORED); // 0 = Not Explored, 1 = Being Explored, 2 = Fully explored
  
  while ((i < n_vertices) && (IsCycle == false))
  {  
      IsCycle = explore(adj, state, i);
	  i++;
  }
  return IsCycle;
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
  std::cout << acyclic(adj, n, m) << std::endl;
}
