/*
Munir Jojo - Verge
04 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			2_maximum_value_of_the_loot
*/

// Only for Visual Studio implementation
//#include <stdafx.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define EPSILON  0.001

using std::vector;
using namespace std;


int find_most_valuable_idx(int n, std::vector<double> weights, vector<double> unit_values)
{
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (weights[i] > EPSILON) {// Some weight left
			if (unit_values[i] > unit_values[index]) 
				index = i;
		}
	}
	return index;
}

double get_optimal_value(double capacity, vector<double> values, vector<double> weights) 
{
	double value = 0.0;
	int n = values.size();

	// **********************
	auto cmp = [](pair<int, double> left, pair<int, double> right){ return (left.second) < (right.second); };
	priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> unit_values(cmp);

	for (int i = 0; i < n; i++) {
		if (weights[i] < EPSILON) // Avoid Division by Zero
			unit_values.push(make_pair(i, 0.0));
		else
		{
			unit_values.push(make_pair(i, (values[i] / weights[i])));
		}

	}
	// **********************
	
	for (size_t i = 0; i < n; i++)
	{
		if (capacity == 0)
			return value;
		// Find the most valuable item.
		//int idx_max = find_most_valuable_idx(n, weights, unit_values);
		int idx_max = unit_values.top().first;
		double max_unit_val = unit_values.top().second;
		unit_values.pop();
		
		double item_qty = std::min(capacity, weights[idx_max]);
		value = value + (item_qty * max_unit_val);
		weights[idx_max] -= item_qty;
		capacity -= item_qty;
	}

	return value;
}

int main() {
  int n;
  double capacity;
  std::cout<<"Enter the number n of items and the capacity W of the knapsack:";
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);

  
  for (int i = 0; i < n; i++) {
	std::cout<<"Enter the value and the weight available for item " << i+1 << ": ";  
    std::cin >> values[i] >> weights[i];	
	std::cout<<endl;
  }

  double optimal_value = get_optimal_value(capacity, values, weights);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
