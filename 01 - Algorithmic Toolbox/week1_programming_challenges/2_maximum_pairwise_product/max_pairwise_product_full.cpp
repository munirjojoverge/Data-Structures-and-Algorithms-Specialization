/*
Munir Jojo-Verge
04/06/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week1_programming_challenges
			2_maximum_pairwise_product
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;
using namespace std::chrono;
//using std::vector;
//using std::cin;
//using std::cout;

long long MaxPairwiseProductNaive(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        result = max(result, (long long)(numbers[i]) * numbers[j]);
    }
  }
  return result;
}

long long MaxPairwiseProductOpt1(vector<int>& numbers) {
	
	int idx_max = std::distance(numbers.begin(), std::max_element(numbers.begin(), numbers.end()));
	int max1 = numbers[idx_max];
	numbers[idx_max] = 0;
	idx_max = std::distance(numbers.begin(), std::max_element(numbers.begin(), numbers.end()));
	int max2 = numbers[idx_max];

	return (long long)(max1)*max2;
}

long long MaxPairwiseProductOpt2(vector<int>& numbers) {
	int n = numbers.size();
	std::sort(numbers.begin(), numbers.end());
	/*
	for (auto a : numbers) {
		std::cout << a << " ";
	}
	std::cout << '\n';
	*/
	return (long long)(numbers[n - 1]) * numbers[n - 2];
}

int Random_n() {
	//int random_number = std::experimental::randint(100, 999);
	//return 2 + std::rand() / ((RAND_MAX + 2u) / 200000);
	return 2 + std::rand() % (90000-2); // ((RAND_MAX + 2u) / 200000);
}

void Random_values(const int n, vector<int>& numbers) {

	int i = 0;
	while (i < n) {
		numbers.push_back(Random_n());
		i++;	
	}
}

int Manual_n() {
	int n;
	cout << "Step 1: Please enter the number (n) of positive integers you will be inputing. This number must follow the rule: n>=2 and n<=2*10^5: ";

	cin >> n;
	while ((n < 2) || (n > 200000))
	{
		cout << "The number you entered does not follow the rule! Try again, please \n";
		cin >> n;
	}
	return n;
}

void Manual_values(const int n, vector<int>& numbers) {

	cout << "Step 2: Please enter " << n << " positive integers. These numbers must follow the rule: your_number>=0 and your_number<=2*10^5 \n";

	int i = 0;
	int num;
	while (i < n) {
		cout << i + 1 << ": ";
		cin >> num;
		if ((num < 0) || (num > 200000))
		{
			cout << "The number you entered does not follow the rule!. Try again, please. \n";
		}
		else
		{
			numbers.push_back(num);
			i++;
		}
	}
}
/*
int main() {

	// Number of integers
	int n;
	// Values
	vector<int> numbers;

	cout << "Generate Random data? [Y/N]: ";
	char Random;
	cin >> Random;
	switch (Random)
	{
	case 'Y': 
		{
			std::srand(std::time(nullptr)); // use current time as seed for random generator	
			n = Random_n();
			Random_values(n, numbers);
			break;
		}
	default:
		{
			n = Manual_n();
			Manual_values(n, numbers);
			break;
		}
	}
	
    
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	long duration;
 	/*
	//---------- Naive Solution ---------------
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
    long long result_naive= MaxPairwiseProductNaive(numbers);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	cout << "Max Pairwise Product - Naive: " << result_naive;
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	cout << " duration: " << duration << "\n";
	
	//---------- Optimal Solution 2 ---------------
	t1 = high_resolution_clock::now();
	long long result_opt2 = MaxPairwiseProductOpt2(numbers);
	t2 = high_resolution_clock::now();

	cout << "Max Pairwise Product - Optimal 2: " << result_opt2;
	duration = duration_cast<microseconds>(t2 - t1).count();
	cout << " duration: " << duration << "\n";

	//---------- Optimal Solution 1 ---------------
	t1 = high_resolution_clock::now();
	long long result_opt1 = MaxPairwiseProductOpt1(numbers);
	t2 = high_resolution_clock::now();

	cout << "Max Pairwise Product - Optimal 1: " << result_opt1;
	duration = duration_cast<microseconds>(t2 - t1).count();
	cout << " duration: " << duration << "\n";

	

	cin;
    return 0;
}
*/

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	long long result = MaxPairwiseProductOpt1(numbers);
	cout << result << "\n";
	return 0;
}

