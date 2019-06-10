/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week6_dynamic_programming2
			2_partitioning_souvenirs

			Partitioning Souvenirs
			You and two of your friends have just returned back home after visiting various countries. Now you would
			like to evenly split all the souvenirs that all three of you bought.
			Problem Description
			Input Format. The first line contains an integer 𝑛. The second line contains integers 𝑣1, 𝑣2, . . . , 𝑣𝑛 separated
			by spaces.
			Constraints. 1 ≤ 𝑛 ≤ 20, 1 ≤ 𝑣𝑖 ≤ 30 for all 𝑖.
			Output Format. Output 1, if it possible to partition 𝑣1, 𝑣2, . . . , 𝑣𝑛 into three subsets with equal sums, and
			0 otherwise.
			Sample 1.
			Input:
			4
			3 3 3 3
			Output:
			0
			Sample 2.
			Input:
			1
			40
			Output:
			0
			Sample 3.
			Input:
			11
			17 59 34 57 17 23 67 1 18 2 59
			Output:
			1
			34 + 67 + 17 = 23 + 59 + 1 + 17 + 18 = 59 + 2 + 57.
			Sample 4.
			Input:
			13
			1 2 3 4 5 5 7 7 8 10 12 19 25
			Output:
			1
			1 + 3 + 7 + 25 = 2 + 4 + 5 + 7 + 8 + 10 = 5 + 12 + 19.
			
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using std::vector;
using namespace std;

bool isSubsetSum(vector<int> &wi, int n, int sum)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;

	// If last element is greater than sum, then 
	// ignore it
	if (wi[n - 1] > sum)
		return isSubsetSum(wi, n - 1, sum);

	/* else, check if sum can be obtained by any of
	the following
	(a) including the last element
	(b) excluding the last element
	*/
	return isSubsetSum(wi, n - 1, sum) ||
		   isSubsetSum(wi, n - 1, sum - wi[n - 1]);
}

int partition3(vector<int> &wi) {
	
	int W = std::accumulate(wi.begin(), wi.end(), 0);
	if (W % 3 > 0) return 0;

    return isSubsetSum(wi, wi.size(), W / 3);;
}

int optimal_souvenirs_partition_dp(int w, int i, vector<int> &wi, vector<vector<int>> &opt_value, vector<vector<bool>> &calculated) {

	if (calculated[w][i]) return opt_value[w][i];
	/* If there is an optimal solution and we can find a combination that actually partitions the 
	 souvenirs in 3 part of equal value, than means:
	 val_p1 = val_p2 = val_p3
	 and since we have to use all the souvenirs that also means:
	 val_p1 + val_p2 + val_p3 = 3*val= TotalVal
	 Thereore and MUST condition for an optical solution to exist is that Total Value is Divisible by 3
	*/
	if ((w % 3 > 0) || (w < 3) || (i < 3)) return 0;
		
	/*possibility 1: item i was already used, therefore we can not use it in an Optimal solution without repetition.
	that means that the optimal opt_value for weight w using items from 1 to i MUST be exactly the same as w for items 1 i-1
	since we are not allwed to re-use i
	*/
	int val_pos1 = optimal_souvenirs_partition_dp(w, i - 1, wi, opt_value, calculated);
		//opt_value[w][i - 1];

	/* possibility 2: the optimal solution uses element i and therefore we are coming from a previous optimal solution
	for a weight w-wi (before we added element i) and using items 1 to i-1.
	Note: The opt_value of item i is actually wi since all the items have the same opt_value per unit of weight,
	for a simple reasons: they are all made of gold. \
	For this reason I will assume unit_value = 1, therefore Value of i = Unit_Value * wweight of i = 1*w1 = w1
	NOTE: remember that wi (items weights vector) index starts at 0 and that we decided to initialize opt_val first (0) col & row
	with zeros. So col and row 1 will actually refer to the item 0.
	*/
	int val_pos2 = 0;
	if (w >= wi[i - 1]) { // make sure we have weigh avilable for this item since we can not partition the elements.
		val_pos2 = ((optimal_souvenirs_partition_dp(w - wi[i - 1], i, wi, opt_value, calculated) + wi[i - 1]) % 3 == 0);
			//opt_value[w - wi[i - 1]][i - 1] + wi[i - 1];
	}

	// Now for an optimal solution where we pick the biggest opt_value we just pick the max between this 2 values:
	opt_value[w][i] = (val_pos1 || val_pos2);
	calculated[w][i] = true;
	

	// After we finish both loops we would have calculated the optimal value for weight W using items from 1 to i (last combination of the loop)
	// which is the value that we are interested in.
	return opt_value[w][wi.size()];
}

int main2() {
  int n;
  std::cin >> n;
  vector<int> wi(n);
  for (size_t i = 0; i < wi.size(); ++i) {
    std::cin >> wi[i];
  }

  int W = std::accumulate(wi.begin(), wi.end(), 0);

  // First define a 2D vector where I will store the "optimal" opt_value of the subproblem (knapsack) of weigh (w) and items 1 to i
  // opt_value[w][i];
  vector<vector<int>> opt_value(W + 1, vector<int>(wi.size() + 1));
  vector<vector<bool>> calculated(W + 1, vector<bool>(wi.size() + 1));

  // Let's initialize the first Column and Row since we know they are values at "0"
  // Explanation: 
  //      the Value[W][0] is zero since there are NO items to use to fill the knapsack
  //      the Value[0][i] is zero since there is NO weight/capacity available.
  for (size_t i = 0; i < W + 1; i++)
  {
	  opt_value[i][0] = 0;
	  calculated[i][0] = 1; // Calc
  }
  for (size_t j = 0; j < wi.size() + 1; j++)
  {
	  opt_value[0][j] = 0;
	  calculated[0][j] = 1;
  }

  std::cout << optimal_souvenirs_partition_dp(W, n, wi,opt_value, calculated) << '\n';

  return 0;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> wi(n);
	for (size_t i = 0; i < wi.size(); ++i) {
		std::cin >> wi[i];
	}

	std::cout << partition3(wi) << '\n';
}
