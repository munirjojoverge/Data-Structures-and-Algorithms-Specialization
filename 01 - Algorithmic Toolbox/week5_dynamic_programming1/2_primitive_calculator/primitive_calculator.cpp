/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week5_dynamic_programming1
			2_primitive_calculator
*/

// Only for Visual Studio implementation
//#include "stdafx.h"



#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using namespace std;



vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_dp(int n) {
	
	std::vector<int> min_ops(n+1);
	min_ops[0] = 0;
	min_ops[1] = 0;

	std::vector<int> best_parent(n + 1); // kinda sequence
	best_parent[0] = 0;
	best_parent[1] = 0;

	for (size_t i = 2; i <= n; i++)
	{
		int Num_ops;
		
		//min_ops[i] = MY_INT32_MAX;
		// We can ALWAYS substract 1, so we can simply disregard the "if (Num_ops < min_ops[i])" since if I initialize
		// min_ops[i] = MY_INT32_MAX then it will always the if will be true.

		Num_ops = min_ops[i - 1] + 1;
		//if (Num_ops < min_ops[i]) {
			min_ops[i] = Num_ops;
			best_parent[i] = int(i - 1);
		//}

		if (i % 3 == 0) {
			Num_ops = min_ops[int(i / 3)] + 1;
			if (Num_ops < min_ops[i]) {
				min_ops[i] = Num_ops;
				best_parent[i] = int(i / 3);
			}

		}

		if (i % 2 == 0) {
			Num_ops = min_ops[int(i / 2)] + 1;
			if (Num_ops < min_ops[i]) {
				min_ops[i] = Num_ops;
				best_parent[i] = int(i / 2);
			}
		}
		
	}

	// Generate the sequence!!! :-( 
	std::vector<int> sequence;
	sequence.push_back(n);
	int idx = n;
	while (best_parent[idx] > 0)
	{
		sequence.push_back(best_parent[idx]);
		idx = best_parent[idx];
	}
	//sequence.push_back(1);

	reverse(sequence.begin(), sequence.end());
	
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
