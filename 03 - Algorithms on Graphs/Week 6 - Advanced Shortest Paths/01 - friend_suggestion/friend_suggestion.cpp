/*
Munir Jojo - Verge
07 / 27 / 2018
Coursera
00 - Algorithms and Data Structures
	03 - Algorithms on Graphs
		Week 6 - Advanced Shortest Paths
			01 - friend_suggestion (Bidirectional Dijkstra)
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <functional>

using namespace std;

// External vector (First dim) of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
typedef vector<vector<vector<int>>> Adj;

// Distances can grow out of int type
typedef long long Len;

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
typedef vector<priority_queue<pair<Len, int>,vector<pair<Len,int>>,greater<pair<Len,int>>>> Queue;

const Len MY_INFINITY = numeric_limits<Len>::max() / 4;

class Bidijkstra {
    // Number of nodes
    int n_;

    // Graph adj_[0] and cost_[0] correspond to the initial graph,
    // adj_[1] and cost_[1] correspond to the reversed graph.
    // Graphs are stored as vectors of adjacency lists corresponding
    // to nodes.
    // Adjacency list itself is stored in adj_, and the corresponding
    // edge costs are stored in cost_.
    Adj adj_;
    Adj cost_;

    // distance_[0] stores distances for the forward search,
    // and distance_[1] stores distances for the backward search.
    vector<vector<Len>> distance_;

    // Stores all the nodes visited either by forward or backward search.
    vector<int> workset_; 
	

    // Stores a flag for each node which is True iff the node was visited
    // either by forward or backward search.
    vector<bool> visited_;

public:
    Bidijkstra(int n, Adj adj, Adj cost)
        : n_(n), adj_(adj), cost_(cost), distance_(2, vector<Len>(n, MY_INFINITY)), visited_(n)
    { workset_.reserve(n); }

    // Initialize the data structures before new query,
    // clear the changes made by the previous query.
    void clear() {
        for (size_t i = 0; i < workset_.size(); ++i) {
            int v = workset_[i];
            distance_[0][v] = distance_[1][v] = MY_INFINITY;
            visited_[v] = false;
        }
        workset_.clear();
    }

    // Processes visit of either forward or backward search 
    // (determined by value of side), to node v trying to
    // relax the current distance by dist.
    void visit(Queue& q, int side, int v, Len dist) {
        // Implement this method yourself
		//if (!visited_[v])
		{
			for (size_t i = 0; i < adj_[side][v].size(); i++)
			{
				int u = adj_[side][v][i];

				// Let's Relax this node
				Len new_dist = dist + Len(cost_[side][v][i]);

				if (distance_[side][u] > new_dist)// 
				{
					distance_[side][u] = new_dist;
					q[side].push(make_pair(new_dist, u));
				}
			}
			visited_[v] = true;
			workset_.push_back(v);
		}
    }

    // Returns the distance from s to t in the graph.
    Len query(int s, int t) {
        clear();
		distance_[0][s] = 0.0;
		distance_[1][t] = 0.0;
        Queue q(2);
        visit(q, 0, s, 0.0);
        visit(q, 1, t, 0.0);
        // Implement the rest of the algorithm yourself
		while (!q[0].empty() || !q[1].empty())
		{
			int side, v;

			// 1st Forward move
			if (!q[0].empty())
			{
				side = 0;
				v = q[side].top().second;
				q[side].pop();
				visit(q, side, v, distance_[side][v]);

				if (Processed(v)) // was visited/processed on the opposite direction
					return shortestPath(s, t);
			}
			// 2nd Backward move
			if (!q[1].empty())
			{
				side = 1;
				v = q[side].top().second;
				q[side].pop();
				visit(q, side, v, distance_[side][v]);

				if (Processed(v)) // was visited/processed on the opposite direction
					return shortestPath(s, t);
			}
		}
		return -1;
    }
	
	bool Processed(int v)
	{
		bool result = false;
		auto it = std::find(workset_.begin(), workset_.end(), v);
		if (it != workset_.end())
		{
			result = (std::find(it, workset_.end(), v) != workset_.end());
		}
		return result;
	}

	Len shortestPath(int s, int t) 
	{
		int u_best = -1;
		Len distance = MY_INFINITY;
		for (size_t i = 0; i < workset_.size(); i++)
		{
			int u = workset_[i];
			if (distance_[0][u] + distance_[1][u] < distance)
			{
				u_best = u;
				distance = distance_[0][u] + distance_[1][u];
			}
		}

		return distance;
	}

};

int main() {
    int n, m;
    scanf_s("%d%d", &n, &m);
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for (int i=0; i<m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }

    Bidijkstra bidij(n, adj, cost);

    int t;
    scanf_s("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;
        scanf_s("%d%d", &u, &v);
        printf("%lld\n", bidij.query(u-1, v-1));
    }
}
