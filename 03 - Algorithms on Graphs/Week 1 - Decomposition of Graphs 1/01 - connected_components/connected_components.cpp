/*
Munir Jojo - Verge
04 / 24 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 1 - Decomposition of Graphs 1
			02 - connected_components
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void explore(vector<vector<int> > &adj, vector<int> &group, int actual_group, int x)
{
	group[x] = actual_group;
	for (size_t i = 0; i < adj[x].size(); i++)
	{
		if (group[adj[x][i]] == 0) // Not visited
			explore(adj, group, actual_group, adj[x][i]);
	}

}

int number_of_components(vector<vector<int> > &adj) {
  
  //write your code here
  /*
  The improtant thing is that with DFS everytime we reach a dead-end or we have visited all vertices, we back step and we can "label" every
  "group" of connected vertices. Once we finish, if x group num is different than y's then, they NOT belong to the same group and that mean they ARE NOT
  CONNECTED or reachable from each other.
  */

  // first we create a Vector to store the "group or set" term and initialize it to 0 (non-visited/ No group)
  int n_vertices = adj.size();
  if (n_vertices == 0)
	  return 0; // If the there is No nodes/vertices, then there is No groups!
  

  vector<int> group(n_vertices, 0);

  // Second: I will implement a recursive funtion
  int group_count = 1; // If there is, at least 1 node/vertix, then there should be at least 1 group
 
  for (size_t i = 0; i < n_vertices; i++)
  {
	  if (group[i] == 0) // Not visited
	  {
		  explore(adj, group, group_count, i); // This will recursively explore all the connected vertices from X. All of them will have the same group number
		  group_count++; // When we get out of the stack from "explore" either we reach a dead-end or we have visited them all. Therefore we can incremet the group, since, if we haven't finish, we will move to a different group
	  }
  }

  return --group_count;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj) << std::endl;
}
