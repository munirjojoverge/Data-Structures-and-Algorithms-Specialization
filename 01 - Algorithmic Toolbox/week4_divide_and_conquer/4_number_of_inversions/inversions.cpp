/*
Munir Jojo - Verge
04 / 10 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week4_divide_and_conquer
			4_number_of_inversions
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>

using std::vector;

vector<int> merge_and_count_inversions(vector<int> &a, vector<int> &b, long long &number_of_inversions) {
	int D_size = a.size() + b.size();
	vector<int> D(D_size);
	size_t D_i = 0;
	while(!a.empty() && !b.empty())
	{
		if (a[0] <= b[0]) {
			D[D_i] = a[0];
			a.erase(a.begin());
			D_i++;
		}
		else {
			D[D_i] = b[0];
			b.erase(b.begin());
			D_i++;
			number_of_inversions++;
		}
	}
	D_i++;
	if (a.empty()) {
		for (size_t i = 0; (i < b.size() && D_i < D_size); i++, D_i++)
		{
			D[D_i] = b[i];
		}
	}
	if (b.empty()) {
		for (size_t i = 0; (i < a.size() && D_i < D_size); i++, D_i++)
		{
			D[D_i] = a[i];
		}
	}
	return D;
}

long long count_inversions(vector<int> &B, vector<int> &C) {
	long long number_of_inversions = 0;
	for (size_t i = 0; i < B.size(); i++)
	{
		for (size_t j = 0; j < C.size(); j++)
		{
			if (B[i] > C[j]) 
				number_of_inversions++;
		}
	}

	return number_of_inversions;
}

long long get_number_of_inversions2(vector<int> &a) {
  long long number_of_inversions = 0;
  if (a.size()==1) return number_of_inversions;
  size_t half = size_t(a.size() / 2) - 1;

  vector<int> B;
  B.insert(B.begin(), a.begin(), a.begin() + half + 1);

  vector<int> C;
  C.insert(C.begin(), a.begin() + half + 1, a.end());

  number_of_inversions += get_number_of_inversions2(B);
  number_of_inversions += get_number_of_inversions2(C);

  //write your code here
  number_of_inversions += count_inversions(B, C);

  return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t half = size_t(left + (right - left) / 2);

	vector<int> B;
	B.insert(B.begin(), a.begin() + left, a.begin() + half);

	vector<int> C;
	C.insert(C.begin(), a.begin() + half + 1, a.begin() + right);

	number_of_inversions += get_number_of_inversions(B, C, left, half);
	number_of_inversions += get_number_of_inversions(B, C, half + 1, right);

	//write your code here
	number_of_inversions += count_inversions(B, C);

	return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  //std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
  std::cout << get_number_of_inversions2(a) << '\n';
}
