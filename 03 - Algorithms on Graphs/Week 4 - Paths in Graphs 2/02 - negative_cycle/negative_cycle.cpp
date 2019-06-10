/*
Munir Jojo - Verge
07 / 09 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 4 - Paths in Graphs 2
			02 - negative_cycle
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>

using std::vector;

#define MY_MAX_INT 9999999999

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	// As usial in this type of problems we will start with initializing the "distances" vector

	// 1) Let's initialize the optimal path vector: Distances
	vector<long long int> distances(adj.size(), MY_MAX_INT);

	// 2) For this specific problem we don't need to track previous nodes to trace back the shortest path or the negative cycle. 

	// 3) For convinience, the starting node will be the "first" node
	distances[0] = 0;

	bool relaxed;
	int v = adj.size(); // number of vertices

	for (size_t n = 0; n < v; n++) // We will loop for "num of vertex" times: 1 more than what Bellman-Ford Algo requires
	{
		relaxed = false;
		// No we have to go through all Adjacents pairs
		for (size_t vi = 0; vi < v; vi++)  // We will loop for "num of vertex" times
		{
			for (size_t neig = 0; neig < adj[vi].size(); neig++) // Check the neighbours
			{
				long long int dist = distances[vi] + cost[vi][neig];

				if (dist < distances[adj[vi][neig]])// 
				{
					distances[adj[vi][neig]] = dist;
					relaxed = true;
				}
			}
		}
	}

  return relaxed;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost)<< std::endl;
}
