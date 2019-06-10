/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week6_dynamic_programming2
			1_maximum_amount_of_gold

			Problem Introduction
			You are given a set of bars of gold and your goal is to take as much gold as possible into
			your bag. There is just one copy of each bar and for each bar you can either take it or not
			(hence you cannot take a fraction of a bar).
			Problem Description
			Task. Given 𝑛 gold bars, find the maximum weight of gold that fits into a bag of capacity 𝑊.
			Input Format. The first line of the input contains the capacity 𝑊 of a knapsack and the number 𝑛 of bars
			of gold. The next line contains 𝑛 integers 𝑤0,𝑤1, . . . ,𝑤𝑛−1 defining the weights of the bars of gold.
			Constraints. 1 ≤ 𝑊 ≤ 10^4; 1 ≤ 𝑛 ≤ 300; 0 ≤ 𝑤0, . . . ,𝑤𝑛−1 ≤ 10^5.
			Output Format. Output the maximum weight of gold that fits into a knapsack of capacity 𝑊.
			Sample 1.
			Input:
			10 3
			1 4 8
			Output:
			9
			Here, the sum of the weights of the first and the last bar is equal to 9.
			Starter Files
			Starter files contain an implementation of the following greedy strategy: scan the list of given bars of gold
			and add the current bar if it fits into the current capacity (note that, in this problem, all the items have the
			same value per unit of weight, for a simple reasons: they are all made of gold). As you already know from
			the lectures, such a greedy move is not safe. You may want to additionally submit a starter file as a solution
			to the grading system to ensure that this greedy algorithm indeed might produce a non-optimal result.
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>

using std::vector;

int optimal_weight_naive(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &wi) {
	//write your code here
	// First define a 2D vector where I will store the "optimal" opt_value of the subproblem (knapsack) of weigh (w) and items 1 to i
	// opt_value[w][i];
	vector<vector<int>> opt_value(W + 1, vector<int>(wi.size() + 1));

	// Let's initialize the first Column and Row since we know they are values at "0"
	// Explanation: 
	//      the Value[W][0] is zero since there are NO items to use to fill the knapsack
	//      the Value[0][i] is zero since there is NO weight/capacity available.
	for (size_t i = 0; i < W+1; i++)
	{
		opt_value[i][0] = 0;
	}
	for (size_t j = 0; j < wi.size() + 1; j++)
	{
		opt_value[0][j] = 0;
	}

	// Let's now Fill in the Value 2D vector.
	for (size_t i = 1; i < wi.size() + 1; i++) {
		for (size_t w = 1; w < W + 1; w++)
		{
			/*possibility 1: item i was already used, therefore we can not use it in an Optimal solution without repetition.
			that means that the optimal opt_value for weight w using items from 1 to i MUST be exactly the same as w for items 1 i-1
			since we are not allwed to re-use i
			*/
			int val_pos1 = opt_value[w][i - 1];

			/* possibility 2: the optimal solution uses element i and therefore we are coming from a previous optimal solution
			for a weight w-wi (before we added element i) and using items 1 to i-1.
			Note: The opt_value of item i is actually wi since all the items have the same opt_value per unit of weight,
			for a simple reasons: they are all made of gold. \
			For this reason I will assume unit_value = 1, therefore Value of i = Unit_Value * wweight of i = 1*w1 = w1
			NOTE: remember that wi (items weights vector) index starts at 0 and that we decided to initialize opt_val first (0) col & row
			with zeros. So col and row 1 will actually refer to the item 0. 
			*/
			int val_pos2 = 0;
			if (w >= wi[i-1]) { // make sure we have weigh avilable for this item since we can not partition the elements.
				val_pos2 = opt_value[w - wi[i-1]][i - 1] + wi[i-1];
			}

			// Now for an optimal solution where we pick the biggest opt_value we just pick the max between this 2 values:
			opt_value[w][i] = (val_pos1 > val_pos2) ? val_pos1 : val_pos2;

		}
	}
	
	// After we finish both loops we would have calculated the optimal value for weight W using items from 1 to i (last combination of the loop)
	// which is the value that we are interested in.
	return opt_value[W][wi.size()];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> wi(n);
  for (int i = 0; i < n; i++) {
    std::cin >> wi[i];
  }
  std::cout << optimal_weight_dp(W, wi) << '\n';
}
