/*
Munir Jojo - Verge
05 / 04 / 2018
Coursera
00 - Algorithms and Data Structures
03 - Algorithms on Graphs
	Week 3 - Paths in Graphs 1
		01 - BFS
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;
#define MY_MAX_INT 999999

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
	
	vector<int> distances(adj.size(), -1);
	std::queue<int> my_queue;
	distances[s] = 0;
	my_queue.push(s);
	
	while (!my_queue.empty())
	{
		int actual_vertix = my_queue.front();
		my_queue.pop();

		if (actual_vertix == t)
			return distances[actual_vertix];

		for (size_t i = 0; i < adj[actual_vertix].size(); i++)
		{
			if (distances[adj[actual_vertix][i]] == -1) // If neighbour NOT visited/explored
			{
				distances[adj[actual_vertix][i]] = distances[actual_vertix] + 1;
				my_queue.push(adj[actual_vertix][i]);
			}
		}
	}
	
  return distances[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t) << std::endl;
}
