/*
Munir Jojo - Verge
07 / 27 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 5 - Minimum Spanning Trees
			01 - connecting_points
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>

using std::vector;
using namespace std;

#define MY_MAX_INT 9999999999

double minimum_distance(vector<int> x, vector<int> y) {
  /*
  I will start implementing Prim’s Algorithm and later I will implement Kruskal’s Algorithm
  to be able to compare performance by creating several input cases
  */
  double result = 0.0;
  //write your code here

  int num_vertex = x.size();

  // 1) Let's initialize the optimal cost vector "cost" that will contain the min cost to reach vertex V.
  vector<double> cost(num_vertex, MY_MAX_INT);

  // 2) Let's initialize the parents vector "parent" that will contain the ONLY parent to reach vertex V.
  //vector<int> parent(num_vertex, -1);

  // 3) Let's use a Priority Queue that will:
  //  a) map node/vertex/pair of points with its optimal cost. So we will store pairs such: <node, cost[Node]>
  //  b) order this queue with lowest cost on top.
  // Using lambda to compare elements.
  auto cmp = [](pair<int, double> left, pair<int, double> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
  priority_queue<pair<int, double>, std::vector<pair<int, double>>, decltype(cmp)> my_queue(cmp);
  /*
  Due to the characteristics of the Priority_queue, it is difficult to "find" and "update" terms, therefore,
  we better simply ADD new terms that wil be pushed to the top. So basically we will have a "history" of how nodes get better cost as we iterate.
  To avoid going through the elements that have been added twice, we will use a "visited" vector to pop from the queue and not re-do all
  calculations
  */
  vector<bool> visited(num_vertex, false);

  
 
  // 4) Lets pick any initial vertex u0 and initialize its cost to 0
  cost[0] = 0.0;
  my_queue.push(make_pair(0, cost[0]));

  while (!my_queue.empty())
  {
	  int vertex_idx = my_queue.top().first;
	  //double vertex_cost = my_queue.top().second;
	  my_queue.pop();

	  if (visited[vertex_idx] == false)
	  {
		  for (size_t i = 0; i < num_vertex; i++)
		  {

			  if ((vertex_idx != i) && (visited[i] == false)) // Make sure we don't calculate the distance between the vertex and itself
			  {
				  double x_dist = x[vertex_idx] - x[i];
				  double y_dist = y[vertex_idx] - y[i];

				  double euclidean_distance = sqrt((x_dist*x_dist) + (y_dist*y_dist));
				  double new_cost = euclidean_distance;

				  if (cost[i] > new_cost)// 
				  {
					  cost[i] = new_cost;
					  //parent[i] = vertex_idx;
					  my_queue.push(make_pair(i, cost[i]));
				  }
			  }

		  }
		  visited[vertex_idx] = true;
	  }
  }
  // At this point we have all the min costs calculated. We just need to loop over them and calulate the total cost to connect this verteces.
  //return result = std::accumulate(cost.begin(), cost.end(), 0);
  for (auto i = 0; i < cost.size(); i++) {
	  result += cost[i];
  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
