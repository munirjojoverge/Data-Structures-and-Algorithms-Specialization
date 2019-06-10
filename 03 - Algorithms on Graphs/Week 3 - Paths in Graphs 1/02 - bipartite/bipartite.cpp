/*
Munir Jojo - Verge
05 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
	Week 3 - Paths in Graphs 1
		02 - bipartite
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
   //write your code here
	vector<bool> team(adj.size(), false); // Team or Party A = 0, and Team/Party B = 1
	vector<bool> visited(adj.size(), false);
	std::queue<int> my_queue;

	team[0] = 0;
	my_queue.push(0);
	while (!my_queue.empty())
	{
		int actual_vertex = my_queue.front();
		my_queue.pop();
		visited[actual_vertex] = true;

		for (size_t i = 0; i < adj[actual_vertex].size(); i++)
		{
			if (!visited[adj[actual_vertex][i]])
			{
				team[adj[actual_vertex][i]] = !team[actual_vertex];
				my_queue.push(adj[actual_vertex][i]);
			}
			else
			{
				if (team[adj[actual_vertex][i]] == team[actual_vertex])
				{
					return 0;
				}
			}
		}
	}
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj) << std::endl;
}
