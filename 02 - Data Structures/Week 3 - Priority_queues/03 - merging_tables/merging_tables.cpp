/*
Munir Jojo - Verge
04 / 17 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 3 - Priority_queues
			03 - merging_tables
*/

// Only for Visual Studio implementation
//#include "stdafx.h"



#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		// find parent and compress path
		if (table != sets[table].parent) {
			sets[table].parent = getParent(sets[table].parent);
		}
		return sets[table].parent;
	}

	void union_sets(int realDestination, int realSource) {
		if (sets[realSource].rank > sets[realDestination].rank) {
			sets[realDestination].parent = sets[realSource].parent;
			// To be able to update properly the table's sizes we really need to know who's going to be the parent, since it will be the parent the one who gets all the detata.
			//In this case (rank[Dest] > rank[source]) 
			// the parent is the source....so we want to move all data TO DE SOUCE
			int tmp = realSource;
			realSource = realDestination;
			realDestination = tmp;
		}
		else
		{
			sets[realSource].parent = sets[realDestination].parent;
			if (sets[realSource].rank == sets[realDestination].rank)
			{
				sets[sets[realDestination].parent].rank++;
			}
		}
		update_tables(realDestination, realSource);
	}

	void update_tables(int realDestination, int realSource) {
		sets[realDestination].size += sets[realSource].size;
		sets[realSource].size = 0;
		if (this->max_table_size < sets[realDestination].size)
			this->max_table_size = sets[realDestination].size;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
			union_sets(realDestination, realSource);
			// use union by rank heuristic
                        // update max_table_size
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	vector<int> destinations(m), sources(m);

	for (int i = 0; i < m; i++) {
		
		cin >> destinations[i] >> sources[i];
		--destinations[i];
		--sources[i];
	}
	for (int i = 0; i < m; i++) {

			tables.merge(destinations[i], sources[i]);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
