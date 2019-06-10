/*
Munir Jojo - Verge
05 / 04 / 2018
07 / 09 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 4 - Paths in Graphs 2
			01 - Dijkstra
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;

#define MY_MAX_INT 9999999999

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
	// 1) Let's initialize the optimal path vector: Distances
	vector<long long int> distances(adj.size(), MY_MAX_INT);

	// 2) For this specific problem we don't need to track previous nodes to trace back the shortest path. 

	// 3) Let's use a Priority Queue that will:
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
	my_queue.push(make_pair(s,distances[0]));

	while (!my_queue.empty())
	{
		int vertex_idx = my_queue.top().first;
		int vertex_cost = my_queue.top().second;
		my_queue.pop();

		for (size_t i = 0; i < adj[vertex_idx].size(); i++)
		{

			int dist = distances[vertex_idx] + cost[vertex_idx][i];

			if (distances[adj[vertex_idx][i]] > dist)// 
			{
				distances[adj[vertex_idx][i]] = dist;
				my_queue.push(make_pair(adj[vertex_idx][i], dist));
			}

		}
		
	}
	return ((distances[t] < MY_MAX_INT) ? distances[t]: -1);
	//return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t) << std::endl;
}
