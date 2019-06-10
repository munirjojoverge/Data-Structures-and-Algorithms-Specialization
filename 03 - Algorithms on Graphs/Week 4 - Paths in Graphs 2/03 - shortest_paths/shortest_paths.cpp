/*
Munir Jojo - Verge
07 / 09 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 4 - Paths in Graphs 2
			03 - shortest_paths
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int dijkstra(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
	//write your code her

	// 1) Let's initialize the optimal path vector: Distances
	vector<long long> distances(adj.size(), std::numeric_limits<long long>::max());

	// For this specific problem we don't need to track previous nodes to trace back the shortest path. 

	// Let's use a Priority Queue that will:
	//	a) map node with its optimal distance. So we will store pairs such: <node, Distance[Node]>
	//  b) order this queue with shotest diatance on top.
	// Using lambda to compare elements.
	auto cmp = [](pair<int, long long int> left, pair<int, long long int> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
	std::priority_queue<pair<int, long long int>, std::vector<pair<int, long long int>>, decltype(cmp)> my_queue(cmp);
	/*
	Due to the characteristics of the Priority_queue, it is difficult to "find" and "update" terms, therefore,
	we better simply ADD new terms that will be pushed to the top. So basically we will have a "history" of how nodes get better distances as we iterate.
	*/

	distances[s] = 0;
	my_queue.push(make_pair(s, distances[0]));

	while (!my_queue.empty())
	{
		int actual_vertix = my_queue.top().first;
		int vertix_dist = my_queue.top().second;
		my_queue.pop();

		for (size_t i = 0; i < adj[actual_vertix].size(); i++)
		{

			int dist = distances[actual_vertix] + cost[actual_vertix][i];

			if (distances[adj[actual_vertix][i]] > dist)// 
			{
				distances[adj[actual_vertix][i]] = dist;
				my_queue.push(make_pair(adj[actual_vertix][i], dist));
			}

		}

	}
	return ((distances[t] < std::numeric_limits<long long>::max()) ? distances[t] : -1);
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance) {
	//write your code here

	//For this specific problem we don't need to track previous nodes to trace back the shortest path or the negative cycle. 

	distance[s] = 0;

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
				long long int dist = distance[vi] + cost[vi][neig];

				if (dist < distance[adj[vi][neig]])// 
				{
					distance[adj[vi][neig]] = dist;
					relaxed = true;
				}
			}
		}
	}

	return relaxed;
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  // Let's start by checking if there is any Negatie Cycle on the graph. If there is, at least one, we know
  // the shortest distance is -inf and therefore we must resturn "-",
	int n = adj.size();
	for (int i = 0; i < n; i++)
	{
		if ()
	}
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  /*
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
  */
  for (int i = 0; i < n; i++) 
  {
	  if (distance[i] == std::numeric_limits<long long>::max()) {
		  std::cout << "*\n";
	  }
	  else if (!shortest[i]) {
		  std::cout << "-\n";
	  }
	  else {
		  std::cout << distance[i] << "\n";
	  }
  }
}
