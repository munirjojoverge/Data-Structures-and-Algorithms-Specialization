/*
Munir Jojo - Verge
04 / 24 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 1 - Decomposition of Graphs 1
			01 - Reachability
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

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  /* The idea is to answer the question: Can we reach Y from X (or viceversa, since this is an UNdirected graph
  To answer this question we can use actually Depth First Search (DFS).
  The main improtant thing is that with DFS everytime we reach a dead-end or we have visited all vertices, we back step and we can "label" every
  "group" of connected vertices. Once we finish, if x group num is different than y's then, they NOT belong to the same group and that mean they ARE NOT
  CONNECTED or reachable from each other.
  */

  // first we create a Vector to store the "group or set" term and initialize it to 0 (non-visited/ No group)
	int n_vertices = adj.size();
	vector<int> group(n_vertices, 0);

	// Second: I will implement a recursive funtion
	int actual_group = 1;
	
	explore(adj, group, actual_group, x); // This will recursively explore all the connected vertices from X. All of them will have the same group number
	actual_group ++; // When we get out of the stack from "explore" either we reach a dead-end or we have visited them all. Therefore we can incremet the group, since, if we haven't finish, we will move to a different group

	/* In reality if we start with node/vertix X, we know that when we finish "explotring", we have already 
	gone through all the nodes that are reachable from x. We don't need to keep going. We just need to return
	true of false if X and Y have the same group.

	*/
	return (group[x] == group[y]);
	
	
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) << std::endl;
}
